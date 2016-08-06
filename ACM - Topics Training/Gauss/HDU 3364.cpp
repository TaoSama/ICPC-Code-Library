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
int a[N][N], b[N][N];

int xorGauss(int n, int m) {
    int r = 0, c = 0;
    for(; r < n && c < m; ++r, ++c) {
        int p = r;
        for(; p < n; ++p) if(a[p][c]) break;
        if(p == n) {--r; continue;}
        swap(a[p], a[r]);

        for(int i = 0; i < n; ++i) {
            if(i != r && a[i][c]) {
                for(int j = c; j <= m; ++j)
                    a[i][j] ^= a[r][j];
            }
        }
    }
    for(int i = r; i < n; ++i) if(a[i][m]) return -1;

    return m - r;
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
        scanf("%d%d", &n, &m);
        memset(b, 0, sizeof b);
        for(int j = 0; j < m; ++j) {
            int k; scanf("%d", &k);
            while(k--) {
                int x; scanf("%d", &x);
                --x;
                b[x][j] = 1;
            }
        }

        static int kase = 0;
        printf("Case %d:\n", ++kase);
        int q; scanf("%d", &q);
        while(q--) {
            memcpy(a, b, sizeof b);
            for(int i = 0; i < n; ++i) scanf("%d", a[i] + m);
            int freeX = xorGauss(n, m);
            long long tot = ~freeX ? 1LL << freeX : 0;
            printf("%I64d\n", tot);
        }
    }

#ifdef LOCAL
    printf("\nTime cost: %.2fs\n", 1.0 * (clock() - _) / CLOCKS_PER_SEC);
#endif
    return 0;
}
