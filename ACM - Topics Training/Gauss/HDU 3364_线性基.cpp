//
//  Created by TaoSama on 2016-07-28
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
const int N = 50 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, m;
typedef long long LL;
LL a[N];

int xorGauss(int n, int m) {
    int r = 0, c = 0;
    for(; r < n && c < m; ++r, ++c) {
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
    return r;
}

bool check(LL x, LL rnk) {
    LL mix = 0;
    int r = 0, c = 0;
    for(; r < rnk && c < m; ++c) {
        bool have = mix >> c & 1;
        bool need = x >> c & 1;
        if(have == need) continue;
        bool ok = false;
        if(need) {
            while(r < rnk && !ok) {
                if(a[r] >> c & 1) {
                    mix ^= a[r];
                    ok = true;
                }
                ++r;
            }
        }
        if(!ok) return false;
    }
    return mix == x;
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
        scanf("%d%d", &m, &n);
        for(int i = 0; i < n; ++i) {
            a[i] = 0;
            int cnt = 0; scanf("%d", &cnt);
            while(cnt--) {
                int x; scanf("%d", &x);
                a[i] |= 1LL << x - 1;
            }
        }
        int r = xorGauss(n, m);

        static int kase = 0;
        printf("Case %d:\n", ++kase);
        int q; scanf("%d", &q);
        while(q--) {
            LL target = 0;
            for(int i = 0; i < m; ++i) {
                int x; scanf("%d", &x);
                if(x) target |= 1LL << i;
            }
            LL ans = check(target, r) ? 1LL << n - r : 0;
            printf("%I64d\n", ans);
        }
    }

#ifdef LOCAL
    printf("\nTime cost: %.2fs\n", 1.0 * (clock() - _) / CLOCKS_PER_SEC);
#endif
    return 0;
}
