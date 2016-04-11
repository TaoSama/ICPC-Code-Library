//
//  POJ 1703 Find them, Catch them
//
//  Created by TaoSama on 2015-03-16
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

int par[2 * N], rank[2 * N];
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
	if(rank[x] < rank[y]) par[x] = y;
	else {
		par[y] = x;
		if(rank[x] == rank[y]) ++rank[x];
	}
}

bool same(int x, int y) {
	return find(x) == find(y);
}

int main() {
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
//	freopen("out.txt","w",stdout);
#endif
	ios_base::sync_with_stdio(0);

	int t; scanf("%d", &t);
	while(t--) {
		int n, m; scanf("%d%d", &n, &m);
		init(2 * n);
		for(int i = 1; i <= m; ++i) {
			char op[2]; int x, y;
			scanf("%s%d%d", op, &x, &y);
			if(op[0] == 'A') {
				if(same(x, y))
					printf("In the same gang.\n");
				else if(same(x, y + n))
					printf("In different gangs.\n");
				else
					printf("Not sure yet.\n");
			} else {
				unite(x + n, y);
				unite(x, y + n);
			}
		}
	}
	return 0;
}
