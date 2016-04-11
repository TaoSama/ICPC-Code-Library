//
//  POJ 2718 Smallest Difference
//
//  Created by TaoSama on 2015-02-20
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

int n, l, r, a[15];
bool used[15];
void dfs(int k, int b, int s) {
	if(k == n) {
		if(b < s) swap(b, s);
		if(b - s < l - r) l = b, r = s;
		return;
	}
	if(k & 1) {
		for(int i = 0; i < n; ++i) {
			if(!used[i]) {
				if(a[i] == 0 && k == 1) continue;
				used[i] = true;
				dfs(k + 1, b, s * 10 + a[i]);
				used[i] = false;
			}
		}
	} else {
		for(int i = 0; i < n; ++i) {
			if(!used[i]) {
				if(a[i] == 0 && k == 0) continue;
				used[i] = true;
				dfs(k + 1, b * 10 + a[i], s);
				used[i] = false;
			}
		}
	}
}

int main() {
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
//	freopen("out.txt","w",stdout);
#endif
	ios_base::sync_with_stdio(0);

	int t; scanf("%d ", &t);
	while(t--) {
		char c; n = 0;
		memset(used, false, sizeof used);
		while(scanf("%c", &c) == 1 && c != '\n') {
			if(c == ' ') continue;
			a[n++] = c - '0';
		}
		int ans = INF, x, y;
		if(n == 2) ans = a[1] - a[0];
		else {
			l = INF, r = 0;
			dfs(0, 0, 0);
			ans = l - r;
		}
		printf("%d\n", ans);
	}

	return 0;
}

//next_permutation枚举全排列求解
/*
int n, a[15];
int cal(int st, int ed) {
	int ret = 0;
	for(int i = st; i < ed; ++i) {
		if(a[st] == 0) break;
		ret = ret * 10 + a[i];
	}
	return ret == 0 ? INF : ret;
}
int main() {
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
//	freopen("out.txt","w",stdout);
#endif
	ios_base::sync_with_stdio(0);

	int t; scanf("%d ", &t);
	while(t--) {
		char c; n = 0;
		while(scanf("%c", &c) == 1 && c != '\n') {
			if(c == ' ') continue;
			a[n++] = c - '0';
		}
		int ans = INF, x, y;
		if(n == 2) ans = a[1] - a[0];
		else do {
				x = cal(0, n >> 1);
				y = cal(n >> 1, n);
				if(x != INF && y != INF) ans = min(ans, abs(x - y));
			} while(next_permutation(a, a + n));
		printf("%d\n", ans);
	}
	return 0;
}
*/
