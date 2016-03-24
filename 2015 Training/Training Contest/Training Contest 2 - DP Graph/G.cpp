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

int n;
pair<int, int> a[5005];

int main() {
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
//	freopen("out.txt","w",stdout);
#endif
	ios_base::sync_with_stdio(0);

	while(cin >> n) {
		for(int i = 1; i <= n; ++i)
			cin >> a[i].first >> a[i].second;
		sort(a + 1, a + 1 + n);
		int ans = 0;
		for(int i = 1; i <= n; ++i) {
			int t = INF;
			if(a[i].first >= ans) t = min(t, a[i].first);
			if(a[i].second >= ans) t = min(t, a[i].second);
			ans = t;
		}
		cout << ans << endl;
	}
	return 0;
}
