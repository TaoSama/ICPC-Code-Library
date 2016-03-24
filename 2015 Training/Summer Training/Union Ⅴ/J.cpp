//
//  Created by TaoSama on 2015-08-31
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
int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

typedef long long LL;

LL n;
struct Matrix {
    int row, col;
    LL mat[3][3];
    void init(int row, int col, bool one = false){
        this->row = row; this->col = col;
        memset(mat, 0, sizeof mat);
        if(!one) return;
        for(int i = 0; i < row; ++i) mat[i][i] = 1;
    }
    Matrix operator* (const Matrix& rhs) {
        Matrix ret; ret.init(row, rhs.col);
        for(int k = 0; k < 2; ++k)
        for(int i = 0; i < 2; ++i)
            for(int j = 0; j < 2; ++j)

                    ret.mat[i][j] = (ret.mat[i][j] + mat[i][k] * rhs.mat[k][j]) % MOD;
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

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int MOD3 = 222222224, MOD2 = 183120, MOD1 = 240;
    while(scanf("%I64d", &n) == 1) {
        Matrix x, y;
        x.mat[0][0] = 3; x.mat[0][1] = 1;
        x.mat[1][0] = 1; x.mat[1][1] = 0;

        MOD = MOD2; y = x ^ (n % MOD1);
        MOD = MOD3; y = x ^ (y.mat[1][0] % MOD2);
        MOD = 1e9 + 7; y = x ^ (y.mat[1][0] % MOD3);
        printf("%I64d\n", y.mat[1][0]);
    }
    return 0;
}
