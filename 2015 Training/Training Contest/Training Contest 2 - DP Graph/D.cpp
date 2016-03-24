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

char a[N];
int sum[N];

int main() {
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
//	freopen("out.txt","w",stdout);
#endif
	ios_base::sync_with_stdio(0);

	while(cin >> (a + 1)) {
		int n = strlen(a + 1); sum[1] = 0;
		for(int i = 2; i <= n; ++i)
			sum[i] = sum[i - 1] + (a[i] == a[i - 1]);
		int m; cin >> m;
		for(int i = 1; i <= m; ++i) {
			int l, r; cin >> l >> r;
			cout << sum[r] - sum[l] << endl;
		}
	}
	return 0;
}
