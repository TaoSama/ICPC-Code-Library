//
//  POJ 3268 Silver Cow Party
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

int n, m, s, dp[1005], dp2[1005];
struct Edge {
	int to, cost;
};
vector<Edge> G[N], Gr[N];
typedef pair<int, int> Sta;

void dijkstra(vector<Edge> *G, int *dp) {
	priority_queue<Sta, vector<Sta>, greater<Sta> > pq;
	pq.push(Sta(0, s)); dp[s] = 0;
	while(!pq.empty()) {
		Sta p = pq.top(); pq.pop();
		int u = p.second, d = p.first;
		if(d > dp[u]) continue;
		for(int i = 0; i < G[u].size(); ++i) {
			Edge &e = G[u][i];
			if(dp[e.to] > d + e.cost) {
				dp[e.to] = d + e.cost;
				//printf("dp[%d]: %d\n", e.to, dp[e.to]);
				pq.push(Sta(dp[e.to], e.to));
			}
		}
	}
}

int main() {
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
//	freopen("out.txt","w",stdout);
#endif
	ios_base::sync_with_stdio(0);

	scanf("%d%d%d", &n, &m, &s);
	for(int i = 1; i <= m; ++i) {
		int x, y, v; scanf("%d%d%d", &x, &y, &v);
		G[x].push_back((Edge) {y, v});
		Gr[y].push_back((Edge) {x, v});
	}
	memset(dp, 0x3f,sizeof dp);
	memset(dp2, 0x3f,sizeof dp2);
	dijkstra(G, dp); dijkstra(Gr, dp2);
	int ans = -INF;
	for(int i = 1; i <= n; ++i)
		ans = max(ans, dp[i] + dp2[i]);
	printf("%d\n", ans);
	return 0;
}
