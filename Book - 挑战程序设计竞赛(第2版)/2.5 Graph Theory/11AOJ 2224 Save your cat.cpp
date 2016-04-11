//
//  AOJ 2224 Save your cat
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

int n, m, par[10005], rank[10005];

struct Edge {
	int u, v;
	double cost;
	bool operator < (const Edge& rhs) const {
		return cost < rhs.cost;
	}
};
struct Point {
	int x, y;
} a[10005];
vector<Edge> G;

void init(int n) {
	for(int i = 1; i <= n; ++i) {
		par[i] = i;
		rank[i] = 0;
	}
}

int find(int x) {
	if(par[x] == x) return x;
	return par[x] = find(par[x]);
}

void unite(int x, int y) {
	x = find(x); y = find(y);
	if(x == y) return;
	if(rank[x] < rank[y]) {
		par[x] = y;
	} else {
		par[y] = x;
		if(rank[x] == rank[y]) ++rank[x];
	}
}

bool same(int x, int y) {
	return find(x) == find(y);
}

double kruskal() {
	double ret = 0;
	sort(G.begin(), G.end());
	init(n);
	for(int i = 0; i < G.size(); ++i) {
		Edge &e = G[i];
		if(!same(e.u, e.v)) {
			ret += e.cost;
			unite(e.u, e.v);
		}
	}
	return ret;
}

/* 我就草了！！！ 再也不用prim了
double prim() {
	double ret = 0;
	priority_queue<Sta, vector<Sta>, greater<Sta> > pq;
	memset(used, false, sizeof used);
	minCost[1] = 0; pq.push(Sta(0, 1));
	while(!pq.empty()) {
		Sta p = pq.top(); pq.pop();
		int u = p.second;
		if(used[u] || p.first > minCost[u]) continue;
		used[u] = true; ret += minCost[u];
		for(int i = 0; i < G[u].size(); ++i) {
			Edge &e = G[u][i];
			if(minCost[e.to] > e.cost) {
				minCost[e.to] = e.cost;
				pq.push(Sta(minCost[e.to], e.to));
			}
		}
	}
	return ret;
} */

int main() {
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
//	freopen("out.txt","w",stdout);
#endif
	ios_base::sync_with_stdio(0);

	while(scanf("%d%d", &n, &m) == 2) {
		double sum = 0; G.clear();
		for(int i = 1; i <= n; ++i)
			scanf("%d%d", &a[i].x, &a[i].y);
		for(int i = 1; i <= m; ++i) {
			int x, y; scanf("%d%d", &x, &y);
			double cost = sqrt((a[x].x - a[y].x) * (a[x].x - a[y].x) +
			                   (a[x].y - a[y].y) * (a[x].y - a[y].y));
			sum += cost;
			G.push_back((Edge) {x, y, -cost});
		}
		double ans = sum + kruskal();
		printf("%.3f\n", ans);
	}
	return 0;
}
