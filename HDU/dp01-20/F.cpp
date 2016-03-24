//
//  HDU 1505 City Game
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

int l[1005], r[1005], h[1005];
char a[5];

int main() {
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
//	freopen("out.txt","w",stdout);
#endif
	ios_base::sync_with_stdio(0);

	int k; cin >> k;
	while(k--) {
		int n, m; cin >> n >> m;
		int ans = -INF;

		CLR(h, 0); h[0] = h[m + 1] = -1;

		for(int i = 1; i <= n; ++i) {
			for(int j = 1; j <= m; ++j) {
				cin >> a;
				if(a[0] == 'F') ++h[j];
				else            h[j] = 0;
			}

			for(int j =  1; j <= m; ++j)
				l[j] = r[j] = j;
			for(int j = 1; j <= n; ++j)
				while(h[l[j] - 1] >= h[j])
					l[j] = l[l[j] - 1];
			for(int j = m; j >= 1; --j)
				while(h[r[j] + 1] >= h[j])
					r[j] = r[r[j] + 1];

			for(int j = 1; j <= m; ++j)
				ans = max(ans, (r[j] - l[j] + 1) * h[j]);
		}
		cout << ans * 3 << endl;
	}
	return 0;
}
