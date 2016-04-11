//
//  AOJ 2249 Road Construction
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
#include <numeric>
#include <queue>
#include <string>
#include <set>
#include <vector>
#define CLR(x,y) memset(x, y, sizeof(x))

using namespace std;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int N = 1e5 + 10;

int n, m, ans[10005], dp[10005];
struct Edge {
	int to, dis, cost;
};
vector<Edge> G[20005];
struct Sta {
	int u, dis;
	bool operator<(const Sta& rhs) const {
		return dis > rhs.dis;
	}
};

int dijkstra() {
	int ret = 0;
	priority_queue<Sta> pq;
	memset(dp, 0x3f, sizeof dp);
	memset(ans, 0x3f, sizeof ans);
	pq.push((Sta) {1, 0}); dp[1] = 0;
	while(!pq.empty()) {
		Sta p = pq.top(); pq.pop();
		int u = p.u, d = p.dis;
		if(d > dp[u]) continue;
		for(int i = 0; i < G[u].size(); ++i) {
			Edge &e = G[u][i];
			if(dp[e.to] > dp[u] + e.dis) {
				ans[e.to] = e.cost;
				dp[e.to] = dp[u] + e.dis;
				pq.push((Sta) {e.to, dp[e.to]});
			} else if(dp[e.to] == dp[u] + e.dis && ans[e.to] > e.cost)
				ans[e.to] = e.cost;
		}
	}
	return accumulate(ans + 2, ans + n + 1, ret);
}

int main() {
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
//	freopen("out.txt","w",stdout);
#endif
	ios_base::sync_with_stdio(0);

	while(scanf("%d%d", &n, &m) == 2 && (n + m)) {
		for(int i = 1; i <= n; ++i) G[i].clear();
		for(int i = 1; i <= m; ++i) {
			int x, y, d, v; scanf("%d%d%d%d", &x, &y, &d, &v);
			G[x].push_back((Edge) {y, d, v});
			G[y].push_back((Edge) {x, d, v});
		}
		int ans = dijkstra();
		/*int ans = 0;
		for(int i = 2; i <= n; ++i) {
			int t = INF;
			for(int j = 0; j < G[i].size(); ++j) {
				Edge &e = G[i][j];
				if(dp[e.to] + e.dis == dp[i] && e.cost < t)
					t = e.cost;
			}
			ans += t;
		}*/
		printf("%d\n", ans);
	}
	return 0;
}
