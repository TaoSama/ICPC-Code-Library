//
//  Created by TaoSama on 2015-07-27
//  Copyright (c) 2015 TaoSama. All rights reserved.
//
//#pragma comment(linker, "/STACK:1024000000,1024000000")
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

int n, last, pre[3005], dp[3005];
bool vis[3005];
vector<int> G[3005];

bool dfs(int u, int f) {
    vis[u] = true;
    for(auto &v : G[u]) {
        if(v == f) continue;
        pre[v] = u;
        if(vis[v]) {
            last = u;
            return false;
        }
        if(!dfs(v, u)) return false;
    }
    return true;
}

void bfs() {
    queue<int> q; q.push(0);
    memset(vis, false, sizeof vis);
    memset(dp, 0, sizeof dp);
    vis[0] = true;
    while(q.size()) {
        int u = q.front(); q.pop();
        for(auto &v : G[u]) {
            if(!vis[v]) {
                vis[v] = true;
                dp[v] = dp[u] + 1;
//              pr(v); prln(dp[v]);
                q.push(v);
            }
        }
    }
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d", &n) == 1) {
        for(int i = 0; i <= n; ++i) G[i].clear();
        for(int i = 1; i <= n; ++i) {
            int u, v; scanf("%d%d", &u, &v);
            G[u].push_back(v);
            G[v].push_back(u);
        }

        memset(vis, false, sizeof vis);
        dfs(1, -1);  //find the cycle
        int cur = last; //add an 1 edge with pivot 0
        while(true) {
            G[0].push_back(cur);
            G[cur].push_back(0);
            cur = pre[cur];
            if(cur == last) break;
        }

        bfs();
        for(int i = 1; i <= n; ++i)
            cout << dp[i] - 1 << (i == n ? '\n' : ' ');
    }
    return 0;
}
