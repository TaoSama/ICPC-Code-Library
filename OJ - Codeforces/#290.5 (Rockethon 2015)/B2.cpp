//
//  B2.Permutation
//
//  Created by TaoSama on 2015-02-08
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

int n, a[55]; long long m;

int dfs(int dep, long long x) {
	if(dep == 1) return 1;
	int cur = dfs(dep - 1, (x + 1) >> 1) + (x & 1);
	for(int i = dep; i >= cur + 1 ; --i)
		a[i] = a[i - 1];
	a[cur] = dep;
	return cur;
}

int main() {
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
//	freopen("out.txt","w",stdout);
#endif
	ios_base::sync_with_stdio(0);

	while(cin >> n >> m) {
		a[1] = 1;
		dfs(n, m);
		for(int i = 1; i < n; ++i)
			cout << a[i] << ' ';
		cout << a[n] << endl;
	}
	return 0;
}
/*
int ans[777];

int main() {
	int n; long long m;
	cin >> n >> m;
	int l = 0, r = n - 1;
	for(int j = n - 1; j > 0; j--) {
		if(m <= (1LL << (j - 1))) {
			ans[l++] = n - j;
		} else {
			ans[r--] = n - j;
			m -= (1LL << (j - 1));
		}
	}
	ans[l] = n;
	for(int i = 0; i < n; i++) cout << ans[i] << " ";
	cout << endl;
	return 0;
}
*/
