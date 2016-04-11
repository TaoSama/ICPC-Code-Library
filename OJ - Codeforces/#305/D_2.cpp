//
//  Created by TaoSama on 2015-05-28
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
const int N = 2e5 + 10;

int n, a[N], l[N], r[N], ans[N];

int main() {
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
//	freopen("out.txt","w",stdout);
#endif
	ios_base::sync_with_stdio(0);

	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) scanf("%d", a + i);
	for(int i = 1; i <= n; ++i) l[i] = r[i] = i;

	for(int i = 1; i <= n; ++i){
		while(a[l[i] - 1] >= a[i])
			l[i] = l[l[i] - 1];
	}
	for(int i = n; i >= 1; --i){
		while(a[r[i] + 1] >= a[i])
			r[i] = r[r[i] + 1];
	}

	for(int i = 1; i <= n; ++i){
		int w = r[i] - l[i] + 1;
		ans[w] = max(ans[w], a[i]);
	}
	for(int i = n - 1; i >= 1; --i)
		ans[i] = max(ans[i], ans[i + 1]);
	for(int i = 1; i <= n; ++i)
		printf("%d%c", ans[i], i == n ? '\n' : ' ');
	return 0;
}
