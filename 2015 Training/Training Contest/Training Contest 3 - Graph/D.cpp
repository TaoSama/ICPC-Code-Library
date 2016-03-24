//
//  POJ 1258  Agri-Net
//
//  Created by TaoSama on 2015-03-21
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

int n, dp[205];
bool used[205];

struct Point {
	int x, y;
} a[205];

struct Edge {
	int to, cost;
};
vector<Edge> G[40005];
typedef pair<int, int> Sta;

int prim() {
	int ret = -INF;
	memset(dp, 0x3f, sizeof dp);
	memset(used, false, sizeof used);
	priority_queue<Sta, vector<Sta>, greater<Sta> > pq;
	pq.push(Sta(0, 1)); dp[1] = 0;
	while(!pq.empty()) {
		Sta p = pq.top(); pq.pop();
		int u = p.second;
		if(used[u] || p.first > dp[u]) continue;
		used[u] = true; ret = max(ret, dp[u]);
		if(u == 2) break;
		for(int i = 0; i < G[u].size(); ++i) {
			Edge &e = G[u][i];
			if(dp[e.to] > e.cost) {
				dp[e.to] = e.cost;
				pq.push(Sta(dp[e.to], e.to));
			}
		}
	}
	return ret;
}

int main() {
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
//	freopen("out.txt","w",stdout);
#endif
	ios_base::sync_with_stdio(0);

	int kase = 0;
	while(scanf("%d", &n) == 1 && n) {
		for(int i = 1; i <= n; ++i) {
			G[i].clear();
			scanf("%d%d", &a[i].x, &a[i].y);
		}
		for(int i = 1; i <= n; ++i) {
			for(int j = 1; j <= n ; ++j) {
				int d = (a[i].x - a[j].x) * (a[i].x - a[j].x)
				        + (a[i].y - a[j].y) * (a[i].y - a[j].y);
				G[i].push_back((Edge) {j, d});
				G[j].push_back((Edge) {i, d});
			}
		}

		double ans = sqrt(prim());
		printf("Scenario #%d\nFrog Distance = %.3f\n\n", ++kase, ans);
	}
	return 0;
}
