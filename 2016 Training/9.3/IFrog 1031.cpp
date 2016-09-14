//
//  Created by TaoSama on 2016-09-03
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

//remember to call "init" first
struct Matrix {
    int row, col;
    static const int N = 55;
    LL mat[N][N];
    void init(int r, int c, bool one = false) {
        row = r; col = c;
        memset(mat, 0, sizeof mat);
        if(!one) return;
        for(int i = 1; i <= row; ++i) mat[i][i] = 1;
    }
    void see() {
        printf("%d %d\n", row, col);
        for(int i = 1; i <= row; ++i)
            for(int j = 1; j <= col; ++j)
                printf("%I64d%c", mat[i][j], " \n"[j == col]);
    }
    Matrix operator+(const Matrix& rhs) {
        Matrix ret = *this;
        for(int i = 1; i <= row; ++i)
            for(int j = 1; j <= col; ++j)
                if((ret.mat[i][j] += rhs.mat[i][j]) >= MOD)
                    ret.mat[i][j] -= MOD;
        return ret;
    }
    Matrix operator* (const Matrix& rhs) {
        Matrix ret; ret.init(row, rhs.col);
        for(int k = 1; k <= col; ++k) {
            for(int i = 1; i <= row; ++i) {
                if(mat[i][k] == 0) continue;
                for(int j = 1; j <= rhs.col; ++j) {
                    ret.mat[i][j] += mat[i][k] * rhs.mat[k][j] % MOD;
                    ret.mat[i][j] %= MOD;
                }
            }
        }
        return ret;
    }
    Matrix operator^ (LL n) {
        Matrix ret, x = *this;
        ret.init(row, col, 1);
        for(; n; n >>= 1) {
            if(n & 1) ret = ret * x;
            x = x * x;
        }
        return ret;
    }
    Matrix prefix(LL n) {
        Matrix ret, x = *this, t = *this;
        ret.init(row, col);
        for(; n; n >>= 1) {
            if(n & 1) ret = ret * x + t;
            t = t * x + t;
            x = x * x;
        }
        return ret;
    }
};

int f[10][2][2];

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    Matrix A; A.init(4, 4);
    int trans[5][5] = {{}, {0, 4, 1, 1, 0}, {0, 1, 4, 0, 1},
        {0, 1, 0, 4, 1}, {0, 0, 1, 1, 4}
    };
    for(int i = 1; i <= 4; ++i)
        for(int j = 1; j <= 4; ++j)
            A.mat[i][j] = trans[i][j];

    int t; scanf("%d", &t);
    while(t--) {
        LL k; scanf("%lld", &k);
//        f[0][0][0] = 1;
//        for(int i = 1; i <= k; ++i) {
//            f[i][0][0] = f[i - 1][1][0] + f[i - 1][0][1] + 4 * f[i - 1][0][0];
//            f[i][0][1] = f[i - 1][0][0] + f[i - 1][1][1] + 4 * f[i - 1][0][1];
//            f[i][1][0] = f[i - 1][0][0] + f[i - 1][1][1] + 4 * f[i - 1][1][0];
//            f[i][1][1] = f[i - 1][1][0] + f[i - 1][0][1] + 4 * f[i - 1][1][1];
//        }
//        int ans = f[k][0][0];
//        printf("%d\n", ans);

        Matrix ans; ans.init(1, 4);
        ans.mat[1][1] = 1;
        ans = ans * (A ^ k);

        static int kase = 0;
        printf("Case #%d: %lld\n", ++kase, ans.mat[1][1]);
    }

    return 0;
}
