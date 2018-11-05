
//  Created by TaoSama.
//  Copyright (c) 2017 TaoSama. All rights reserved.
//
#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, m;
vector<int> G[N];
bool g[N][N];

void dfs(int s, int u) {
    if(g[s][u]) return;
    g[s][u] = 1;
    for(int v : G[u]) dfs(s, v);
}

int main(){
#ifdef LOCAL
    freopen("/Users/didi/ACM/in.txt", "r", stdin);
//  freopen("/Users/didi/ACM/out.txt", "w", stdout);
#endif
    ios::sync_with_stdio(0); cin.tie(0);
    
    int t; scanf("%d", &t);
    while(t--) {
        scanf("%d%d", &n, &m);
        memset(g, 0, sizeof g);
        for(int i = 1; i <= n; ++i) G[i].clear();
        for(int i = 1; i <= m; ++i) {
            int u, v; scanf("%d%d", &u, &v);
            G[u].push_back(v);
        }

        for(int i = 1; i <= n; ++i) dfs(i, i);

        bool ok = true;
        for(int i = 1; i <= n; ++i) {
            for(int j = i + 1; j <= n; ++j) {
                ok &= g[i][j] || g[j][i];
            }
        }
        puts(ok ? "I love you my love and our love save us!" : "Light my fire!");
    }
    return 0;
}
