//
//  Created by TaoSama on 2016-08-29
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
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e6 + 3;

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
    for(int i = 1; i < N; ++i) {
        fact[i] = fact[i - 1] * i % MOD;
        invf[i] = quick(fact[i], MOD - 2);
    }
}

LL A(int n, int m) {
    if(n < m) return 0;
    return fact[n] *  invf[n - m] % MOD;
}

LL n, k;

LL Legendre(LL n) { //Legendre's formula (n-s_p(n))/(p-1)
    return n - __builtin_popcountll(n);
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    gao();

//    {
//        LL y = 8 * 8 * 1;
//        LL x = y - A(8, 2);
//        LL g = __gcd(y, x);
//        prln(g);
//        cout << x / g << ' ' << y / g << endl;
//    }
//
//    {
//        LL y = 16 * 16 * 16;
//        LL x = A(16, 3);
//        LL g = __gcd(y, x);
//        prln(g);
//        cout << x<< ' ' << y<< endl;
//    }

    while(cin >> n >> k) {
        if(n < 63 && (1LL << n) < k) {
            cout << "1 1\n";
            continue;
        }

        //A(2^n, k) / 2^(nk) = 2^n * (2^n-1) * ... * (2^n-(k-1)) / 2^(nk)
        //gcd(a, b) = gcd(b-a, b)

        LL two = n + Legendre(k - 1);
        LL gcd = quick(2, two), gcdInv = quick(gcd, MOD - 2);

//        prln(gcd);

        LL up = 0;
        if(k < MOD) {
            up = 1;
            LL two = quick(2, n);
            for(LL i = 0; i < k; ++i) {
                up = up * two % MOD;
                two = (two - 1 + MOD) % MOD;
            }
        }
        LL dw = quick(quick(2, n), k);

        up = up * gcdInv % MOD;
        dw = dw * gcdInv % MOD;

        cout << (dw - up + MOD) % MOD << ' ' << dw << endl;
    }

    return 0;
}
