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
const int N = 20 + 10, INF = 0x3f3f3f3f, MOD = 2;


int n = 20;
int a[N][N], ans[N];
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

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);
    clock_t _ = clock();

    int tmp[20];
    for(int i = 0; i < n; ++i) {
        scanf("%d", a[i] + n);
        tmp[i] = a[i][n];
        a[i][n] = -a[i][n] + MOD;
    }

    for(int i = 0; i < n; ++i) {
        for(int j = -1; j <= 1; ++j) {
            int x = i + j;
            if(x < 0 || x >= n) continue;
            a[i][x] = 1;
        }
    }

    int r = gauss(n, n);
    int minv = getMinAns(n, n, r);
    printf("%d\n", minv);

//    for(int i = 0; i < n; ++i) {
//        if(ans[i]) {
//            printf("%d ", i + 1);
//            for(int j = -1; j <= 1; ++j) {
//                int x = i + j;
//                if(x < 0 || x >= n) continue;
//                tmp[x] ^= 1;
//            }
//        }
//    }
//    puts("");
//    if(count(tmp, tmp + 20, 1)) puts("WA");
//    else puts("AC");


#ifdef LOCAL
    printf("\nTime cost: %.2fs\n", 1.0 * (clock() - _) / CLOCKS_PER_SEC);
#endif
    return 0;
}
