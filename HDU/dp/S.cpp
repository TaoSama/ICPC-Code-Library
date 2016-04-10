//
//  HDU 2870 Largest Submatrix
//
//  Created by TaoSama on 2015-02-12
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

int n, m, h[1005], l[1005], r[1005];
char a[1005][1005];

int cal(char c) {
	int ret = -INF;
	memset(h, 0, sizeof h); h[0] = h[m + 1] = -1;
	for(int i = 1; i <= n; ++i) {
		for(int j = 1; j <= m; ++j) {
			if(c == 'a') {
				if(a[i][j] == 'w' || a[i][j] == 'y' || a[i][j] == 'z' || a[i][j] == c)
					++h[j];
				else h[j] = 0;
			} else if(c == 'b') {
				if(a[i][j] == 'w' || a[i][j] == 'x' || a[i][j] == 'z' || a[i][j] == c)
					++h[j];
				else h[j] = 0;
			} else {
				if(a[i][j] == 'x' || a[i][j] == 'y' || a[i][j] == 'z' || a[i][j] == c)
					++h[j];
				else h[j] = 0;
			}
		}
		for(int j = 1; j <= m; ++j) l[j] = r[j] = j;
		for(int j = 1; j <= m; ++j)
			while(h[l[j] - 1] >= h[j])
				l[j] = l[l[j] - 1];
		for(int j = m; j >= 1; --j)
			while(h[r[j] + 1] >= h[j])
				r[j] = r[r[j] + 1];

		for(int j = 1; j <= m; ++j)
			ret = max(ret, (r[j] - l[j] + 1) * h[j]);
	}
	return ret;
}
int main() {
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
//	freopen("out.txt","w",stdout);
#endif
	ios_base::sync_with_stdio(0);

	while(cin >> n >> m) {
		for(int i = 1; i <= n; ++i) cin >> a[i] + 1;
		int ans = max(cal('a'), max(cal('b'), cal('c')));
		cout << ans << endl;
	}
	return 0;
}
