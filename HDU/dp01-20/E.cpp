//
//  HDU 1506 Largest Rectangle in a Histogram
//
//  Created by TaoSama on 2015-02-07
//  Copyright (c) 2014 TaoSama. All rights reserved.
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

int n, l[N], r[N], h[N];

int main() {
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
//	freopen("out.txt","w",stdout);
#endif
	ios_base::sync_with_stdio(0);
	while(scanf("%d", &n) == 1 && n) {
		for(int i = 1; i <= n; ++i) {
			scanf("%d", h + i);
			l[i] = r[i] = i;
		}

		h[0] = h[n + 1] = -1;
		for(int i = 1; i <= n; ++i)
			while(h[l[i] - 1] >= h[i])
				l[i] = l[l[i] - 1];
		for(int i = n; i >= 1; --i)
			while(h[r[i] + 1] >= h[i])
				r[i] = r[r[i] + 1];

		long long ans = -INF;
		for(int i = 1; i <= n; ++i)
			ans = max(ans, (r[i] - l[i] + 1LL) * h[i]);

		printf("%I64d\n", ans);
	}
	return 0;
}
