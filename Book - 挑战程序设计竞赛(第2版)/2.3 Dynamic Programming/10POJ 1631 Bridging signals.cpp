//
//  POJ 1631 Bridging signals
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

int a[40005], dp[40005];

int main() {
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
//	freopen("out.txt","w",stdout);
#endif
	ios_base::sync_with_stdio(0);

	int t; cin >> t;
	while(t--) {
		int n; cin >> n;
		memset(dp, 0x3f, sizeof dp);
		int ans = 1;
		for(int i = 1; i <= n; ++i) {
			int x; cin >> x;
			int l = 1, r = ans;
			while(l <= r) {
				int mid = (l + r) >> 1;
				if(dp[mid] < x) l = mid + 1;
				else	r = mid - 1;
			}
			dp[l] = x;
			ans = max(ans, l);
		}
		cout << ans << endl;
	}
	return 0;
}
