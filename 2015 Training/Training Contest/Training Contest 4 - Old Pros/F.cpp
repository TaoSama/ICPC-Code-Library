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

using namespace std;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int N = 1e5 + 10;

int n, dp[105];
bool con[105][105];
struct Edge {
    int u, v, cost;
};
vector<Edge> G;

bool BellmanFord() {
    memset(dp, 0x3f, sizeof dp); dp[1] = -100;
    for(int i = 1; i <= n; ++i) {
        for(int j = 0; j < G.size(); ++j) {
            Edge &e = G[j];
            if(dp[e.v] > dp[e.u] + e.cost && dp[e.u] + e.cost < 0) {
                dp[e.v] = dp[e.u] + e.cost;
                if(i == n && con[1][e.v] && con[e.v][n])
                    return true;
            }
        }
    }
    return false;
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//	freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(cin >> n && n != -1) {
        G.clear();
        memset(con, false, sizeof con);
        for(int i = 1; i <= n; ++i) con[i][i] = true;
        for(int i = 1; i <= n; ++i) {
            int c, t, x; cin >> c >> t;
            while(t--) {
                cin >> x;
                G.push_back((Edge) {i, x, -c});
                con[i][x] = true;
            }
        }
        for(int k = 1; k <= n; ++k)
            for(int i = 1; i <= n; ++i)
                for(int j = 1; j <= n; ++j)
                    if(con[i][k] && con[k][j])
                        con[i][j] = true;

        if(BellmanFord() || dp[n] < 0) cout << "winnable" << endl;
        else cout << "hopeless" << endl;
    }
    return 0;
}
