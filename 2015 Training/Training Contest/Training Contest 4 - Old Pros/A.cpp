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

int n, m, w, dp[505];
struct Edge {
    int u, v, cost;
};
vector<Edge> G;

bool BellmanFord() {
    memset(dp, 0, sizeof dp);
    for(int i = 1; i <= n; ++i) {
        for(int j = 0; j < G.size(); ++j) {
            Edge &e = G[j];
            if(dp[e.v] > dp[e.u] + e.cost) {
                dp[e.v] = dp[e.u] + e.cost;
                if(i == n) return true;
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

    int t; scanf("%d", &t);
    while(t--) {
		G.clear();
        scanf("%d%d%d", &n, &m, &w);
        for(int i = 1; i <= m; ++i) {
            int x, y, v; scanf("%d%d%d", &x, &y, &v);
            G.push_back((Edge) {x, y, v});
            G.push_back((Edge) {y, x, v});
        }
        for(int i = 1; i <= w; ++i) {
            int x, y, v; scanf("%d%d%d", &x, &y, &v);
            G.push_back((Edge) {x, y, -v});
        }
        if(BellmanFord()) printf("YES\n");
        else 	printf("NO\n");
    }
    return 0;
}
