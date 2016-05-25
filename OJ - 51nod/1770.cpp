//
//  Created by TaoSama on 2016-05-20
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

int a, b, d, n;

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//    freopen("C:\\Users\\TaoSama\\Desktop\\out.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    clock_t _ = clock();


//    for(int j = 1; j < 10; ++j) {
//        long long t = 0;
//        for(int k = 1; k <= 10; ++k) t = t * 10 + j;
//        for(int k = 1; k < 10; ++k) {
//            printf("%lld * %d = %lld\n", t, k, t * k);
//        }
//    }

    int t; scanf("%d", &t);
    while(t--) {
        scanf("%d%d%d%d", &a, &b, &d, &n);
        int c[10] = {};
        int x = 0;
        for(int i = 1; i <= 5 && i <= n; ++i) x = x * 10 + a;
        x *= b;
        char buf[10]; sprintf(buf, "%d", x);
        for(int i = 0; buf[i]; ++i) ++c[buf[i] - '0'];
        int lft = max(0, n - 5);
        c[buf[1] - '0'] += lft;
        printf("%d\n", c[d]);
    }

#ifdef LOCAL
    printf("\nTime cost: %.2fs\n", 1.0 * (clock() - _) / CLOCKS_PER_SEC);
#endif
    return 0;
}
