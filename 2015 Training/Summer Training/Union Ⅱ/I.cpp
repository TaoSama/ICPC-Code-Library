//
//  Created by TaoSama on 2015-08-25
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
const int N = 3e3 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, m;
struct Edge {
    int to, cost;
};
vector<Edge> G[N];
vector<int> P[N];

int in[N], maxt[N], dp[N], done[N];
typedef pair<int, int> Sta;
int dijkstra() {
    priority_queue<Sta, vector<Sta>, greater<Sta> > q;
    memset(dp, 0x3f, sizeof dp);
    memset(done, false, sizeof done);
    memset(maxt, 0, sizeof maxt);
    q.push(Sta(0, 1)); dp[1] = 0;
    while(q.size()) {
        int u = q.top().second; q.pop();
        if(done[u]) continue;
        done[u] = true;
        for(int i = 0; i < P[u].size(); ++i) {
            int v = P[u][i]; --in[v];
            maxt[v] = max(maxt[v], dp[u]);
            if(dp[v] != INF && in[v] == 0) {
                dp[v] = max(dp[v], maxt[v]);
                q.push(Sta(dp[v], v));
            }
        }
        for(int i = 0; i < G[u].size(); ++i) {
            Edge &e = G[u][i];
            if(dp[e.to] > dp[u] + e.cost) {
                dp[e.to] = dp[u] + e.cost;
                if(in[e.to] == 0) q.push(Sta(dp[e.to], e.to));
            }
        }
    }
    return dp[n];
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int t; scanf("%d", &t);
    while(t--) {
        scanf("%d%d", &n, &m);
        for(int i = 1; i <= n; ++i) {
            G[i].clear();
            P[i].clear();
        }
        for(int i = 1; i <= m; ++i) {
            int u, v, c; scanf("%d%d%d", &u, &v, &c);
            G[u].push_back((Edge) {v, c});
        }
        for(int i = 1; i <= n; ++i) {
            scanf("%d", in + i);
            for(int j = 1; j <= in[i]; ++j) {
                int u; scanf("%d", &u);
                P[u].push_back(i);
            }
        }
        printf("%d\n", dijkstra());
    }
    return 0;
}
