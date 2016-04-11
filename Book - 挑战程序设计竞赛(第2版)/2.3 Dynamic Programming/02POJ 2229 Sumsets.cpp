//
//  POJ 2229 Sumsets
//
//  Created by TaoSama on 2015-03-03
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
const int MOD = 1e9;
const int N = 1e6 + 10;

int n, dp[N];

int main() {
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
//	freopen("out.txt","w",stdout);
#endif
	ios_base::sync_with_stdio(0);

	dp[1] = 1;
	for(int i = 2; i < N; ++i)
		if(i & 1) dp[i] = dp[i - 1];
		else	dp[i] = (dp[i - 1] + dp[i >> 1]) % MOD;
	while(cin >> n) {
		cout << dp[n] << endl;
	}
	return 0;
}

//±³°üµÄ×ËÊÆ
/*
int n, c[25], dp[N];

int main() {
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
//	freopen("out.txt","w",stdout);
#endif
	ios_base::sync_with_stdio(0);

	c[0] = dp[0] = 1;
	for(int i = 1; i <= 20; ++i)
		c[i] = c[i - 1] << 1;
	for(int i = 0; i <= 20 && c[i] < N; ++i)
		for(int j = c[i]; j < N; ++j)
			dp[j] = (dp[j] + dp[j - c[i]]) % MOD;
	while(cin >> n) {
		cout << dp[n] << endl;
	}
	return 0;
}
*/
