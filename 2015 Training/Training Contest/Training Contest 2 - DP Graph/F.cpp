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

int n, a[4005], dp[4005][4005];

int main() {
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
//	freopen("out.txt","w",stdout);
#endif
	ios_base::sync_with_stdio(0);

	while(cin >> n) {
		for(int i = 1; i <= n; ++i) cin >> a[i];

		int ans = 0;
		//dp[i][j]:= 以a[i] a[j]结尾的满足要求的序列的最大长度
		dp[0][0] = 0;
		for(int i = 1; i <= n; ++i){
			for(int j = 0, last = 0; j < i; ++j){
				dp[j][i] = dp[last][j] + 1;
				if(a[j] == a[i]) last = j;
				ans = max(ans, dp[j][i]);
			}
		}
		cout << ans << endl;
	}
	return 0;
}
