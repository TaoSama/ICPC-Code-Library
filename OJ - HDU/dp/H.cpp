//
//  HDU 1087 Super Jumping! Jumping! Jumping!
//
//  Created by TaoSama on 2015-02-09
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

int n, a[1005];
int ans, dp[1005];

int main() {
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
//	freopen("out.txt","w",stdout);
#endif
	ios_base::sync_with_stdio(0);

	while(cin >> n && n) {
		for(int i = 1; i <= n; ++i) cin >> a[i];

		CLR(dp, 0); ans = dp[1] = a[1];
		for(int i = 2; i <= n; ++i) {
			dp[i] = a[i];
			for(int j = 1; j < i; ++j) {
				if(a[i] > a[j]) dp[i] = max(dp[i], dp[j] + a[i]);
				ans = max(ans, dp[i]);
			}
		}
		cout << ans << endl;
	}
	return 0;
}
