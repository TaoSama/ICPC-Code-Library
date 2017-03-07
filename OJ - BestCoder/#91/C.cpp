//
//  Created by TaoSama on 2017-01-21
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


struct Sta {
    long double a[3][3];
    void init() {
        memset(a, 0, sizeof a);
    }
    void one() {
        for(int i = 0; i < 3; ++i)
            for(int j = 0; j < 3; ++j)
                a[i][j] = i == j;
    }
    void see() {
        for(int i = 0; i < 3; ++i) {
            for(int j = 0; j < 3; ++j) {
                printf("%.2f ", a[i][j]);
            }
            puts("");
        }
    }
    long double* operator[](int k) {return a[k];}
};

Sta v[N << 2];

inline mul(Sta& a, Sta& b) {
    Sta c; c.init();
    for(int k = 0; k < 3; ++k)
        for(int i = 0; i < 3; ++i)
            for(int j = 0; j < 3; ++j)
                c[i][j] += b[i][k] * a[k][j];

    for(int i = 0; i < 3; ++i)
        for(int j = 0; j < 3; ++j)
            a[i][j] = c[i][j];
}

void build(int l, int r, int rt) {
    v[rt].one();
    if(l == r) return;
    int m = l + r >> 1;
    build(l, m, rt << 1);
    build(m + 1, r, rt << 1 | 1);
}

void down(int rt) {
    mul(v[rt << 1], v[rt]);
    mul(v[rt << 1 | 1], v[rt]);
    v[rt].one();
}

void update(int L, int R, Sta& val, int l, int r, int rt) {
    if(L <= l && r <= R) {
        mul(v[rt], val);
        return ;
    }

    down(rt);
    int m = l + r >> 1;
    if(L <= m) update(L, R, val, l, m, rt << 1);
    if(R > m) update(L, R, val, m + 1, r, rt << 1 | 1);
}

Sta query(int o, int l, int r, int rt) {
    if(l == r) return v[rt];

    down(rt);
    int m = l + r >> 1;
    if(o <= m) return query(o, l, m, rt << 1);
    else return query(o, m + 1, r, rt << 1 | 1);
}

int x[N], y[N];

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int t; scanf("%d", &t);
    while(t--) {
        int q; scanf("%d", &q);
        build(1, q, 1);
        int n = 0;
        for(int i = 1; i <= q; ++i) {
            char op[2]; scanf("%s", op);
            if(*op == 'I') {
                ++n;
                scanf("%d%d", x + n, y + n);
            } else if(*op == 'M') {
                int l, r, x, y;
                scanf("%d%d%d%d", &l, &r, &x, &y);
                Sta val; val.one();
                val[0][2] = x, val[1][2] = y;
                update(l, r, val, 1, q, 1);
            } else if(*op == 'R') {
                int l, r, x, y;
                scanf("%d%d%d%d", &l, &r, &x, &y);
                double a; scanf("%lf", &a);
                Sta trans; trans.one();
                trans[0][2] = -x, trans[1][2] = -y;

                Sta val; val.one();
                val[0][0] = cos(a); val[0][1] = -sin(a);
                val[1][0] = sin(a); val[1][1] = cos(a);
                mul(trans, val);

                Sta trans2; trans2.one();
                trans2[0][2] = x, trans2[1][2] = y;
                mul(trans, trans2);

                update(l, r, trans, 1, q, 1);
            } else if(*op == 'F') {
                int l, r, x, y;
                scanf("%d%d%d%d", &l, &r, &x, &y);
                double a; scanf("%lf", &a);

                Sta trans; trans.one();
                trans[0][2] = -x, trans[1][2] = -y;

                Sta val; val.init();
                val[0][0] = val[1][1] = a;
                mul(trans, val);

                Sta trans2; trans2.one();
                trans2[0][2] = x, trans2[1][2] = y;
                mul(trans, trans2);

                update(l, r, trans, 1, q, 1);
            } else {
                int id; scanf("%d", &id);
                Sta val = query(id, 1, q, 1);
//                pr(x[id]); prln(y[id]);
//                val.see();

                double xx = x[id] * val[0][0] + y[id] * val[0][1] + val[0][2];
                double yy = x[id] * val[1][0] + y[id] * val[1][1] + val[1][2];
                printf("%.0f %.0f\n", floor(xx), floor(yy));
            }
        }
    }

    return 0;
}
