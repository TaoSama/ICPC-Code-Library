//
//  Created by TaoSama on 2017-04-09
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
#define pr(x) cerr << #x << " = " << x << "  "
#define prln(x) cerr << #x << " = " << x << endl
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

typedef long long LL;

// !!! remember to call "init" first
struct Matrix {
    int row, col;
    static const int N = 64;
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
        for(int i = 0; i < row; ++i) {
            for(int k = 0; k < col; ++k) {
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
};

int a[8] = {2, 1, -1, -2, -2, -1, 1, 2};
int b[8] = {1, 2, 2, 1, -1, -2, -2, -1};

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int n, r, c; cin >> n >> r >> c; --r; --c;
    LL t[64][64] = {};
    for(int i = 0; i < 64; ++i) {
        int x = i / 8, y = i % 8;
        for(int k = 0; k < 8; ++k) {
            int nx = x + a[k], ny = y + b[k];
            if(nx < 0 || nx >= 8 || ny < 0 || ny >= 8) continue;
            int j = nx * 8 + ny;
            t[i][j] = 1;
        }
    }

    Matrix A; A.init(64, 64);
    memcpy(A.mat, t, sizeof t);

    Matrix S; S.init(1, 64);
    S.mat[0][r * 8 + c] = 1;
    S = S * (A ^ n);

    LL ans = 0;
    for(int i = 0; i < 64; ++i) ans = (ans + S.mat[0][i]) % MOD;
    cout << ans << endl;

    return 0;
}
