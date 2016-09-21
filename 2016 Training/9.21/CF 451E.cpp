//
//  Created by TaoSama on 2016-09-17
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

LL C(LL n, LL m) {
    if(n < m) return 0;
    m = min(m, n - m);

    LL up = 1, dw = 1;
    for(int i = 0; i < m; ++i) {
        up = up * (n - i) % MOD;
        dw = dw * (i + 1) % MOD;
    }
    return up * quick(dw, MOD - 2) % MOD;
}

LL lucas(LL n, LL m) {
    if(m == 0) return 1;
    return C(n % MOD, m % MOD) * lucas(n / MOD, m / MOD) % MOD;
}

LL calc(LL n, LL m) {
    return lucas(n + m - 1, m - 1);
}

int n;
LL s, f[N];

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(cin >> n >> s) {
        for(int i = 0; i < n; ++i) cin >> f[i];

        LL ans = 0;
        for(int i = 0; i < 1 << n; ++i) {
            LL lft = s, cnt = 0;
            for(int j = 0; j < n; ++j) {
                if(i >> j & 1) {
                    lft -= f[j] + 1;
                    ++cnt;
                }
            }
            if(lft < 0) continue;

            if(cnt & 1) ans -= calc(lft, n);
            else ans += calc(lft, n);
            ans %= MOD;
        }
        ans = (ans + MOD) % MOD;
        cout << ans << endl;
    }

    return 0;
}
