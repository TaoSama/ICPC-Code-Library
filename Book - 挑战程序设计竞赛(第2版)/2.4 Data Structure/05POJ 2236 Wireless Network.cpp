//
//  POJ 2236 Wireless Network
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
const int N = 1e4 + 10;

int n, d, repaired[N], par[N], rank[N];
pair<int, int> pnt[N];
vector<int> edge[N];

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
	if(rank[x] < rank[y])	par[x] = y;
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
	//ios_base::sync_with_stdio(0);

	scanf("%d%d", &n, &d);	d *= d;
	init(n);
	for(int i = 1; i <= n; ++i)
		scanf("%d%d", &pnt[i].first, &pnt[i].second);
	for(int i = 1; i <= n; ++i) {
		for(int j = 1; j <= n; ++j) {
			if(i == j) continue;
			int dis = (pnt[i].first - pnt[j].first) *
			          (pnt[i].first - pnt[j].first) +
			          (pnt[i].second - pnt[j].second) *
			          (pnt[i].second - pnt[j].second);
			if(dis <= d) edge[i].push_back(j);
		}
	}
	char op[2]; int x, y;
	while(scanf("%s", op) != EOF) {
		if(op[0] == 'O') {
			scanf("%d", &x);
			if(!repaired[x]) {
				repaired[x] = true;
				for(int i = 0; i < edge[x].size(); ++i) {
					if(repaired[edge[x][i]]) {
						unite(x, edge[x][i]);
					}

				}
				/*for(int i = 1; i <= n; ++i)
					cout << i << "->" << find(i) << endl;
				cout << endl; */
			}
		} else {
			scanf("%d%d", &x, &y);
			if(same(x, y)) printf("SUCCESS\n");
			else	printf("FAIL\n");
		}
	}
	return 0;
}
