//
//  POJ 2395 Out of Hay
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

int n, m, par[2005], rank[2005];

struct Edge {
	int u, v, cost;
	bool operator < (const Edge& rhs) const {
		return cost < rhs.cost;
	}
};

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

int kruskal() {
	int ret = -INF;
	sort(G.begin(), G.end());
	init(n);
	for(int i = 0; i < G.size(); ++i) {
		Edge &e = G[i];
		if(!same(e.u, e.v)) {
			ret = max(ret, e.cost);
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

	cin >> n >> m;
	for(int i = 1; i <= m; ++i) {
		int x, y, v; cin >> x >> y >> v;
		G.push_back((Edge) {x, y, v});
	}
	cout << kruskal() << endl;
	return 0;
}
