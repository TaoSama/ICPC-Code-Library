
//  Created by TaoSama.
//  Copyright (c) 2017 TaoSama. All rights reserved.
//
#include <bits/stdc++.h>
using namespace std;
const int N = 3e3 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, m, q;
vector<int> g[N], rg[N], t[N];
vector<pair<int, int>> qs[N][N];

void dfs(int u, vector<bool>& reach) {
    reach[u] = true;
    for(int v : rg[u]) if(!reach[v]) dfs(v, reach);
}

const int Q = 4e5 + 10;
int ans[Q];
vector<int> stk;
void solve(int y, int u) {
    // cout << y << ' ' << u << endl;
    stk.emplace_back(u);
    for(const auto& it : qs[y][u]) {
        ans[it.second] = it.first <= stk.size() ? stk[stk.size() - it.first] : -1;
    }
    for(int v : t[u]) solve(y, v);
    stk.pop_back();
}

int main(){
#ifdef LOCAL
    freopen("/Users/didi/ACM/in.txt", "r", stdin);
//  freopen("/Users/didi/ACM/out.txt", "w", stdout);
#endif
    ios::sync_with_stdio(0); cin.tie(0);
    
    scanf("%d%d%d", &n, &m, &q);
    for(int i = 1; i <= m; ++i) {
        int x, y; scanf("%d%d", &x, &y);
        g[x].emplace_back(y);
        rg[y].emplace_back(x);
    }
    for(int i = 1; i <= q; ++i) {
        int x, y, k; scanf("%d%d%d", &x, &y, &k);
        qs[y][x].emplace_back(k, i);
    }
    
    for(int y = 1; y <= n; ++y) {
        // printf("y = %d\n", y);
        vector<bool> reach(n + 1, false);
        dfs(y, reach);
        for(int i = 1; i <= n; ++i) t[i].clear();
        for(int i = 1; i <= n; ++i) {
            if(i == y) continue;
            int par = INF;
            for(int v : g[i]) {
                if(reach[v]) par = min(par, v);
            }
            if(par != INF) t[par].emplace_back(i);
        }
        solve(y, y);
    }
    transform(ans + 1, ans + 1 + q, ans + 1, [](int x){ return x ? x : -1; });
    for(int i = 1; i <= q; ++i) printf("%d\n", ans[i]);
    return 0;
}
