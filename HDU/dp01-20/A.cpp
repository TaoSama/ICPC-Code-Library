//
//  HDU 2955 Robbery
//
//  Created by TaoSama on 2015-02-05
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
#define CLR(x) memset(x, 0, sizeof(x))

using namespace std;
const int INF = 0x3f3f3f3f;
const double EPS = 1e-9;
const int MOD = 1e9 + 7;
const int N = 1e5 + 10;

int w[105];
double v[105], dp[N]; //dp[j]表示j钱数的最大概率

int main() {
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
//	freopen("out.txt","w",stdout);
#endif
	ios_base::sync_with_stdio(0);
	int kase, n; cin >> kase;
	while(kase--) {
		memset(dp, 0, sizeof dp);
		double p; cin >> p >> n; p = 1 - p;
		int sum = 0;
		for(int i = 1; i <= n; ++i) {
			cin >> w[i] >> v[i];
			v[i] = 1 - v[i];
			sum += w[i];
		}
		dp[0] = 1; int ans = -INF;
		for(int i = 1; i <= n; ++i)
			for(int j = sum; j >= w[i]; --j)
				dp[j] = max(dp[j], dp[j - w[i]] * v[i]);

		for(int i = sum; i >= 0; --i)
			if(dp[i] - p > EPS) {
				ans = i;
				break;
			}
		cout << ans << endl;
	}
	return 0;
}
