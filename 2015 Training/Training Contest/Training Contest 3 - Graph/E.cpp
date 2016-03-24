//
//
//
//  Created by TaoSama on 2015-03-22
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

int n, dp[105][105];

int main() {
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
//	freopen("out.txt","w",stdout);
#endif
	ios_base::sync_with_stdio(0);

	while(scanf("%d", &n) == 1 && n) {
		for(int i = 1; i <= n; ++i)
			for(int j = 1; j <= n; ++j)
				dp[i][j] = i == j ? 0 : INF;
		for(int i = 1; i <= n; ++i) {
			int m; scanf("%d", &m);
			for(int j = 1; j <= m; ++j) {
				int s, t; scanf("%d%d", &s, &t);
				dp[i][s] = t;
			}
		}

		for(int k = 1; k <= n; ++k)
			for(int i = 1; i <= n; ++i)
				for(int j = 1; j <= n; ++j)
					dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);

		int id, ans = INF;

		for(int i = 1; i <= n; ++i) {
			int t = -INF;
			for(int j = 1; j <= n; ++j)
				t = max(t, dp[i][j]);
			if(ans > t) {
				ans = t;
				id = i;
			}
		}
		if(ans == INF) printf("disjoint\n");
		else printf("%d %d\n", id, ans);
	}
	return 0;
}
