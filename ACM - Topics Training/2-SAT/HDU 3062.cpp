//
//  Created by TaoSama on 2016-05-28
//  Copyright (c) 2016 TaoSama. All rights reserved.
//
#pragma comment(linker, "/STACK:102400000,102400000")
#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <set>
#include <vector>

using namespace std;
#define pr(x) cout << #x << " = " << x << "  "
#define prln(x) cout << #x << " = " << x << endl
const int N = 2e3 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, m;
vector<int> G[N];

int dfn[N], low[N], in[N], id[N], scc, dfsNum;
int stk[N], top;

void tarjan(int u) {
    dfn[u] = low[u] = ++dfsNum;
    stk[++top] = u;
    in[u] = true;
    for(int i = 0; i < G[u].size(); ++i) {
        int v = G[u][i];
        if(!dfn[v]) {
            tarjan(v);
            low[u] = min(low[u], low[v]);
        } else if(in[v]) low[u] = min(low[u], dfn[v]);
    }
    if(low[u] == dfn[u]) {
        ++scc;
        while(true) {
            int v = stk[top--];
            in[v] = false;
            id[v] = scc;
            if(v == u) break;
        }
    }
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);
    clock_t _ = clock();

    while(scanf("%d%d", &n, &m) == 2) {
        scc = dfsNum = 0;
        memset(dfn, 0, sizeof dfn);
        for(int i = 0; i < 2 * n; ++i) G[i].clear();
        for(int i = 1; i <= m; ++i) {
            int a1, a2, c1, c2;
            scanf("%d%d%d%d", &a1, &a2, &c1, &c2);
            int u = a1 << 1 | c1, v = a2 << 1 | c2;
            G[u].push_back(v ^ 1);
            G[v].push_back(u ^ 1);
        }
        for(int i = 0; i < 2 * n; ++i) if(!dfn[i]) tarjan(i);

        bool ok = true;
        for(int i = 0; i < 2 * n; i += 2)
            if(id[i] == id[i ^ 1]) {ok = false; break;}
        puts(ok ? "YES" : "NO");
    }

#ifdef LOCAL
    printf("\nTime cost: %.2fs\n", 1.0 * (clock() - _) / CLOCKS_PER_SEC);
#endif
    return 0;
}
