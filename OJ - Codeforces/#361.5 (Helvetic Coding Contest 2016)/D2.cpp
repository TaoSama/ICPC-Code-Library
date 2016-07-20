//
//  Created by TaoSama on 2016-07-10
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
const int N = 1e6 + 10, INF = 0x3f3f3f3f, MOD = 1e6 + 3;

typedef long long LL;
LL inv[MOD], fact[N], finv[MOD];

LL C(int n, int m){
	return fact[n] * finv[m] % MOD * finv[n - m] % MOD;
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);
    clock_t _ = clock();

	fact[0] = finv[0] = 1;
	inv[1] = fact[1] = finv[1] = 1;
	for(int i = 2; i < MOD; ++i){
		inv[i] = (MOD - MOD / i) * inv[MOD % i] % MOD;
		fact[i] = fact[i - 1] * i % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
	}

	int n, m;
	while(scanf("%d%d", &n, &m) == 2){
		LL ans = 0;
		for(int i = 1; i <= n; ++i){
			ans += C(i + m - 1, m - 1);
//			printf("%d: %lld\n", i, C(i + m - 1, m - 1));
			if(ans >= MOD) ans -= MOD;
		}
		printf("%lld\n", ans);
	}

#ifdef LOCAL
    printf("\nTime cost: %.2fs\n", 1.0 * (clock() - _) / CLOCKS_PER_SEC);
#endif
    return 0;
}
