//
//  Created by TaoSama on 2016-10-05
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
const int N = 1e5 + 10, INF = 0x3f3f3f3f;
int MOD = 20160519;

typedef long long LL;

//remember to call "init" first
struct Matrix {
    int row, col;
    static const int N = 2;
    LL mat[N][N];
    void init(int r, int c, bool one = false) {
        row = r; col = c;
        memset(mat, 0, sizeof mat);
        if(!one) return;
        for(int i = 0; i < row; ++i) mat[i][i] = 1;
    }
    void see() {
        printf("%d %d\n", row, col);
        for(int i = 0; i < row; ++i)
            for(int j = 0; j < col; ++j)
                printf("%I64d%c", mat[i][j], " \n"[j + 1 == col]);
    }
    Matrix operator+(const Matrix& rhs) {
        Matrix ret = *this;
        for(int i = 0; i < row; ++i)
            for(int j = 0; j < col; ++j)
                if((ret.mat[i][j] += rhs.mat[i][j]) >= MOD)
                    ret.mat[i][j] -= MOD;
        return ret;
    }
    Matrix operator* (const Matrix& rhs) {
        Matrix ret; ret.init(row, rhs.col);
        for(int k = 0; k < col; ++k) {
            for(int i = 0; i < row; ++i) {
                if(mat[i][k] == 0) continue;
                for(int j = 0; j < rhs.col; ++j) {
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


int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

//    int f0 = 0, f1 = 1;
//    for(int i = 2; i <= 10; ++i) {
//        int f2 = f0 + f1;
//        f2 %= MOD;
//        printf("%d\n", f2);
//        if(f1 == 0 && f2 == 1) {
//            printf("cycle = %d\n", i - 1);
//        }
//        f0 = f1;
//        f1 = f2;
//    }

    const int CYCLE = 26880696;

    int fibo[] = {0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89};

    Matrix A; A.init(2, 2);
    LL a[] = {1, 1, 1, 0};
    memcpy(A.mat, a, sizeof a);

    int t; scanf("%d", &t);
    while(t--) {
        int n; scanf("%d", &n);
        MOD = CYCLE;
        Matrix in = A ^ n;
        LL idx = in.mat[1][0];
//        prln(idx);

        MOD = 20160519;
        Matrix ans = A ^ idx;
        printf("%lld\n", ans.mat[1][0]);
    }

    return 0;
}
