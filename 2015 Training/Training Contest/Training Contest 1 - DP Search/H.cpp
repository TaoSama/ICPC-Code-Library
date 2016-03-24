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

long long n, p[1005], dp[1005], b[1005];

int main() {
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
//	freopen("out.txt","w",stdout);
#endif
	ios_base::sync_with_stdio(0);
	while(cin >> n) {
		for(int i = 1; i <= n; ++i) cin >> p[i];

		memset(dp, 0, sizeof dp);
		for(int i = 1; i <= n; ++i) {
			dp[i + 1] = (dp[i] + 1) + (dp[i] - dp[p[i]] + 1);
			dp[i + 1] = (dp[i + 1] + MOD) % MOD;
		}
		cout << dp[n + 1] << endl;

		/*
		memset(b, 0, sizeof b);
		int ans = 0, pos = 1;
		for(;; ++ans) {
			++b[pos];
			if(pos == n + 1) break;
			if(b[pos] & 1) pos = p[pos];
			else ++pos;
			if(ans == MOD) ans = 0;
		}
		cout << ans << endl;
		for(int i = 1; i <= n + 1; ++i)
			cout << i << ": " << b[i] << endl;
		*/
	}
	return 0;
}
