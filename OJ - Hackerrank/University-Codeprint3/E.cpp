
//  Created by TaoSama.
//  Copyright (c) 2017 TaoSama. All rights reserved.
//
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int c[N];
vector<int> G[N];
int f[N][2], g[N][2];

void dfs(int u, int fa) {
    f[u][0] = -INF;
    f[u][1] = c[u];
    g[u][0] = INF;
    g[u][1] = c[u];

    for(int v : G[u]) {
        if(v == fa) continue;
        dfs(v, u);
        f[u][0] = max({f[u][0], f[v][0], f[v][1]});
        f[u][1] += max(f[v][1], 0);

        g[u][0] = min({g[u][0], g[v][0], g[v][1]});
        g[u][1] += min(g[v][1], 0);
    }
    // printf("f[%d][%d] = %d\n", u, 0, f[u][0]);
    // printf("f[%d][%d] = %d\n", u, 1, f[u][1]);
    // printf("g[%d][%d] = %d\n", u, 0, g[u][0]);
    // printf("g[%d][%d] = %d\n", u, 1, g[u][1]);
}

void dfs1(int u, int fa, int p, vector<int>& choose) {
    if(p == 0) {
        for(int v : G[u]) {
            if(v == fa) continue;
            if(f[v][0] == f[u][p]) {
                dfs1(v, u, 0, choose);
                break;
            }
            else if(f[v][1] == f[u][p]) {
                dfs1(v, u, 1, choose);
                break;
            }
        }
    }
    else {
        choose.emplace_back(u);
        for(int v : G[u]) {
            if(v == fa) continue;
            if(f[v][1] > 0) {
                dfs1(v, u, 1, choose);
            }
        }
    }
}

void dfs2(int u, int fa, int p, vector<int>& choose) {
    if(p == 0) {
        for(int v : G[u]) {
            if(v == fa) continue;
            if(g[v][0] == g[u][p]) {
                dfs2(v, u, 0, choose);
                break;
            }
            else if(g[v][1] == g[u][p]) {
                dfs2(v, u, 1, choose);
                break;
            }
        }
    }
    else {
        choose.emplace_back(u);
        for(int v : G[u]) {
            if(v == fa) continue;
            if(g[v][1] < 0) {
                dfs2(v, u, 1, choose);
            }
        }
    }
}

int main(){
#ifdef LOCAL
    freopen("/Users/didi/ACM/in.txt", "r", stdin);
//  freopen("/Users/didi/ACM/out.txt", "w", stdout);
#endif
    ios::sync_with_stdio(0); cin.tie(0);
    
    int n; cin >> n;
    for(int i = 1; i <= n; ++i) {
        cin >> c[i];
        if(c[i] == 0) c[i] = -1;
    }
    for(int i = 1; i < n; ++i) {
        int x, y; cin >> x >> y;
        G[x].emplace_back(y);
        G[y].emplace_back(x);
    }
    dfs(1, -1);
    vector<int> choose;
    int ans = max({f[1][0], f[1][1], -g[1][0], -g[1][1]}), p = -1;
    if(ans == f[1][0] || ans == f[1][1]) {
        p = ans == f[1][1];
        dfs1(1, -1, p, choose);
    }
    if(ans == -g[1][0] || ans == -g[1][1]) {
        p = ans == -g[1][1];
        dfs2(1, -1, p, choose); 
    }
    cout << ans << endl;
    sort(choose.begin(), choose.end());
    cout << choose.size() << endl;
    for(int x : choose) cout << x << ' '; cout << endl;
    return 0;
}
