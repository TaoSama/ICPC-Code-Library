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

int n, m, w[105], c[105];
bool dp[N];

int main() {
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
//	freopen("out.txt","w",stdout);
#endif
	ios_base::sync_with_stdio(0);

	while(cin >> n >> m && n && m) {
		for(int i = 1; i <= n; ++i)  cin >> w[i];
		for(int i = 1; i <= n; ++i)  cin >> c[i];
		memset(dp, false, sizeof dp);
		dp[0] = true;
		for(int i = 1; i <= n; ++i) {
			int k = 1;
			while(c[i] > 0) {
				int v = w[i] * min(k, c[i]);
				for(int j = m; j >= v; --j)
					dp[j] |= dp[j - v];
				c[i] -= k; k <<= 1;
			}
		}
		cout << count(dp + 1, dp + 1 + m, true) << endl;
	}
	return 0;
}