//
//  Created by TaoSama on 2016-04-16
//  Copyright (c) 2016 TaoSama. All rights reserved.
//
#pragma comment(linker, "/STACK:102400000,102400000")
#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
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
const int N = 5, INF = 0x3f3f3f3f;

typedef long long LL;

LL MOD;

LL ksm(LL x, LL n, LL MOD) {
    LL ret = 1;
    for(; n; n >>= 1) {
        if(n & 1) ret = ret * x % MOD;
        x = x * x % MOD;
    }
    return ret;
}

//remember to call "init" first
struct Matrix {
    int row, col;
    LL mat[N][N];
    void init(int r, int c, bool one = false) {
        row = r; col = c;
        memset(mat, 0, sizeof mat);
        if(!one) return;
        for(int i = 0; i < row; ++i) mat[i][i] = 1;
    }
    Matrix operator* (const Matrix& rhs) {
        Matrix ret; ret.init(row, rhs.col);
        for(int k = 0; k < col; ++k) {
            for(int i = 0; i < row; ++i) {
                if(mat[i][k] == 0) continue;
                for(int j = 0; j < rhs.col; ++j) {
                    if(rhs.mat[k][j] == 0) continue;
                    ret.mat[i][j] = (ret.mat[i][j] + mat[i][k] * rhs.mat[k][j] % MOD) % MOD;
                }
            }
        }
        return ret;
    }
    Matrix operator^ (LL n) {
        Matrix ret, x = *this;
        ret.init(row, col, 1);
        while(n) {
            if(n & 1) ret = ret * x;
            x = x * x;
            n >>= 1;
        }
        return ret;
    }
};

LL n, a, b, c;

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int t; cin >> t;
    while(t--) {
        cin >> n >> a >> b >> c >> MOD;
        if(a % MOD == 0) {cout << "0\n"; continue;}
        if(n == 1) {cout << "1\n"; continue;}

        //f(1) f(2) b = f(2) f(1)+cf(2)+b b

        --MOD;
        Matrix A; A.init(1, 3);
        A.mat[0][1] = A.mat[0][2] = b;
        Matrix B; B.init(3, 3);
        /*  0 1 0
            1 c 0
            0 1 1
        */
        B.mat[0][1] = B.mat[1][0] = B.mat[2][1] = B.mat[2][2] = 1;
        B.mat[1][1] = c;

        A = A * (B ^ n - 1);
        LL e = A.mat[0][0] + MOD;
//      prln(A.mat[0][0]);
        LL ans = ksm(a, e, MOD + 1);
        cout << ans << '\n';
    }
    return 0;
}
