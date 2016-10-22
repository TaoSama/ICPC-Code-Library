//
//  Created by TaoSama on 2016-07-15
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

LL exgcd(LL a, LL b, LL& x, LL& y) {
    LL g = a;
    if(!b) x = 1, y = 0;
    else {
        g = exgcd(b, a % b, y, x);
        y -= a / b * x;
    }
    return g;
}

LL get(LL a, LL b, LL c) {
    LL x, y, g = exgcd(a, b, x, y);
    if(c % g) return -1;
    x *= c / g;
    x = (x % (b / g) + b / g) % (b / g);
    if(!x) x = b / g;
    return x;
}

int firstA[N], firstB[N];

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);
    clock_t _ = clock();

    int t; scanf("%d", &t);
    while(t--) {
        int n, d, r; scanf("%d%d%d", &n, &d, &r);
        d %= n; r %= n;
//        LL ans = 1e18;
//        for(int i = 0; i < n; ++i) {
//            //d*x+y*n=i
//            LL a = get(d, n, i);
//            if(a == -1) continue;
//            LL b = get(r, n, i);
//            if(b == -1) continue;
//
//            printf("%d: %I64d %I64d\n", i, a, b);
//            ans = min(ans, max(a, b));
//        }
//        printf("%I64d\n", ans);

        memset(firstA, 0, n << 2);
        memset(firstB, 0, n << 2);
        int ans = 1;
        while(true) {
            int a = 1LL * d * ans % n;
            int b = 1LL * r * ans % n;
            if(!firstA[a]) firstA[a] = ans;
            if(!firstB[b]) firstB[b] = ans;

            if(firstB[a] || firstA[b]) break;

            ++ans;
        }
        printf("%d\n", ans);
    }

#ifdef LOCAL
    printf("\nTime cost: %.2fs\n", 1.0 * (clock() - _) / CLOCKS_PER_SEC);
#endif
    return 0;
}
