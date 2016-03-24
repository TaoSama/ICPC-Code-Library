//
//
//
//  Created by TaoSama on 2015-03-15
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

int n, m;
int dp[105][105];

int main() {
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
//	freopen("out.txt","w",stdout);
#endif
	ios_base::sync_with_stdio(0);

	while(cin >> n >> m && n && m) {
		memset(dp, 0x3f,sizeof dp);
		for(int i = 1; i <= m; ++i) {
			int x, y, v; cin >> x >> y >> v;
			dp[x][y] = dp[y][x] = v;
		}
		for(int k = 1; k <= n; ++k) {
			for(int i = 1 ; i <= n; ++i) {
				for(int j = 1; j <= n; ++j) {
					if(dp[i][j] > dp[i][k] + dp[k][j])
						dp[i][j] = dp[i][k] + dp[k][j];
				}
			}
		}
		cout << dp[1][n] << endl;
	}
	return 0;
}