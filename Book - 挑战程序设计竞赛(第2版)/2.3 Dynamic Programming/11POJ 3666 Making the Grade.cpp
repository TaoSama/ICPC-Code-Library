//
//  POJ 3666 Making the Grade
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
const int N = 1e5 + 10;

//dp[i][j]表示第i个位置的值改成b数组中第j个数的值，且前i个有序（单调不上升或者单调不下降）
//dp[i][j] = min (dp[i - 1][k]）+ abs (a[i] - b[j])
//最小的dp[i - 1][k]可以边循环边找，且k<=j

int n, a[2005], b[2005], dp[2005];
int solve() {
	memset(dp, 0, sizeof dp);
	for(int i = 1; i <= n; ++i) {
		int preMin = INF;
		for(int j = 1; j <= n; ++j) {
			preMin = min(preMin, dp[j]);
			dp[j] = preMin + abs(a[i] - b[j]);
		}
	}
	return *min_element(dp + 1, dp + 1 + n);
}

int main() {
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
//	freopen("out.txt","w",stdout);
#endif
	ios_base::sync_with_stdio(0);

	while(cin >> n) {
		for(int i = 1; i <= n; ++i) cin >> a[i], b[i] = a[i];

		sort(b + 1, b + 1 + n);
		int ans = INF;
		ans = min(ans, solve());
		reverse(b + 1, b + 1 + n);
		ans = min(ans, solve());
		cout << ans << endl;
	}
	return 0;
}
