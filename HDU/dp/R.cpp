//
//  HDU 2845 Beans
//
//  Created by TaoSama on 2015-02-06
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
#define CLR(x) memset(x, 0, sizeof(x))

using namespace std;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int N = 2e5 + 10;

int n, m, x, dpx[N], dpy[N]; //dpx[j]表示前j列, dpy[i]表示前i行的 最大值

int main() {
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
//	freopen("out.txt","w",stdout);
#endif
	ios_base::sync_with_stdio(0);
	while(cin >> n >> m) {
		memset(dpx,0,sizeof dpx);
		memset(dpy,0,sizeof dpy);
		for(int i = 2; i <= n + 1; ++i) {
			for(int j = 2; j <= m + 1; ++j) {
				cin >> x;
				dpx[j] = max(dpx[j - 1], dpx[j - 2] + x);
			}
			dpy[i] = max(dpy[i - 1], dpy[i - 2] + dpx[m + 1]);
		}
		cout << dpy[n + 1] << endl;
	}
	return 0;
}
