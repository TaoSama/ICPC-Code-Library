
//  Created by TaoSama.
//  Copyright (c) 2017 TaoSama. All rights reserved.
//
#include <bits/stdc++.h>
using namespace std;
const int N = 4e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, m, q;
vector<int> g[N];
bool vis[N];

void dfs(int u) {
    vis[u] = true;
    for(int v : g[u]) {
        if(vis[v]) continue;
        dfs(v);
    }
}

int main(){
#ifdef LOCAL
    freopen("/Users/didi/ACM/in.txt", "r", stdin);
//  freopen("/Users/didi/ACM/out.txt", "w", stdout);
#endif
    ios::sync_with_stdio(0); cin.tie(0);
    
    while(cin >> n >> m >> q) {
        memset(vis, 0, sizeof vis);
        for(int i = 1; i <= n + m; ++i) g[i].clear();
        for(int i = 1; i <= q; ++i) {
            int x, y; cin >> x >> y;
            g[x].push_back(n + y);
            g[n + y].push_back(x);
        }
        int ans = 0;
        for(int i = 1; i <= n + m; ++i) {
           if(vis[i]) continue;
           dfs(i);
           ++ans;
        }
        cout << ans - 1 << endl;
    }
    return 0;
}
