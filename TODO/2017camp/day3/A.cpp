//
//  Created by TaoSama on 2017-02-14
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
const int N = 2e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

typedef long long LL;
typedef __int128 BigInt;

int n;
LL a[N], b[N], c[N];

// exgcd
LL exgcd(LL a, LL b, LL& x, LL& y) {
    LL d = a;
    if(!b) x = 1, y = 0;
    else {
        d = exgcd(b, a % b, y, x);
        y -= (a / b) * x;
    }
    return d;
}

BigInt A, B;

bool ok(LL m, LL k) {
    for(int i = 1; i <= n; ++i) {
        c[i] = (a[i] + k) % m;
        if(!binary_search(b + 1, b + 1 + n, c[i])) return false;
    }
    sort(c + 1, c + 1 + n);
    for(int i = 1; i <= n; ++i) if(b[i] != c[i]) return false;
    return true;
}

bool check(LL m) {
    LL a = n, b = m, c = ((B - A) % m + m) % m;
    LL x, y, g = exgcd(a, b, x, y);
    if(c % g) return false;
    x = (BigInt) x * c / g % b;
    LL k = (x + b) % (b / g);
    for(int i = 0; i < g; ++i, k += b / g) {
        if(ok(m, k)) {
            printf("%lld %lld\n", m, k);
            return true;
        }
    }
    return false;
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d", &n) == 1) {
        A = B = 0;
        for(int i = 1; i <= n; ++i) scanf("%lld", a + i), A += a[i];
        for(int i = 1; i <= n; ++i) scanf("%lld", b + i), B += b[i];

        sort(b + 1, b + 1 + n);

        for(LL m = b[n] + 1; ; ++m)
            if(check(m)) break;
    }

    return 0;
}
