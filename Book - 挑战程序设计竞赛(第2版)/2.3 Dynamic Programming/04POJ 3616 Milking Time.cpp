//
//  POJ 3616 Milking Time
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
const int N = 1e6 + 10;

int n, m, r, dp[1005];
struct Seg {
	int l, r, v;
	bool operator<(const Seg& rhs) const {
		return l < rhs.l;
	}
} a[1005];

int main() {
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
//	freopen("out.txt","w",stdout);
#endif
	ios_base::sync_with_stdio(0);

	while(cin >> n >> m >> r) {
		for(int i = 1; i <= m; ++i) {
			cin >> a[i].l >> a[i].r >> a[i].v;
			a[i].r += r;
		}
		sort(a + 1, a + 1 + m);

		memset(dp, 0, sizeof dp);
		for(int i = 1; i <= m; ++i) {
			dp[i] = a[i].v;
			for(int j = 1; j < i; ++j)
				if(a[i].l >= a[j].r)
					dp[i] = max(dp[i], dp[j] + a[i].v);
		}
		int ans = *max_element(dp + 1, dp + 1 + m);
		cout << ans << endl;
	}
	return 0;
}
