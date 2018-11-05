
//  Created by TaoSama.
//  Copyright (c) 2017 TaoSama. All rights reserved.
//
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n;
vector<int> G[N];
int sz[N], dep[N];

void dfs(int u, int fa) {
    sz[u] = 1;
    dep[u] = dep[fa] + 1;
    for(int v : G[u]) {
        if(v == fa) continue;
        dfs(v, u);
        sz[u] += sz[v];
    }
}

double ans, sum;
void dfs2(int u, int fa) {
    for(int v : G[u]) {
        if(v == fa) continue;
        sum += dep[v];
        ans += 1.0 * dep[v] * (sz[1] - sz[v]);
        dfs2(v, u);
    }
}

int main(){
#ifdef LOCAL
    freopen("/Users/didi/ACM/in.txt", "r", stdin);
//  freopen("/Users/didi/ACM/out.txt", "w", stdout);
#endif
    ios::sync_with_stdio(0); cin.tie(0);
    
    
    cin >> n;
    for(int i = 1; i < n; ++i) {
        int x, y; cin >> x >> y;
        G[x].push_back(y);
        G[y].push_back(x);
    }
    dep[0] = -1;
    dfs(1, 0);
    dfs2(1, 0);
    cout << fixed << setprecision(20) << ans / sum << endl;
    return 0;
}
