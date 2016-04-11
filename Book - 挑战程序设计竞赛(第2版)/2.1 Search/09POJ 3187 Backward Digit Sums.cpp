//
//  POJ 3187 Backward Digit Sums
//
//  Created by TaoSama on 2015-02-21
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

int n, s, a[15], t[15], c[15][15];

void InitC() {
	for(int i = 0; i < 10; ++i) {
		for(int j = 0; j <= i; ++j) {
			if(i == j || j == 0) c[i][j] = 1;
			else c[i][j] = c[i - 1][j] + c[i - 1][j - 1];
		}
	}
}

int main() {
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
//	freopen("out.txt","w",stdout);
#endif
	//ios_base::sync_with_stdio(0);

	InitC();
	while(cin >> n >> s) {
		for(int i = 1; i <= n; ++i) a[i] = i;
		do {
			int sum = 0;
			for(int i = 1; i <= n; ++i)
				sum += c[n - 1][i - 1] * a[i];
			if(sum == s) break;
		} while(next_permutation(a + 1, a + 1 + n));
		for(int i = 1; i <= n; ++i)
			if(i == n) cout << a[i] << endl;
			else	cout << a[i] << ' ';
	}
	return 0;
}
