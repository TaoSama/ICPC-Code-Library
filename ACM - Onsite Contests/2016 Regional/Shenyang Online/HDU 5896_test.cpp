//
//  Created by TaoSama on 2016-09-18
//  Copyright (c) 2016 TaoSama. All rights reserved.
//
#pragma comment(linker, "/STACK:102400000,102400000")
#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
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
const int N = 5, INF = 0x3f3f3f3f, MOD = 1004535809;
const int G = 3;

typedef long long LL;
LL fact[N], finv[N];

LL C(int n, int m){
	if(n < m) return 0;
	return fact[n] * finv[m] % MOD * finv[n - m] % MOD;
}

LL quick(LL x, LL n, LL m){
	LL ret = 1;
	for(; n; n >>= 1){
		if(n & 1) ret = ret * x % m;
		x = x * x % m;
	}
	return ret;
}

LL f[N], g[N];

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

	fact[0] = finv[0] = 1;
	for(int i = 1; i < N; ++i) {
		fact[i] = fact[i - 1] * i % MOD;
		finv[i] = quick(fact[i], MOD - 2, MOD);
	}

	for(int i = 1; i < N; ++i) {
		LL e = 1LL * i * (i - 1) / 2;
		g[i] = quick(2, e, MOD);
	}

	f[0] = 1;
	for(int i = 1; i < N; ++i){
		f[i] = 0;
//		prln(i);
		for(int j = 0; j < i; ++j){
			LL mul = j == 0 ? 1 : quick(j + 1, j - 1, MOD);
//			pr(j);pr(C(i-1,j)); pr(mul); prln(f[i-1-j]);
			f[i] += C(i-1, j) * mul % MOD * f[i - 1 - j] % MOD;
			f[i] %= MOD;
		}
	}
	for(int i = 1; i < N; ++i){
//		pr(f[i]); prln(g[i]);
		LL ans = (g[i] - f[i] + MOD) % MOD;
		cout << i << ' ' << ans << endl;
	}

    return 0;
}
