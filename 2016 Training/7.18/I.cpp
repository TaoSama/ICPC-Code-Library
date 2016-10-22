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

int n, k, a[N];

int f[N];
int calc(int x) {
    memset(f, 0x3f, sizeof f);
    f[0] = 0;
    for(int i = 1; i <= n; ++i) {
        int p = upper_bound(a + i, a + 1 + n, a[i] + x - 1) - a - 1;
//        printf("in %d: %d\n", i, p);
        f[p] = min(f[p], f[i - 1] + 1); //[i, p]
    }
//    printf("%d: %d\n", x, f[n]);
    return f[n];
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);
    clock_t _ = clock();

    int t; scanf("%d", &t);
    while(t--) {
        scanf("%d%d", &n, &k);
        for(int i = 1; i <= n; ++i) scanf("%d", a + i);
        int l = 1, r = 1e9 + 10, ans = -1;
//        prln(calc(5));
        while(l <= r) {
            int m = l + r >> 1;
            if(calc(m) <= k) ans = m, r = m - 1;
            else l = m + 1;
        }
        printf("%d\n", ans);
    }

#ifdef LOCAL
    printf("\nTime cost: %.2fs\n", 1.0 * (clock() - _) / CLOCKS_PER_SEC);
#endif
    return 0;
}
