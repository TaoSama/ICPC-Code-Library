//
//  Created by TaoSama on 2015-10-08
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
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

typedef long long LL;

LL n;

struct Matrix {
    int row, col;
    LL mat[3][3];
    void init(int row, int col, bool one = false) {
        this->row = row; this->col = col;
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
                    ret.mat[i][j] = (ret.mat[i][j] + mat[i][k] * rhs.mat[k][j]) % MOD;
                }
            }
        }
        return ret;
    }
    Matrix operator^ (LL n) {
        Matrix ret, x = *this;
        ret.init(this->row, this->col, 1);
        while(n) {
            if(n & 1) ret = ret * x;
            x = x * x;
            n >>= 1;
        }
        return ret;
    }
};

Matrix p[61];

void init() {
    /*
    0 -1 0
    1  6 1
    0  0 1
    */
    p[0].init(3, 3);
    p[0].mat[0][1] = -1;
    p[0].mat[1][0] = 1;
    p[0].mat[1][1] = 6;
    p[0].mat[1][2] = 1;
    p[0].mat[2][2] = 1;

    for(int i = 1; i <= 60; ++i) p[i] = p[i - 1] * p[i - 1];
}

Matrix ans;

void gao(LL n) {
    ans.init(1, 3);
    ans.mat[0][0] = 6;
    ans.mat[0][1] = 35;
    ans.mat[0][2] = 6;
    for(int i = 0; n; ++i, n >>= 1)
        if(n & 1) ans = ans * p[i];
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int t; scanf("%d", &t);
    init();
    while(t--) {
        scanf("%I64d", &n);
        gao(n - 1);
        printf("%I64d\n", ans.mat[0][2]);
    }
    return 0;
}
