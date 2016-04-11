//
//  POJ 1852 Ants
//
//  Created by TaoSama on 2015-02-16
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



int main() {
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
//	freopen("out.txt","w",stdout);
#endif
	ios_base::sync_with_stdio(0);

	int t; cin >> t;
	while(t--) {
		int l, n, x; cin >> l >> n;
		int MinT = 0, MaxT = 0;
		for(int i = 1; i <= n; ++i) {
			cin >> x;
			MinT = max(MinT, min(x, l - x));
			MaxT = max(MaxT, max(x, l - x));
		}
		cout << MinT << ' ' << MaxT << endl;
	}
	return 0;
}
