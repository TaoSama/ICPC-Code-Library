//
//  Created by TaoSama on 2016-08-04
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
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

typedef long long LL;

LL quick(LL x, LL n) {
    LL ret = 1;
    for(; n; n >>= 1) {
        if(n & 1) ret = ret * x % MOD;
        x = x * x % MOD;
    }
    return ret;
}

LL fact[N], invf[N];

void gao() {
    fact[0] = invf[0] = 1;
    for(int i = 1; i < 100; ++i) {
        fact[i] = fact[i - 1] * i % MOD;
        invf[i] = quick(fact[i], MOD - 2);
    }
}

LL C(int n, int m) {
    if(n < m) return 0;
    return fact[n] * invf[m] % MOD * invf[n - m] % MOD;
}

int n, m;
int a[N];

LL ans;
void dfs(int dep) {
    if(dep == m) {
        LL tmp = 1;
        for(int i = 1; i < m; ++i)
            tmp = tmp * C(a[i], a[i - 1]) % MOD;
        if((ans += tmp) >= MOD) ans -= MOD;
        return;
    }
    for(int i = 0; i <= n; ++i) {
        a[dep] = i;
        dfs(dep + 1);
    }
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

//  gao();
//  for(n = 0; n <= 5; ++n){
//      for(m = 2; m <= 10; ++m){
//          ans = 0;
//          dfs(0);
//          printf("%d %d %I64d\n", n, m, ans);
//      }
//  }

    int t; scanf("%d", &t);
    while(t--) {
        scanf("%d%d", &n, &m);
        LL result = (1 - quick(m, n + 1)) * quick(1 - m, MOD - 2) % MOD;
        result = (result + MOD) % MOD;
        printf("%I64d\n", result);
    }

    return 0;
}
