//
//
//
//  Created by TaoSama on 2015-03-22
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

int n, m;
double dp[35][35];
map<string, int> mp;

int main() {
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
//	freopen("out.txt","w",stdout);
#endif
	//ios_base::sync_with_stdio(0);

	int kase = 0;
	while(cin >> n && n) {
		mp.clear();
		for(int i = 1; i <= n; ++i) {
			string s; cin >> s;
			mp[s] = i;
		}
		cin >> m;
		for(int i = 1; i <= n; ++i)
			for(int j = 1; j <= n; ++j)
				dp[i][j] = i == j ? 1 : 0;
		for(int i = 1; i <= m; ++i) {
			string s, t; double v;
			cin >> s >> v >> t;
			dp[mp[s]][mp[t]] = v;
		}

		for(int k = 1; k <= n; ++k)
			for(int i = 1; i <= n; ++i)
				for(int j = 1; j <= n; ++j)
					dp[i][j] = max(dp[i][j], dp[i][k] * dp[k][j]);

		bool ok = false;
		for(int i = 1; i <= n; ++i)
			if(dp[i][i] > 1) {
				ok = true;
				break;
			}
		cout << "Case " << ++kase << ": ";
		if(ok) cout << "Yes" << endl;
		else cout << "No" << endl;
	}
	return 0;
}
