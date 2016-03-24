//
//  Created by TaoSama on 2016-01-02
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
const int N = 50 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

typedef long long LL;

struct Matrix {
    int row, col;
    LL mat[N][N];
    void init(int row, int col, bool one = false) {
        this->row = row; this->col = col;
        memset(mat, 0, sizeof mat);
        if(!one) return;
        for(int i = 1; i <= row; ++i) mat[i][i] = 1;
    }
    Matrix operator* (const Matrix& rhs) {
        Matrix ret; ret.init(row, rhs.col);
        for(int k = 1; k <= col; ++k) {
            for(int i = 1; i <= row; ++i) {
                if(mat[i][k] == 0) continue;
                for(int j = 1; j <= rhs.col; ++j) {
                    if(rhs.mat[k][j] == 0) continue;
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
        while(n) {
            if(n & 1) ret = ret * x;
            x = x * x;
            n >>= 1;
        }
        return ret;
    }
} A;

int n, m;

LL ksm(LL x, LL n) {
    LL ret = 1;
    for(; n; n >>= 1) {
        if(n & 1) ret = ret * x % MOD;
        x = x * x % MOD;
    }
    return ret;
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d%d", &n, &m) == 2) {
        A.init(n, n);
        while(m--) {
            int u, v; scanf("%d%d", &u, &v);
            A.mat[u][v] = 1;
        }
        for(int i = 1; i <= n; ++i) {
            int one = 0;
            for(int j = 1; j <= n; ++j)
                one += A.mat[i][j];
            for(int j = 1; j <= n; ++j)
                if(A.mat[i][j]) A.mat[i][j] = ksm(one, MOD - 2);
        }
        int q; scanf("%d", &q);
        while(q--) {
            int u, k; scanf("%d%d", &u, &k);
            Matrix B = A ^ k;
            for(int i = 1; i <= n; ++i)
                printf("%I64d ", B.mat[u][i]);
            puts("");
        }
    }
    return 0;
}
