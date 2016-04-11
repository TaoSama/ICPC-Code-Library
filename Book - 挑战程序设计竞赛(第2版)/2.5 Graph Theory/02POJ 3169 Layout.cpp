//
//  POJ 3169 Layout
//
//  Created by TaoSama on 2015-03-20
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

int n, l, d, dp[1005];
struct Edge {
	int to, cost;
};
vector<Edge> G[21005];

int BellmanFord() {
	memset(dp, 0x3f, sizeof dp); dp[1] = 0;
	for(int k = 1; k <= n; ++k) {
		for(int i = 1; i <= n; ++i) {
			for(int j = 0; j < G[i].size(); ++j) {
				Edge &e = G[i][j];
				dp[e.to] = min(dp[e.to], dp[i] + e.cost);
				//printf("dp[%d]: %d\n",e.to, dp[e.to]);
			}
		}
	}
	return dp[n];
}

int main() {
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
//	freopen("out.txt","w",stdout);
#endif
	ios_base::sync_with_stdio(0);

	scanf("%d%d%d", &n, &l, &d);
	int a, b, c;
	for(int i = 1; i < n; ++i)
		G[i + 1].push_back((Edge) {i, 0});
	for(int i = 1; i <= l; ++i) {
		scanf("%d%d%d", &a, &b, &c);
		G[a].push_back((Edge) {b, c});
	}
	for(int i = 1; i <= d; ++i) {
		scanf("%d%d%d", &a, &b, &c);
		G[b].push_back((Edge) {a, -c});
	}
	int ans = BellmanFord();
	if(dp[1] < 0) ans = -1;
	else if(ans == INF)  ans = -2;
	printf("%d\n", ans);
	return 0;
}
