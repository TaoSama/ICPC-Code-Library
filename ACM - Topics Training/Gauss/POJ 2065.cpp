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
const int N = 70 + 10, INF = 0x3f3f3f3f;

int n, MOD;
char s[N];
int a[N][N], ans[N];
bool isFreeX[N];

int quick(int x, int n) {
    int ret = 1;
    for(; n; n >>= 1) {
        if(n & 1) ret = ret * x % MOD;
        x = x * x % MOD;
    }
    return ret;
}

inline int inv(int x) {return quick(x, MOD - 2);}

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
                int delta = a[i][c] * inv(a[r][c]) % MOD;
                for(int j = c; j <= m; ++j) {
                    a[i][j] -= delta * a[r][j] ;
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

int w(char c) {
    if(c == '*') return 0;
    return c - 'a' + 1;
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
        scanf("%d%s", &MOD, s);
        memset(a, 0, sizeof a);
        n = strlen(s);
        for(int i = 0; i < n; ++i) {
            int k = i + 1, coff = 1;
            for(int j = 0; j < n; ++j) {
                a[i][j] = coff;
                coff = coff * k % MOD;
            }
            a[i][n] = w(s[i]);
        }
        int r = gauss(n, n);
        getAns(n, n, r);

        for(int i = 0; i < n; ++i)
            printf("%d%c", ans[i], " \n"[i == n - 1]);
    }

#ifdef LOCAL
    printf("\nTime cost: %.2fs\n", 1.0 * (clock() - _) / CLOCKS_PER_SEC);
#endif
    return 0;
}
