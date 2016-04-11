//
//  Created by TaoSama on 2016-03-25
//  Copyright (c) 2016 TaoSama. All rights reserved.
//
#pragma comment(linker, "/STACK:102400000,102400000")
#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
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
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

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
        ++scc;
        while(true) {
            int v = stk[top--];
            in[v] = false;
            id[v] = scc;
            if(v == u) break;
        }
    }
}

int n, m;

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int t; scanf("%d", &t);
    while(t--) {
        scanf("%d%d", &n, &m);
        for(int i = 1; i <= n; ++i) G[i].clear();
        for(int i = 1; i <= m; ++i) {
            int u, v; scanf("%d%d", &u, &v);
            G[u].push_back(v);
        }

        scc = dfsNum = 0;
        memset(dfn, 0, sizeof dfn);
        for(int i = 1; i <= n; ++i) if(!dfn[i]) tarjan(i);

        static int kase = 0;
        if(scc == 1) {printf("Case %d: -1\n", ++kase); continue;}

        vector<bool> in(N, 0), out(N, 0);
        for(int i = 1; i <= n; ++i) {
            int u = id[i];
            for(int j : G[i]) {
                int v = id[j];
                if(u == v) continue;
                out[u] = in[v] = true;
            }
        }
        vector<int> cnt(N, 0);
        for(int i = 1; i <= n; ++i) ++cnt[id[i]];

        int x = INF;
        for(int i = 1; i <= scc; ++i)
            if(!in[i] || !out[i]) x = min(x, cnt[i]);
        int y = n - x;

        long long ans = 1LL * n * n - n - 1LL * x * y - m;
        printf("Case %d: %I64d\n", ++kase, ans);
    }
    return 0;
}
