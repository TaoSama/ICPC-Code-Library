//
//  AOJ 0525 Osenbei
//
//  Created by TaoSama on 2015-02-21
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

int n, m, ans, row[15];
bool a[15][10005];
void dfs(int r) {
	if(r == n) {
		int ret = 0;
		for(int j = 1; j <= m; ++j) {
			int up = 0;
			for(int i = 1; i <= n; ++i) {
				if(!row[i] && a[i][j] || row[i] && !a[i][j])
					++up;
			}
			ret += max(up, n - up);
		}
		ans = max(ans, ret);
		return;
	}
	row[r] = false;
	dfs(r + 1);
	row[r] = true;
	dfs(r + 1);
}

int main() {
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
//	freopen("out.txt","w",stdout);
#endif
	ios_base::sync_with_stdio(0);

	while(cin >> n >> m && n && m) {
		memset(row, 0, sizeof row);
		for(int i = 1; i <= n; ++i)
			for(int j = 1; j <= m; ++j)
				cin >> a[i][j];
		ans = 0;
		dfs(0);
		cout << ans << endl;
	}
	return 0;
}
