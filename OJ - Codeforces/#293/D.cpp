//
//
//
//  Created by TaoSama on 2015-02-25
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

double p, dp[2005][2005];
int n, t;

int main() {
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
//	freopen("out.txt","w",stdout);
#endif
	ios_base::sync_with_stdio(0);

	while(cin >> n >> p >> t) {
		memset(dp, 0, sizeof dp);
		dp[0][n] = 1;
		for(int i = 1; i <= t; ++i)
			for(int j = 0; j <= n; ++j)
				if(j != n)
					dp[i][j] = dp[i - 1][j + 1] * p + dp[i - 1][j] * (1 - p);
				else dp[i][j] = dp[i - 1][j] * (1 - p);

		double ans = 0;
		for(int i = 0; i <= n; ++i)
			ans += dp[t][i] * i;
		cout << fixed << setprecision(6) << n - ans << endl;
	}
	return 0;
}
