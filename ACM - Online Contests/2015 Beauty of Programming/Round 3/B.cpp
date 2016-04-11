//
//  Created by TaoSama on 2015-05-09
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

using namespace std;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int N = 1e5 + 10;

int n, q, a[1005];

int main() {
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
//	freopen("out.txt","w",stdout);
#endif
	ios_base::sync_with_stdio(0);

	int t; scanf("%d", &t);
	int kase = 0;
	while(t--){
		scanf("%d%d", &n, &q);
		printf("Case #%d:\n", ++kase);
		for(int i = 1; i <= n; ++i) scanf("%d", a + i);
		while(q--){
			int l, r, k; scanf("%d%d%d", &l, &r, &k);
			int ans = INF;
			for(int i = l; i <= r; ++i)
				ans = min(ans, abs(a[i] - k));
			printf("%d\n", ans);
		}
	}
	return 0;
}
