//
//  Created by TaoSama on 2016-07-27
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

int n, q;
typedef long long LL;
LL a[N];

int xorGauss() {
    int r = 0, c = 63;
    for(; r < n && ~c; ++r, --c) {
        int p = r;
        for(; p < n; ++p) if(a[p] >> c & 1) break;
        if(p == n) {--r; continue;}

        swap(a[p], a[r]);
        for(int i = 0; i < n; ++i) {
            if(i != r) {
                if(a[i] >> c & 1) a[i] ^= a[r];
            }
        }
    }
    return r; //rank
}

LL kth(LL k, int r) {
    if(r != n) --k;  //
    if(k >= 1LL << r) return -1;

    LL ret = 0;
    for(int i = 0; i < 64; ++i)
        if(k >> i & 1) ret ^= a[r - i - 1];
    return ret;
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
        scanf("%d", &n);
        for(int i = 0; i < n; ++i) scanf("%I64d", a + i);

        int r = xorGauss();

        static int kase = 0;
        printf("Case #%d:\n", ++kase);

        scanf("%d", &q);
        while(q--) {
            LL k; scanf("%I64d", &k);
            printf("%I64d\n", kth(k, r));
        }
    }

#ifdef LOCAL
    printf("\nTime cost: %.2fs\n", 1.0 * (clock() - _) / CLOCKS_PER_SEC);
#endif
    return 0;
}
