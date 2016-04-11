//
//  POJ 1182 食物链
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
const int N = 50000;

int n, k, par[3 * N + 5], rank[3 * N + 5];

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

int main() {
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
//	freopen("out.txt","w",stdout);
#endif
	ios_base::sync_with_stdio(0);

	scanf("%d%d", &n, &k);
	init(3 * n);
	int ans = 0;
	for(int i = 1; i <= k; ++i) {
		int x, y, op; scanf("%d%d%d", &op, &x, &y);

		if(x < 1 || x > n || y < 1 || y > n) {
			++ans;
			continue;
		}

		if(op == 1) {
			if(same(x, y + n) || same(x, y + 2 * n)) ++ans;
			//A-B捕食 A-C反捕食
			else {
				unite(x, y);
				unite(x + n, y + n);
				unite(x + 2 * n, y + 2 * n);
			}
		} else {
			if(same(x, y) || same(x + n, y)) ++ans;
			//x,y同组 y吃x
			else {
				unite(x, y + n);
				unite(x + n, y + 2 * n);
				unite(x + 2 * n, y);
			}
		}
	}
	cout << ans << endl;
	return 0;
}
