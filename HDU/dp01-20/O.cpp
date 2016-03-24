//
//  HDU 2159 FATE
//
//  Created by TaoSama on 2015-02-08
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

int n, m, k, s;
int w[105], v[105], dp[105][105];

int main() {
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
//	freopen("out.txt","w",stdout);
#endif
	ios_base::sync_with_stdio(0);

	while(cin >> n >> m >> k >> s) {
		for(int i = 1; i <= k; ++i) cin >> v[i] >> w[i];

		CLR(dp, 0);
		for(int i = 1; i <= k; i++) {
			for(int j = w[i]; j <= m; ++j) {
				for(int l = 1; l <= s; ++l)
					dp[j][l] = max(dp[j][l], dp[j - w[i]][l - 1] + v[i]);
			}
		}
		int ans;
		if(dp[m][s] < n) ans = m + 1;
		else {
			for(int i = 0; i <= m; ++i)
				if(dp[i][s] >= n) {
					ans = i;
					break;
				}
		}
		cout << m - ans << endl;
	}
	return 0;
}
