//
//  POJ 2392 Space Elevator
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

int n, dp[40005];
struct Block {
	int w, h, ct;
	bool operator<(const Block& rhs) const {
		return h < rhs.h;
	}
} a[405];

int main() {
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
//	freopen("out.txt","w",stdout);
#endif
	ios_base::sync_with_stdio(0);

	while(cin >> n) {
		int V = -INF;
		for(int i = 1; i <= n; ++i) {
			cin >> a[i].w >> a[i].h >> a[i].ct;
			V = max(V, a[i].h);
		}
		sort(a + 1, a + 1 + n);
		memset(dp, 0, sizeof dp);
		for(int i = 1; i <= n; ++i)
			for(int k = 1; k <= a[i].ct; ++k)
				for(int j = a[i].h; j >= a[i].w; --j)
					dp[j] = max(dp[j], dp[j - a[i].w] + a[i].w);
		cout << *max_element(dp, dp + V + 1) << endl;
		//坑点 - - 有可能后面的垒不起来
	}
	return 0;
}
