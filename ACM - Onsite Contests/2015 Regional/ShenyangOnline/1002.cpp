//
//  Created by TaoSama on 2015-09-20
//  Copyright (c) 2015 TaoSama. All rights reserved.
//
//#pragma comment(linker, "/STACK:1024000000,1024000000")
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
const int N = 1e5 + 10, INF = 0x3f3f3f3f;

typedef long long LL;

LL n, m, MOD;

LL mul(LL a, LL b, LL mod) {
    LL ret = 0;
    while(b) {
        if(b & 1) ret = (ret + a) % mod;
        a = (a + a) % mod;
        b >>= 1;
    }
    return ret;
}

struct Matrix {
    LL mat[2][2];
    Matrix(bool one = false) {
        memset(mat, 0, sizeof mat);
        if(!one) return;
        for(int i = 0; i < 2; ++i) mat[i][i] = 1;
    }

    Matrix operator* (const Matrix& rhs) {
        Matrix ret;
        for(int i = 0; i < 2; ++i)
            for(int j = 0; j < 2; ++j)
                for(int k = 0; k < 2; ++k)
                    ret.mat[i][j] = (ret.mat[i][j] + mul(mat[i][k], rhs.mat[k][j], MOD)) % MOD;
        return ret;
    }
    Matrix operator^ (LL n) {
        Matrix ret(1), x = *this;
        while(n) {
            if(n & 1) ret = ret * x;
            x = x * x;
            n >>= 1;
        }
        return ret;
    }
};

LL ksm(LL x, LL n, LL mod) {
    LL ret = 1;
    while(n) {
        if(n & 1) ret = mul(ret, x, mod);
        x = mul(x, x, mod);
        n >>= 1;
    }
    return ret;
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int t; scanf("%d", &t);
    int kase = 0;
    while(t--) {
        scanf("%I64d%I64d", &n, &m);
        LL two = (m * m - m) * (m * m - 1);  //二阶矩阵指数循环节(m*m-1也能A)

        n = ksm(2, n, two) + 1;

        Matrix A;
        MOD = m;
        A.mat[0][0] = 5, A.mat[0][1] = 2;
        A.mat[1][0] = 12, A.mat[1][1] = 5;
        A = A ^ n;
        LL ans = (A.mat[0][0] * 2 + m - 1) % m;
        printf("Case #%d: %I64d\n", ++kase, ans);
    }
    return 0;
}
