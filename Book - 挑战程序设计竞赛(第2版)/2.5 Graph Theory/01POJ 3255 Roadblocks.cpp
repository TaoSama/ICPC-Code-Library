//
//  POJ 3255 Roadblocks
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

int n, r, dp[5005], dp2[5005];
struct Edge {
	int to, cost;
};
vector<Edge> G[N];
typedef pair<int, int> Sta; //距离, 节点标号

int dijkstra() {
	priority_queue<Sta, vector<Sta>, greater<Sta> > pq;
	memset(dp, 0x3f, sizeof dp); memset(dp2, 0x3f, sizeof dp2);
	dp[1] = 0; pq.push(Sta(0, 1));
	while(!pq.empty()) {
		Sta p = pq.top(); pq.pop();
		int u = p.second, d = p.first;
		if(d > dp2[u]) continue;
		for(int i = 0; i < G[u].size(); ++i) {
			Edge &e = G[u][i];
			int d2 = d + e.cost;
			if(dp[e.to] > d2) {
				swap(dp[e.to], d2);
				pq.push(Sta(dp[e.to], e.to));
			}
			if(dp2[e.to] > d2 && dp[e.to] < d2) {
				dp2[e.to] = d2;
				pq.push(Sta(dp2[e.to], e.to));
			}
		}
	}
	return dp2[n];
}

int main() {
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
//	freopen("out.txt","w",stdout);
#endif
	//ios_base::sync_with_stdio(0);

	cin >> n >> r;
	for(int i = 1; i <= r; ++i) {
		int x, y, v; cin >> x >> y >> v;
		G[x].push_back((Edge) {y, v});
		G[y].push_back((Edge) {x, v});
	}
	cout << dijkstra() << endl;
	return 0;
}
