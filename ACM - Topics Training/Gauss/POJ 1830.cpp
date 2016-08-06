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
const int N = 30 + 10, INF = 0x3f3f3f3f, MOD = 2;

int n;
int a[N][N], ans[N];
bool freeX[N];

inline int inv(int x) {
    return 1;
}

int gauss(int n, int m) {
    for(int i = 0; i < m; ++i) freeX[i] = false;
    //enumerate x_i
    int r = 0, c = 0;
    for(; r < n && c < m; ++r, ++c) {
        int maxR = r;       //row transform
        for(int i = r + 1; i < n; ++i)
            if(abs(a[i][c]) > abs(a[maxR][c])) maxR = i;
        if(maxR != r) swap(a[maxR], a[r]);

        if(!a[r][c]) { --r; freeX[c] = true; continue;}

        //eliminate coefficient
        for(int i = 0; i < n; ++i) {
            if(i != r && a[i][c]) {
                int delta = a[i][c] * inv(a[r][c]);
                for(int j = c; j <= m; ++j) {
                    a[i][j] -= delta * a[r][j];
                    a[i][j] %= MOD;
                    if(a[i][j] < 0) a[i][j] += MOD;
                }
            }
        }
    }
    //no answer
    for(int i = r; i < n; ++i) if(a[i][m]) return -1;

    //at last, r is rank, m - r is the number of freeX
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
        scanf("%d", &n);

        memset(a, 0, sizeof a);
        for(int i = 0; i < n; ++i) {
            scanf("%d", a[i] + n);
            a[i][i] = 1;
        }
        for(int i = 0; i < n; ++i) {
            int x; scanf("%d", &x);
            a[i][n] = (x - a[i][n] + MOD) % MOD;
        }

        int u, v;
        while(scanf("%d%d", &u, &v) == 2 && (u || v)) a[v - 1][u - 1] = 1;

        int freeX = gauss(n, n);
        if(~freeX) printf("%d\n", 1 << freeX);
        else puts("Oh,it's impossible~!!");
    }

#ifdef LOCAL
    printf("\nTime cost: %.2fs\n", 1.0 * (clock() - _) / CLOCKS_PER_SEC);
#endif
    return 0;
}
