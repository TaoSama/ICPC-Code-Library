//
//
//
//  Created by TaoSama on 2015-03-08
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
const int N = 1e4 + 10;

char s[N];
int pre[N], suf[N];

int main() {
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
//	freopen("out.txt","w",stdout);
#endif
	ios_base::sync_with_stdio(0);

	while(cin >> (s + 1)) {
		int l = strlen(s + 1);
		memset(pre, 0, sizeof pre);
		memset(suf, 0, sizeof suf);
		for(int i = 1; i <= l; ++i) {
			for(int j = i, k = i; j >= 1 && k <= l && s[j] == s[k]; --j, ++k)
				++pre[j], ++suf[k];
			for(int j = i, k = i + 1; j >= 1 && k <= l && s[j] == s[k]; --j, ++k)
				++pre[j], ++suf[k];
		}
		for(int i = 2; i <= l; ++i) suf[i] += suf[i - 1];
		long long ans = 0;
		for(int i = 1; i <= l; ++i) ans += pre[i] * suf[i - 1];
		cout << ans << endl;
	}
	return 0;
}
