//
//  Created by TaoSama on 2016-09-23
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
    inline Matrix operator+(const Matrix& rhs) {
        Matrix ret = *this;
        for(int i = 0; i < row; ++i)
            for(int j = 0; j < col; ++j)
                if((ret.mat[i][j] += rhs.mat[i][j]) >= MOD)
                    ret.mat[i][j] -= MOD;
        return ret;
    }
    inline Matrix operator* (const Matrix& rhs) {
        Matrix ret; ret.init(row, rhs.col);
        for(int k = 0; k < col; ++k) {
            for(int i = 0; i < row; ++i) {
                if(mat[i][k] == 0) continue;
                for(int j = 0; j < rhs.col; ++j) {
                    ret.mat[i][j] += 1LL * mat[i][k] * rhs.mat[k][j] % MOD;
                    if(ret.mat[i][j] >= MOD) ret.mat[i][j] -= MOD;
                }
            }
        }
        return ret;
    }
    inline Matrix operator^ (LL n) {
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


Matrix dat[N << 2], mul[N << 2], A;
bool lazy[N << 2];

inline void up(int rt) {
    dat[rt] = dat[rt << 1] + dat[rt << 1 | 1];
}

void build(int l, int r, int rt) {
    lazy[rt] = 0;
    mul[rt].init(2, 2, true);
    if(l == r) {
        int x; scanf("%d", &x);
        dat[rt] = A ^ x;
        return ;
    }
    int m = l + r >> 1;
    build(l, m, rt << 1);
    build(m + 1, r, rt << 1 | 1);
    up(rt);
}

inline void down(int rt) {
    if(lazy[rt]) {

        Matrix& x = mul[rt];
        mul[rt << 1] = mul[rt << 1] * x;
        mul[rt << 1 | 1] = mul[rt << 1 | 1] * x;
        dat[rt << 1] = dat[rt << 1] * x;
        dat[rt << 1 | 1] = dat[rt << 1 | 1] * x;

        lazy[rt << 1] = lazy[rt << 1 | 1] = true;
        lazy[rt] = 0;
        x.init(2, 2, true);
    }
}

void update(int L, int R, Matrix v, int l, int r, int rt) {
    if(L <= l && r <= R) {
        lazy[rt] = true;
        mul[rt] = mul[rt] * v;
        dat[rt] = dat[rt] * v;
        return;
    }
    down(rt);
    int m = l + r >> 1;
    if(L <= m) update(L, R, v, l, m, rt << 1);
    if(R > m) update(L, R, v, m + 1, r, rt << 1 | 1);
    up(rt);
}

LL query(int L, int R, int l, int r, int rt) {
    if(L <= l && r <= R) return dat[rt].mat[1][0];
    down(rt);
    int m = l + r >> 1;
    LL ret = 0;
    if(L <= m) ret += query(L, R, l, m, rt << 1);
    if(R > m) ret += query(L, R, m + 1, r, rt << 1 | 1);
    return ret;
}

int n, q;

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    A.init(2, 2);
    int a[2][2] = {1, 1, 1, 0};
    for(int i = 0; i < 2; ++i)
        for(int j = 0; j < 2; ++j)
            A.mat[i][j] = a[i][j];

    scanf("%d%d", &n, &q);
    build(1, n, 1);
    while(q--) {
        int op, l, r, v; scanf("%d%d%d", &op, &l, &r);
        if(op == 1) {
            scanf("%d", &v);
            update(l, r, A ^ v, 1, n, 1);
        } else {
            printf("%I64d\n", query(l, r, 1, n, 1) % MOD);
        }
    }

    return 0;
}
