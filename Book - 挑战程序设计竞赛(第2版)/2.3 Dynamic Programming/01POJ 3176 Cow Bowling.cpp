//
//  POJ 3176 Cow Bowling
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
const int MOD = 1e9 + 7;
const int N = 1e5 + 10;

int n, a[400][400], dp[400][400];

int main() {
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
//	freopen("out.txt","w",stdout);
#endif
	ios_base::sync_with_stdio(0);

	while(cin >> n) {
		memset(dp, 0, sizeof dp);
		for(int i = 1; i <= n; ++i) {
			for(int j = 1; j <= i; ++j) {
				cin >> a[i][j];
				if(i == n) dp[i][j] = a[i][j];
			}
		}
		for(int i = n - 1; i >= 1; --i) {
			for(int j = 1; j <= i; ++j) {
				dp[i][j] = max(dp[i+1][j],dp[i+1][j+1]) + a[i][j];
//				printf("dp[%d][%d]: %d\n",i,j,dp[i][j]);
			}
		}
		cout<<dp[1][1]<<endl;
	}
	return 0;
}
