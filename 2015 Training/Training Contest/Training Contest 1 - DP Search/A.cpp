//
//
//
//  Created by TaoSama on 2015-03-08
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

int n, m, dp[10005], sum[10005], v[10005];

int main() {
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
//	freopen("out.txt","w",stdout);
#endif
	ios_base::sync_with_stdio(0);

	while(cin >> n >> m) {
		memset(dp, 0, sizeof dp);
		for(int i = 1; i <= n; ++i) {
			int ct; cin >> ct;
			sum[0] = 0;
			for(int j = 1; j <= ct; ++j) {
				int x; cin >> x;
				sum[j] = sum[j - 1] + x;
			}
			memset(v, 0, sizeof v);
			for(int j = 1; j <= ct; ++j) {
				for(int k = 0; k <= j; ++k) {
					v[j] = max(v[j], sum[k] + sum[ct] - sum[ct - j + k]);
				}
			}
			for(int j = m; j >= 1; --j) {
				for(int k = 1; k <= ct && k <= j; ++k) {
					dp[j] = max(dp[j], dp[j - k] + v[k]);
				}
			}
		}
		cout << dp[m] << endl;
	}
	return 0;
}
