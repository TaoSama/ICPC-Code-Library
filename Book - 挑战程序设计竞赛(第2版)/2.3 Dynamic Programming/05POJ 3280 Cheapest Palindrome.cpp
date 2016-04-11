//
//  POJ 3280 Cheapest Palindrome
//
//  Created by TaoSama on 2015-03-04
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

int n, m, dp[2005][2005], cost[30];
char a[2005];
int main() {
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
//	freopen("out.txt","w",stdout);
#endif
	ios_base::sync_with_stdio(0);

	while(cin >> n >> m >> (a + 1)) {
		for(int i = 1; i <= n; ++i) {
			char c; int x, y; cin >> c >> x >> y;
			cost[c - 'a'] = min(x, y);
		}
		memset(dp, 0, sizeof dp);
		for(int i = m; i >= 1; --i)
			for(int j = i + 1; j <= m; ++j)
				if(a[i] == a[j]) dp[i][j] = dp[i + 1][j - 1];
				else dp[i][j] = min(dp[i + 1][j] + cost[a[i] - 'a'],
					                    dp[i][j - 1] + cost[a[j] - 'a']);
		cout << dp[1][m] << endl;
	}
	return 0;
}
