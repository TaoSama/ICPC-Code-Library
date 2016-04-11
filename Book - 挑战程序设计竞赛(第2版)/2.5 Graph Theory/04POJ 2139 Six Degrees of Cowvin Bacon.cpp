//
//  POJ 2139 Six Degrees of Cowvin Bacon
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

int n, m, a[305], dp[305][305];

int main() {
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
//	freopen("out.txt","w",stdout);
#endif
	ios_base::sync_with_stdio(0);

	scanf("%d%d", &n, &m);
	memset(dp, 0x3f, sizeof dp);
	for(int i = 1; i <= m; ++i) {
		int t; scanf("%d", &t);
		for(int j = 1; j <= t; ++j) scanf("%d", a + j);
		for(int j = 1; j <= t; ++j)
			for(int k = j + 1; k <= t; ++k)
				dp[a[j]][a[k]] = dp[a[k]][a[j]] = 1;
	}

	for(int k = 1; k <= n; ++k)
		for(int i = 1; i <= n; ++i)
			for(int j = 1; j <= n; ++j)
				dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);

	int ans = INF;
	for(int i = 1; i <= n; ++i) {
		int t = 0;
		for(int j = 1; j <= n; ++j) {
			if(i == j) continue;
			t += dp[i][j];
		}
		ans = min(ans, t);
	}
	printf("%d\n", ans * 100 / (n - 1));
	return 0;
}
