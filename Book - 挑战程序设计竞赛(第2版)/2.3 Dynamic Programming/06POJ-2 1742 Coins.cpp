//
//  POJ 1742 Coins
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
const int MOD = 1e9 + 7;
const int N = 1e5 + 10;

int n, m, w[105], c[105], dp[N];

int main() {
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
//	freopen("out.txt","w",stdout);
#endif
	ios_base::sync_with_stdio(0);

	while(cin >> n >> m && n && m) {
		for(int i = 1; i <= n; ++i)  cin >> w[i];
		for(int i = 1; i <= n; ++i)  cin >> c[i];
		memset(dp, 0xc0, sizeof dp);
		dp[0] = 0;
		for(int i = 1; i <= n; ++i) {
			for(int j = 0; j <= m; ++j) {
				if(dp[j] >= 0) dp[j] = c[i];
				else if(j < w[i] || dp[j - w[i]] <= 0) dp[j] = -INF;
				else	dp[j] = dp[j - w[i]] - 1;
			}
		}
		int ans = 0;
		for(int i = 1; i <= m; ++i) if(dp[i] >= 0) ++ans;
		cout << ans << endl;
	}
	return 0;
}
