//
//  Created by TaoSama on 2015-08-22
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

int n, m, k;
struct Edge {
    int to, c;
};
vector<Edge> G[1005];

int dp[15][1005]; //use i superpower s->j's min distance
bool in[15][1005];
typedef pair<int, int> P;
int spfa() {
    queue<P> q; q.push(P(0, 1));
    memset(in, false, sizeof in);
    memset(dp, 0x3f, sizeof dp);
    dp[0][1] = 0; in[0][1] = true;
    while(q.size()) {
        int k = q.front().first, u = q.front().second; q.pop();
        in[k][u] = false;
        for(int i = 0; i < G[u].size(); ++i) {
            Edge &e = G[u][i];
            if(dp[k][e.to] > dp[k][u] + e.c) {
                dp[k][e.to] = dp[k][u] + e.c;
                if(!in[k][e.to]) q.push(P(k, e.to)), in[k][e.to] = true;
            }
            if(dp[k + 1][e.to] > dp[k][u]) {
                dp[k + 1][e.to] = dp[k][u];
                if(!in[k + 1][e.to]) q.push(P(k + 1, e.to)), in[k + 1][e.to] = true;
            }
        }
    }
    return dp[k][n];
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d%d%d", &n, &m, &k) == 3) {
        for(int i = 1; i <= n; ++i) G[i].clear();
        for(int i = 1; i <= m; ++i) {
            int u, v, c; scanf("%d%d%d", &u, &v, &c);
            G[u].push_back((Edge) {v, c});
            G[v].push_back((Edge) {u, c});
        }
        printf("%d\n", spfa());
    }
    return 0;
}
