//
//  Created by TaoSama on 2016-10-08
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

int n, m, k;

typedef long long LL;
LL exgcd(LL a, LL b, LL& x, LL& y) {
    LL d = a;
    if(!b) x = 1, y = 0;
    else {
        d = exgcd(b, a % b, y, x);
        y -= a / b * x;
    }
    return d;
}

//2n * x + px = 2m * y + py
LL solve(LL px, LL py) {
    LL a = 2 * n, b = 2 * m, c = py - px;
    LL x, y, g = exgcd(a, b, x, y);
    LL lcm = a / g * b;
    if(c % g) return 1e18;
    x *= c / g;
    LL ret = a % lcm * x % lcm + px;
    ret = (ret % lcm + lcm) % lcm;
    if(!ret) ret = lcm;
    return ret;
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d%d%d", &n, &m, &k) == 3) {
        for(int i = 1; i <= k; ++i) {
            int x, y; scanf("%d%d", &x, &y);
            LL ans = min({solve(x, y), solve(x, 2 * m - y),
                          solve(2 * n - x, y), solve(2 * n - x, 2 * m - y)
                         });
            if(ans == 1e18) ans = -1;
            printf("%I64d\n", ans);
        }
    }

    return 0;
}
