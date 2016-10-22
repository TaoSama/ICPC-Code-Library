//
//  Created by TaoSama on 2016-09-18
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

typedef long long LL;
LL MOD;

//remember to call "init" first
struct Matrix {
    int row, col;
    static const int N = 55;
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

LL phi(LL x) {
    LL ret = x;
    for(int i = 2; i * i <= x; ++i) {
        if(x % i == 0) {
            ret = ret / i * (i - 1);
            while(x % i == 0) x /= i;
        }
    }
    if(x > 1) ret = ret / x * (x - 1);
    return ret;
}

LL quick(LL x, LL n, LL m) {
    LL ret = 1;
    for(; n; n >>= 1) {
        if(n & 1) ret = ret * x % m;
        x = x * x % m;
    }
    return ret;
}

LL n, y, x, s;

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    Matrix A; A.init(4, 4);
    int xx = 2, yy = 1;
    int a[4][4] = {{1, 0, 0, 0}, {1, xx * xx, 1, xx},
        {0, yy * yy, 0, 0}, {0, 2 * xx * yy, 0, yy}
    };
    for(int i = 0; i < 4; ++i)
        for(int j = 0; j < 4; ++j)
            A.mat[i][j] = a[i][j];


    int t; cin >> t;
    while(t--) {
        cin >> n >> y >> x >> s;
        if(x % (s + 1) == 0) {
            cout << "0\n";
            continue;
        }

        n *= y;
        MOD = phi(s + 1);


        Matrix ans; ans.init(1, 4);
        int b[4] = {0, 1, 0, 0};
        for(int i = 0; i < 4; ++i)
            ans.mat[0][i] = b[i];

        Matrix B = A;
        ans = ans * (B ^ n);
        LL e = ans.mat[0][0];
        e += MOD;

        LL res = quick(x, e, s + 1);
        cout << res << endl;
    }

    return 0;
}
