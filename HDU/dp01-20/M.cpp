//
//  HDU 1176 Ãâ·ÑÏÚ±ý
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

int dp[N][15], n;

int main() {
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
//	freopen("out.txt","w",stdout);
#endif
	ios_base::sync_with_stdio(0);

	while(cin >> n && n) {
		CLR(dp, 0); int t = 0;
		while(n--) {
			int x, T; cin >> x >> T;
			++dp[T][x]; t = max(t, T);
		}

		for(int i = t - 1; i >= 0; --i) {
			dp[i][0] += max(dp[i + 1][1], dp[i + 1][0]);
			for(int j = 1; j <= 10; ++j) {
				dp[i][j] += max(dp[i + 1][j], max(dp[i + 1][j - 1],
				                                  dp[i + 1][j + 1]));
			}
		}
		cout << dp[0][5] << endl;
	}
	return 0;
}
