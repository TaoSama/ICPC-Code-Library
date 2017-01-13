//
//  Created by TaoSama on 2016-10-29
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
const int N = 1e3 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;
typedef long long LL;

int n;
int x[N], y[N], r[N], c[N], newC[N];

vector<int> G[N];
int dfn[N], low[N], in[N], id[N], scc, dfsNum;
int stk[N], top;
void tarjan(int u) {
    dfn[u] = low[u] = ++dfsNum;
    stk[++top] = u;
    in[u] = true;
    for(int v : G[u]) {
        if(!dfn[v]) {
            tarjan(v);
            low[u] = min(low[u], low[v]);
        } else if(in[v]) low[u] = min(low[u], dfn[v]);
    }
    if(low[u] == dfn[u]) {
        newC[++scc] = INF;
        while(true) {
            int v = stk[top--];
            in[v] = false;
            id[v] = scc;
            newC[scc] = min(newC[scc], c[v]);
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

    int t; scanf("%d", &t);
    while(t--) {
        scanf("%d", &n);
        for(int i = 1; i <= n; ++i) G[i].clear();
        for(int i = 1; i <= n; ++i)
            scanf("%d%d%d%d", x + i, y + i, r + i, c + i);
        for(int i = 1; i <= n; ++i) {
            for(int j = 1; j <= n; ++j) {
                if(i == j) continue;
                LL dis = 1LL * (x[i] - x[j]) * (x[i] - x[j]) +
                         1LL * (y[i] - y[j]) * (y[i] - y[j]);
                if(dis <= 1LL * r[i] * r[i]) G[i].push_back(j);
            }
        }

        scc = dfsNum = 0;
        memset(dfn, 0, sizeof dfn);
        for(int i = 1; i <= n; ++i) if(!dfn[i]) tarjan(i);

        vector<int> indeg(scc + 1, 0);
        for(int i = 1; i <= n; ++i) {
            int u = id[i];
            for(int j : G[i]) {
                int v = id[j];
                if(u == v) continue;
                ++indeg[v];
            }
        }

        int ans = 0;
        for(int i = 1; i <= scc; ++i) if(!indeg[i]) ans += newC[i];
        static int kase = 0;
        printf("Case #%d: %d\n", ++kase, ans);
    }

    return 0;
}
