//
//  HDU 2571 รüิห
//
//  Created by TaoSama on 2015-02-11
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

int n, m, dp[25][1005], v[25][1005];

int main() {
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
//	freopen("out.txt","w",stdout);
#endif
	ios_base::sync_with_stdio(0);

	int t; cin >> t;
	while(t--) {
		cin >> n >> m;
		for(int i = 1; i <= n; ++i)
			for(int j = 1; j <= m; ++j)
				cin >> v[i][j];

		memset(dp, 0xc0, sizeof dp);
		dp[1][0] = dp[0][1] = 0;
		for(int i = 1; i <= n; ++i) {
			for(int j = 1; j <= m; ++j) {
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
				for(int k = 1; k < j; ++k) {
					if(j % k == 0)
						dp[i][j] = max(dp[i][j], dp[i][k]);
				}
				dp[i][j] += v[i][j];
				//printf("dp[%d][%d]: %d\n", i, j, dp[i][j]);
			}
		}
		cout << dp[n][m] << endl;
	}
	return 0;
}
