//
//  HDU 2830 Matrix Swapping II
//
//  Created by TaoSama on 2015-02-07
//  Copyright (c) 2014 TaoSama. All rights reserved.
//
#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <functional>
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

int n, m, h[1005], t[1005];

int main() {
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
//	freopen("out.txt","w",stdout);
#endif
	ios_base::sync_with_stdio(0);
	while(cin >> n >> m) {
		CLR(h, 0);
		int ans = -INF;
		for(int i = 1; i <= n; ++i) {
			string a; cin >> a;
			for(int j = 0; j < m; ++j) {
				if(a[j] == '1') ++h[j + 1];
				else			h[j + 1] = 0;
				t[j + 1] = h[j + 1];
			}
			sort(t + 1, t + 1 + m, greater<int>());
			for(int j = 1; j <= m; ++j)
				ans = max(ans, t[j] * j);
		}
		cout << ans << endl;
	}
	return 0;
}
