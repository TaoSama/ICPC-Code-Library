//
//  POJ 2184 Cow Exhibition
//
//  Created by TaoSama on 2015-03-06
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
const int N = 2e5 + 10;

int n, s[105], f[105], dp[N];

int main() {
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
//	freopen("out.txt","w",stdout);
#endif
	ios_base::sync_with_stdio(0);

	while(cin >> n) {
		for(int i = 1; i <= n; ++i)
			cin >> s[i] >> f[i];

		memset(dp, 0xc0, sizeof dp);
		int center = 1e5, range = 2e5;
		dp[center] = 0;
		for(int i = 1; i <= n; ++i) {
			if(s[i] < 0 && f[i] < 0) continue;
			else if(s[i] > 0) {
				for(int j = range; j >= s[i]; --j)
					dp[j] = max(dp[j], dp[j - s[i]] + f[i]);
			} else {
				for(int j = 0; j <= range + s[i]; ++j)
					dp[j] = max(dp[j], dp[j - s[i]] + f[i]);
			}
		}
		int ans = -INF;
		for(int i = center; i <= range; ++i)
			if(dp[i] >= 0) ans = max(ans, dp[i] + i - center);
		cout << ans << endl;
	}
	return 0;
}
