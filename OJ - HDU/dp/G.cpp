//
//  HDU 2602 Bone Collector
//
//  Created by TaoSama on 2015-02-09
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

int n, V, w[1005], v[1005], dp[1005];

int main() {
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
//	freopen("out.txt","w",stdout);
#endif
	ios_base::sync_with_stdio(0);

	int t; cin >> t;
	while(t--) {
		cin >> n >> V;
		for(int i = 1; i <= n; ++i) cin >> v[i];
		for(int i = 1; i <= n; ++i) cin >> w[i];

		CLR(dp, 0);
		for(int i = 1; i <= n; ++i)
			for(int j = V; j >= w[i]; --j)
				dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
		cout << dp[V] << endl;
	}
	return 0;
}
