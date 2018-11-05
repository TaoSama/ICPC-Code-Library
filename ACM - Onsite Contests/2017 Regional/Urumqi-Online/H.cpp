
//  Created by TaoSama.
//  Copyright (c) 2017 TaoSama. All rights reserved.
//
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, m;
vector<pair<int, int>> G[N];

int main(){
#ifdef LOCAL
    freopen("/Users/didi/ACM/in.txt", "r", stdin);
//  freopen("/Users/didi/ACM/out.txt", "w", stdout);
#endif
    ios::sync_with_stdio(0); cin.tie(0);
    
    int t; scanf("%d", &t);
    while(t--) {
        scanf("%d%d", &n, &m);
        for(int i = 1; i <= n; ++i) G[i].clear();
        vector<int> deg(n + 1, 0);
        for(int i = 1; i <= m; ++i) {
            int u, v, c; scanf("%d%d%d", &u, &v, &c);
            G[u].push_back({v, c});
            ++deg[v];
        }
        vector<int> topo;
        for(int i = 1; i <= n; ++i) if(!deg[i]) topo.push_back(i);
        for(size_t i = 0; i < topo.size(); ++i) {
            int u = topo[i];
            for(const auto& e : G[u]) {
                int v = e.first;
                if(!--deg[v]) topo.push_back(v);
            }
        }
        vector<int> f(n + 1, 0);
        int ans = 0;
        for(size_t i = 0; i < topo.size(); ++i) {
            int u = topo[i];
            ans = max(ans, f[u]);
            for(const auto& e : G[u]) {
                int v, c; tie(v, c) = e;
                f[v] = max(f[v], f[u] + c);
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
