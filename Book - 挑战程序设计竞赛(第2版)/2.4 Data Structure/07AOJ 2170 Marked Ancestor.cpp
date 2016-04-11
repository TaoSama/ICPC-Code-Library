//
//  AOJ 2170 Marked Ancestor
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

int n, q, par[N];

int find(int x) {
	if(par[x] == x) return x;
	return find(par[x]);
}

int main() {
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
//	freopen("out.txt","w",stdout);
#endif
	ios_base::sync_with_stdio(0);

	while(~scanf("%d%d", &n, &q) && n && q) {
		par[1] = 1;
		for(int i = 2; i <= n; ++i) scanf("%d", &par[i]);

		long long ans = 0;
		for(int i = 1; i <= q; ++i) {
			char op[2]; int x;
			scanf("%s%d", op, &x);
			if(op[0] == 'Q') ans += find(x);
			else par[x] = x;
		}
		printf("%lld\n", ans);
	}
	return 0;
}
