//
//  Created by TaoSama on 2015-08-16
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

int n, m, S, T;
struct Edge {
    int to, a, b, t;
};
vector<Edge> G[305];

long long dp[305];
bool done[305];
typedef pair<long long, int> Sta;
long long dijkstra() {
    memset(dp, 0x3f, sizeof dp);
    memset(done, false, sizeof done);
    priority_queue<Sta, vector<Sta>, greater<Sta> > q;
    dp[S] = 0; q.push(Sta(0, S));
    while(q.size()) {
        int u = q.top().second; q.pop();
        done[u] = true;
        for(int i = 0; i < G[u].size(); ++i) {
            Edge &e = G[u][i];
            if(e.a < e.t) continue;  //dead way
            int left = dp[u] % (e.a + e.b), cost;
            if(left < e.a && e.a - left >= e.t) cost = e.t; //go directly
            else cost = e.a + e.b - left + e.t; //wait for next open
            if(!done[e.to] && dp[e.to] > dp[u] + cost) {
                dp[e.to] = dp[u] + cost;
                q.push(Sta(dp[e.to], e.to));
            }
        }
    }
    return dp[T];
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int kase = 0;
    while(scanf("%d%d%d%d", &n, &m, &S, &T) == 4) {
        for(int i = 1; i <= n; ++i) G[i].clear();
        for(int i = 1; i <= m; ++i) {
            int u, v, a, b, t;
            scanf("%d%d%d%d%d", &u, &v, &a, &b, &t);
            G[u].push_back((Edge) {v, a, b, t});
        }
        printf("Case %d: %lld\n", ++kase, dijkstra());
    }
    return 0;
}
