//
//  POJ 3069 Saruman's Army
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

int r, n, a[1005];

int main() {
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
//	freopen("out.txt","w",stdout);
#endif
	ios_base::sync_with_stdio(0);

	while(cin >> r >> n && r != -1 && n != -1) {
		for(int i = 1; i <= n; ++i) cin >> a[i];
		sort(a + 1, a + 1 + n);
		int i = 1, ans = 0;
		while(i <= n) {
			int s = i++;
			while(i <= n && a[i] <= a[s] + r) ++i;
			int pos = i - 1;
			while(i <= n && a[i] <= a[pos] + r) ++i;
			++ans;
		}
		cout << ans << endl;
	}
	return 0;
}
