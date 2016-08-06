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
const int N = 16 + 10, INF = 0x3f3f3f3f, MOD = 2;

int n = 4;
int a[N][N], b[N][N], ans[N];
bool isFreeX[N];

inline int inv(int x) {return 1;}

int getAns(int n, int m, int r) {
    int ret = 0;
    for(int i = r - 1; ~i; --i) {
        for(int j = 0; j < m; ++j) {
            if(!a[i][j]) continue;
            ans[j] = a[i][m];
            for(int k = j + 1; k < m; ++k) {
                ans[j] -= a[i][k] * ans[k];
                ans[j] %= MOD;
                if(ans[j] < 0) ans[j] += MOD;
            }
            ans[j] = ans[j] * inv(a[i][j]) % MOD;
            break;
        }
    }
    for(int i = 0; i < m; ++i) ret += ans[i];
    return ret;
}

int gauss(int n, int m) {
    for(int i = 0; i < m; ++i) isFreeX[i] = false;
    int r = 0, c = 0;
    for(; r < n && c < m; ++r, ++c) {
        int maxR = r;       //row transform
        for(int i = r + 1; i < n; ++i)
            if(abs(a[i][c]) > abs(a[maxR][c])) maxR = i;
        if(maxR != r) swap(a[maxR], a[r]);

        if(!a[r][c]) { --r; isFreeX[c] = true; continue;}

        //eliminate coefficient
        for(int i = r + 1; i < n; ++i) {
            if(a[i][c]) {
                int delta = a[i][c] * inv(a[r][c]);
                for(int j = c; j <= m; ++j) {
                    a[i][j] -= delta * a[r][j];
                    a[i][j] %= MOD;
                    if(a[i][j] < 0) a[i][j] += MOD;
                }
            }
        }
    }
    for(int i = r; i < n; i++) if(a[i][m]) return -1;

    //at last, r is rank, m - r is the number of freeX
    return r;
}

int getMinAns(int n, int m, int r) {
    int ret = INF, freeX = m - r;
    for(int s = 0; s < 1 << freeX; ++s) {
        if(__builtin_popcount(s) >= ret) continue;
        int cnt = 0;
        for(int j = 0; j < m; ++j) {
            if(isFreeX[j]) {
                ans[j] = s >> cnt & 1;
                ++cnt;
            }
        }
        ret = min(ret, getAns(n, m, r));
    }
    return ret;
}

inline int ID(int x, int y) {
    return x * n + y;
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);
    clock_t _ = clock();

    for(int i = 0; i < n; ++i) {
        char buf[20]; scanf("%s", buf);
        for(int j = 0; j < n; ++j) {
            a[ID(i, j)][n * n] = -(buf[j] == 'b') + MOD;
            b[ID(i, j)][n * n] = -(buf[j] == 'w') + MOD;
            static int d[][2] = { -1, 0, 0, -1, 1, 0, 0, 1, 0, 0};
            for(int k = 0; k < 5; ++k) {
                int x = i + d[k][0], y = j + d[k][1];
                if(x < 0 || x >= n || y < 0 || y >= n) continue;
                a[ID(i, j)][ID(x, y)] = 1;
                b[ID(i, j)][ID(x, y)] = 1;
            }
        }
    }

    int minv = INF, r;
    r = gauss(n * n, n * n);
    if(~r) minv = min(minv, getMinAns(n * n, n * n, r));

    memcpy(a, b, sizeof b);
    r = gauss(n * n, n * n);
    if(~r) minv = min(minv, getMinAns(n * n, n * n, r));

    if(minv == INF) puts("Impossible");
    else printf("%d\n", minv);

#ifdef LOCAL
    printf("\nTime cost: %.2fs\n", 1.0 * (clock() - _) / CLOCKS_PER_SEC);
#endif
    return 0;
}
