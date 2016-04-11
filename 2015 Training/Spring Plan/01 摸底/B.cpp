//
//  ACdream 1681 娜娜梦游仙境系列——跳远女王
//
//  Created by TaoSama on 2015-04-11
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

using namespace std;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int N = 1e5 + 10;

struct Point {
    int x, y;
} a[1005];

int calc(int i, int j) {
    return (a[i].x - a[j].x) * (a[i].x - a[j].x) +
           (a[i].y - a[j].y) * (a[i].y - a[j].y);
}

vector<int> G[1005];
int g, n, d;
int dp[1005];
bool in[1005];

int spfa() {
    memset(in, false, sizeof in);
    memset(dp, 0x3f, sizeof dp);
    queue<int> q; q.push(0);
    in[0] = true; dp[0] = 0;
    while(!q.empty()) {
        int u = q.front(); q.pop();
        in[u] = false;
        for(int i = 0; i < G[u].size(); ++i) {
            int &v = G[u][i];
            if(dp[v] > dp[u] + 1) {
                dp[v] = dp[u] + 1;
                if(!in[v]) {
                    q.push(v);
                    in[v] = true;
                }
            }
        }
    }
    return dp[n + 1];
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//	freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int t; cin >> t;
    while(t--) {
        cin >> g >> n >> d;
        int dd = d * d;

        int Miny = INF, Maxy = 0;
        G[0].clear();
        for(int i = 1; i <= n; ++i) {
            G[i].clear();
            cin >> a[i].x >> a[i].y;
        }

        for(int i = 0; i <= n; ++i){
            if(a[i].y <= d) G[0].push_back(i);
            if(g - a[i].y <= d) G[i].push_back(n + 1);
        }

        for(int i = 1; i <= n; ++i) {
            for(int j = 1; j <= n; ++j) {
                if(i == j) continue;
                if(calc(i, j) <= dd)
                    G[i].push_back(j);
            }
        }
        int ans = spfa();
        if(ans == INF) {
            for(int i = n; i >= 0; --i) {
                if(dp[i] != INF)
                    ans = min(ans, g - a[i].y);
            }
            cout << "NO\n" << ans << "\n";
        } else cout << "YES\n" << ans << "\n";
    }
    return 0;
}
