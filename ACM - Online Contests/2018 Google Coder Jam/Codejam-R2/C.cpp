
//  Created by TaoSama.
//  Copyright (c) 2017 TaoSama. All rights reserved.
//
#include <bits/stdc++.h>
using namespace std;
const int N = 1e2 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, m;
int conflict[N][N];
struct Edge {
    int v, nxt;
} edge[N * N];
int head[N], cnt;
void addEdge(int u, int v) {
    edge[cnt] = {v, head[u]};
    head[u] = cnt++;
}
int match[N], vis[N];
bool dfs(int u) {
    for(int i = head[u]; ~i; i = edge[i].nxt) {
        int v = edge[i].v;
        if(vis[v]) continue;
        vis[v] = true;
        if(match[v] == -1 || dfs(match[v])) {
            match[v] = u;
            return true;
        }
    }
    return false;
}
int hungary() {
    int matches = 0;
    memset(match, -1, sizeof match);
    for(int i = 1; i <= n; ++i) {
        memset(vis, 0, sizeof vis);
        matches += dfs(i);
    }
    return matches;
}

vector<pair<int, int>> v[N * 2];

int main(){
#ifdef LOCAL
    freopen("/Users/didi/ACM/in.txt", "r", stdin);
//  freopen("/Users/didi/ACM/out.txt", "w", stdout);
#endif
    ios::sync_with_stdio(0); cin.tie(0);
    
    int t; cin >> t;
    while(t--) {
        cin >> n;
        for(int i = 0; i <= 2 * n; ++i) v[i].clear();
        for(int i = 1; i <= n; ++i) {
            for(int j = 1; j <= n; ++j) {
                int x; cin >> x;
                v[n + x].push_back({i, j});
            }
        }
        int ans = 0;
        for(int i = 0; i <= 2 * n; ++i) {
            cnt = 0; memset(head, -1, sizeof head);     
            for(const auto& p : v[i]) {
                int x, y; tie(x, y) = p;    
                addEdge(x, y);
            }
            ans += v[i].size() - hungary();
        }
        static int kase = 0;
        cout << "Case #" << ++kase << ": " << ans << '\n';
    }
    return 0;
}
