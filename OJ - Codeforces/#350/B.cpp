//
//  Created by TaoSama on 2016-05-05
//  Copyright (c) 2016 TaoSama. All rights reserved.
//
#pragma comment(linker, "/STACK:102400000,102400000")
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
#define pr(x) cout << #x << " = " << x << "  "
#define prln(x) cout << #x << " = " << x << endl
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, k, a[N];

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

	while(cin >> n >> k){
		for(int i = 1; i <= n; ++i) cin >> a[i];

		int l = 1, r = n;
		while(l <= r){
			int m = l + r >> 1;
			if(1LL * (1 + m) * m >> 1 <= k) l = m + 1;
			else r = m - 1;
		}
        --l;
//      prln(l);
		int lft = k - (1LL * (1 + l) * l >> 1);
		if(lft == 0) lft = l;
		cout << a[lft] << '\n';
	}
    return 0;
}
