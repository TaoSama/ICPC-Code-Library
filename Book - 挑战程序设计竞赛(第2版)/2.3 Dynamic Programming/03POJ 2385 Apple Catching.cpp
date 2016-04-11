//
//  POJ 2385 Apple Catching
//
//  Created by TaoSama on 2015-03-04
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

int t, w, a[1005], dp[35][1005];

int main() {
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
//	freopen("out.txt","w",stdout);
#endif
	ios_base::sync_with_stdio(0);

	while(cin >> t >> w) {
		for(int i = 1; i <= t; ++i) cin >> a[i];
		memset(dp, 0, sizeof dp);
		for(int i = 0; i <= w; ++i) {
			for(int j = 0; j <= t; ++j) {
				dp[i][j + 1] = max(dp[i][j + 1], dp[i][j] + ((i + a[j + 1]) & 1));
				dp[i + 1][j + 1] = max(dp[i + 1][j + 1],
				                       dp[i][j] + ((i + 1 + a[j + 1]) & 1));
			}
		}
		int ans = -INF;
		for(int i = 0; i <= w; ++i)
			ans = max(ans, dp[i][t]);
		cout << ans << endl;
	}
	return 0;
}
