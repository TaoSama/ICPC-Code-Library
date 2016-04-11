//
//  POJ 3046 Ant Counting
//
//  Created by TaoSama on 2015-03-05
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
const int MOD = 1e6;
const int N = 1e5 + 10;

int n, m, l, r, dp[2][N], w[1005];

int main() {
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
//	freopen("out.txt","w",stdout);
#endif
	ios_base::sync_with_stdio(0);

	while(cin >> n >> m >> l >> r) {
		memset(w, 0, sizeof w);
		for(int i = 1; i <= m; ++i) {
			int x; cin >> x;
			++w[x];
		}
		memset(dp, 0, sizeof dp);
		dp[0][0] = 1;
		for(int i = 1; i <= n; ++i) {
			memset(dp[i & 1], 0, sizeof dp[i & 1]);
			for(int k = 0; k <= w[i]; ++k) {
				for(int j = k; j <= m; ++j) {
					dp[i & 1][j] = (dp[i & 1][j] + dp[(i - 1) & 1][j - k]) % MOD;
				}
			}
		}
		int ans = 0;
//		for(int i = 1; i <= m; ++i)
//			cout << dp[n & 1][i] << endl;
		for(int i = l; i <= r; ++i)
			ans = (ans + dp[n & 1][i]) % MOD;
		cout << ans << endl;
	}
	return 0;
}
