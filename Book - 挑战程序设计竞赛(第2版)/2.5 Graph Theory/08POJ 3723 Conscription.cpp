//
//  POJ 3723  Conscription
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

int n, m, r;
struct Edge {
	int u, v, cost;
	bool operator<(const Edge& rhs) const {
		return cost < rhs.cost;
	}
} G[50005];

int par[20005], rank[20005];

void init(int n) {
	for(int i = 0; i < n; ++i) {
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
	if(rank[x] < rank[y]) par[x] = y;
	else {
		par[y] = x;
		if(rank[x] == rank[y]) ++rank[x];
	}
}

bool same(int x, int y) {
	return find(x) == find(y);
}

int kruskal() {
	int ret = 0;
	sort(G + 1, G + 1 + r);
	init(n + m);
	for(int i = 1; i <= r; ++i) {
		Edge &e = G[i];
		if(!same(e.u, e.v)) {
			ret += e.cost;
			unite(e.u, e.v);
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

	int t; scanf("%d", &t);
	while(t--) {
		scanf("%d%d%d", &n, &m, &r);
		for(int i = 1; i <= r; ++i) {
			int x, y, v; scanf("%d%d%d", &x, &y, &v);
			G[i] = (Edge) {x, y + n, -v};
		}
		int ans = 10000 * (n + m) + kruskal();
		printf("%d\n", ans);
	}
	return 0;
}
