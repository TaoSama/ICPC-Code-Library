//
//
//
//  Created by TaoSama on 2015-03-29
//  Copyright (c) 2015 TaoSama. All rights reserved.
//
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
#define CLR(x,y) memset(x, y, sizeof(x))

using namespace std;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int N = 1e5 + 10;

int m, n, p[105], r[105], cost[105][105], dp[105], Min[105], Max[105];

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//	freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(cin >> m >> n) {
        memset(cost, 0x3f, sizeof cost);
        for(int i = 1; i <= n; ++i) {
            int t; cin >> p[i] >> r[i] >> t;
            for(int j = 1; j <= t; ++j) {
                int v, x; cin >> v >> x;
                cost[i][v] = min(cost[i][v], x);
            }
        }

        for(int i = 1; i <= n; ++i) {
            Min[i] = r[1] - m;
            Max[i] = r[1] + m;
        }

        memset(dp, 0x3f, sizeof dp);
        queue<int> q; q.push(1); dp[1] = 0;
        while(!q.empty()) {
            int u = q.front(); q.pop();
            for(int v = 1; v <= n; ++v) {
                if(r[v] >= Min[u] && r[v] <= Max[u] &&
                        dp[v] > dp[u] + cost[u][v]) {
                    dp[v] = dp[u] + cost[u][v];
                    Min[v] = max(Min[u], r[v] - m);
                    Max[v] = min(Max[u], r[v] + m);
                    q.push(v);
                }
            }
        }

        int ans = INF;
        for(int i = 1; i <= n; ++i) ans = min(ans, p[i] + dp[i]);
        cout << ans << endl;
    }
    return 0;
}
