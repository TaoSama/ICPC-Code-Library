
//  Created by TaoSama.
//  Copyright (c) 2017 TaoSama. All rights reserved.
//
#include <bits/stdc++.h>
using namespace std;
const int N = 1e2 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, m;
vector<pair<int, int>> G[N];

int f[N][N][30][2];

int dfs(int i, int j, int c, int p) {
    int& ret = f[i][j][c][p];
    if(ret >= 0) return ret;
    int t = -1;
    ret = 0;
    int x = p == 0 ? i : j;
    for(const auto& e : G[x]) {
        int v, c2; tie(v, c2) = e;
        c2 -= 'a';
        if(c2 < c) continue;
        if(p == 0) {
            t = dfs(v, j, c2, p ^ 1);
        }
        else {
            t = dfs(i, v, c2, p ^ 1);
        }
        if(!t) ret = 1;
    } 
    return ret;
}

int main(){
#ifdef LOCAL
    freopen("/Users/didi/ACM/in.txt", "r", stdin);
//  freopen("/Users/didi/ACM/out.txt", "w", stdout);
#endif
    ios::sync_with_stdio(0); cin.tie(0);
    
    while(cin >> n >> m) {
        for(int i = 1; i <= n; ++i) G[i].clear();
        for(int i = 1; i <= m; ++i) {
            int u, v; char c;
            cin >> u >> v >> c;
            G[u].emplace_back(v, c);
        }
        memset(f, -1, sizeof f);
        for(int i = 1; i <= n; ++i) {
            for(int j = 1; j <= n; ++j) {
                for(int k = 0; k <= 1; ++k) {
                    dfs(i, j, 0, k);
                }
                cout << "BA"[f[i][j][0][0]];
            }
            cout << '\n';
        }
    }
    return 0;
}
