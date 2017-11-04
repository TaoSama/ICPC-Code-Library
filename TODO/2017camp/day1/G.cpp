//
//  Created by TaoSama on 2017-02-13
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

int n, l, mod;

struct Matrix {
    static const int N = 5;
    int a[N][N];
    Matrix() {
        memset(a, 0, sizeof a);
    }
    inline void setOne() {
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < n; ++j) a[i][j] = i == j;
    }
    void read() {
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < n; ++j)
                scanf("%d", a[i] + j);
    }
    void see() {
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < n; ++j)
                printf("%d%c", a[i][j], " \n"[j + 1 == n]);
    }
    inline int* operator[](int k) {return a[k];}
    inline Matrix operator*(Matrix& m) {
        Matrix ret;
        if(n == 1) {
            ret[0][0] = (1LL * a[0][0] * m[0][0]) % mod;
        } else if(n == 2) {
            ret[0][0] = (1LL * a[0][0] * m[0][0] + 1LL * a[0][1] * m[1][0]) % mod;
            ret[0][1] = (1LL * a[0][0] * m[0][1] + 1LL * a[0][1] * m[1][1]) % mod;
            ret[1][0] = (1LL * a[1][0] * m[0][0] + 1LL * a[1][1] * m[1][0]) % mod;
            ret[1][1] = (1LL * a[1][0] * m[0][1] + 1LL * a[1][1] * m[1][1]) % mod;
        } else if(n == 3) {
            ret[0][0] = (1LL * a[0][0] * m[0][0] + 1LL * a[0][1] * m[1][0] + 1LL * a[0][2] * m[2][0]) % mod;
            ret[0][1] = (1LL * a[0][0] * m[0][1] + 1LL * a[0][1] * m[1][1] + 1LL * a[0][2] * m[2][1]) % mod;
            ret[0][2] = (1LL * a[0][0] * m[0][2] + 1LL * a[0][1] * m[1][2] + 1LL * a[0][2] * m[2][2]) % mod;
            ret[1][0] = (1LL * a[1][0] * m[0][0] + 1LL * a[1][1] * m[1][0] + 1LL * a[1][2] * m[2][0]) % mod;
            ret[1][1] = (1LL * a[1][0] * m[0][1] + 1LL * a[1][1] * m[1][1] + 1LL * a[1][2] * m[2][1]) % mod;
            ret[1][2] = (1LL * a[1][0] * m[0][2] + 1LL * a[1][1] * m[1][2] + 1LL * a[1][2] * m[2][2]) % mod;
            ret[2][0] = (1LL * a[2][0] * m[0][0] + 1LL * a[2][1] * m[1][0] + 1LL * a[2][2] * m[2][0]) % mod;
            ret[2][1] = (1LL * a[2][0] * m[0][1] + 1LL * a[2][1] * m[1][1] + 1LL * a[2][2] * m[2][1]) % mod;
            ret[2][2] = (1LL * a[2][0] * m[0][2] + 1LL * a[2][1] * m[1][2] + 1LL * a[2][2] * m[2][2]) % mod;
        } else if(n == 4) {
            ret[0][0] = (1LL * a[0][0] * m[0][0] + 1LL * a[0][1] * m[1][0] + 1LL * a[0][2] * m[2][0] + 1LL * a[0][3] * m[3][0]) % mod;
            ret[0][1] = (1LL * a[0][0] * m[0][1] + 1LL * a[0][1] * m[1][1] + 1LL * a[0][2] * m[2][1] + 1LL * a[0][3] * m[3][1]) % mod;
            ret[0][2] = (1LL * a[0][0] * m[0][2] + 1LL * a[0][1] * m[1][2] + 1LL * a[0][2] * m[2][2] + 1LL * a[0][3] * m[3][2]) % mod;
            ret[0][3] = (1LL * a[0][0] * m[0][3] + 1LL * a[0][1] * m[1][3] + 1LL * a[0][2] * m[2][3] + 1LL * a[0][3] * m[3][3]) % mod;
            ret[1][0] = (1LL * a[1][0] * m[0][0] + 1LL * a[1][1] * m[1][0] + 1LL * a[1][2] * m[2][0] + 1LL * a[1][3] * m[3][0]) % mod;
            ret[1][1] = (1LL * a[1][0] * m[0][1] + 1LL * a[1][1] * m[1][1] + 1LL * a[1][2] * m[2][1] + 1LL * a[1][3] * m[3][1]) % mod;
            ret[1][2] = (1LL * a[1][0] * m[0][2] + 1LL * a[1][1] * m[1][2] + 1LL * a[1][2] * m[2][2] + 1LL * a[1][3] * m[3][2]) % mod;
            ret[1][3] = (1LL * a[1][0] * m[0][3] + 1LL * a[1][1] * m[1][3] + 1LL * a[1][2] * m[2][3] + 1LL * a[1][3] * m[3][3]) % mod;
            ret[2][0] = (1LL * a[2][0] * m[0][0] + 1LL * a[2][1] * m[1][0] + 1LL * a[2][2] * m[2][0] + 1LL * a[2][3] * m[3][0]) % mod;
            ret[2][1] = (1LL * a[2][0] * m[0][1] + 1LL * a[2][1] * m[1][1] + 1LL * a[2][2] * m[2][1] + 1LL * a[2][3] * m[3][1]) % mod;
            ret[2][2] = (1LL * a[2][0] * m[0][2] + 1LL * a[2][1] * m[1][2] + 1LL * a[2][2] * m[2][2] + 1LL * a[2][3] * m[3][2]) % mod;
            ret[2][3] = (1LL * a[2][0] * m[0][3] + 1LL * a[2][1] * m[1][3] + 1LL * a[2][2] * m[2][3] + 1LL * a[2][3] * m[3][3]) % mod;
            ret[3][0] = (1LL * a[3][0] * m[0][0] + 1LL * a[3][1] * m[1][0] + 1LL * a[3][2] * m[2][0] + 1LL * a[3][3] * m[3][0]) % mod;
            ret[3][1] = (1LL * a[3][0] * m[0][1] + 1LL * a[3][1] * m[1][1] + 1LL * a[3][2] * m[2][1] + 1LL * a[3][3] * m[3][1]) % mod;
            ret[3][2] = (1LL * a[3][0] * m[0][2] + 1LL * a[3][1] * m[1][2] + 1LL * a[3][2] * m[2][2] + 1LL * a[3][3] * m[3][2]) % mod;
            ret[3][3] = (1LL * a[3][0] * m[0][3] + 1LL * a[3][1] * m[1][3] + 1LL * a[3][2] * m[2][3] + 1LL * a[3][3] * m[3][3]) % mod;
        } else if(n == 5) {
            ret[0][0] = (1LL * a[0][0] * m[0][0] + 1LL * a[0][1] * m[1][0] + 1LL * a[0][2] * m[2][0] + 1LL * a[0][3] * m[3][0] + 1LL * a[0][4] * m[4][0]) % mod;
            ret[0][1] = (1LL * a[0][0] * m[0][1] + 1LL * a[0][1] * m[1][1] + 1LL * a[0][2] * m[2][1] + 1LL * a[0][3] * m[3][1] + 1LL * a[0][4] * m[4][1]) % mod;
            ret[0][2] = (1LL * a[0][0] * m[0][2] + 1LL * a[0][1] * m[1][2] + 1LL * a[0][2] * m[2][2] + 1LL * a[0][3] * m[3][2] + 1LL * a[0][4] * m[4][2]) % mod;
            ret[0][3] = (1LL * a[0][0] * m[0][3] + 1LL * a[0][1] * m[1][3] + 1LL * a[0][2] * m[2][3] + 1LL * a[0][3] * m[3][3] + 1LL * a[0][4] * m[4][3]) % mod;
            ret[0][4] = (1LL * a[0][0] * m[0][4] + 1LL * a[0][1] * m[1][4] + 1LL * a[0][2] * m[2][4] + 1LL * a[0][3] * m[3][4] + 1LL * a[0][4] * m[4][4]) % mod;
            ret[1][0] = (1LL * a[1][0] * m[0][0] + 1LL * a[1][1] * m[1][0] + 1LL * a[1][2] * m[2][0] + 1LL * a[1][3] * m[3][0] + 1LL * a[1][4] * m[4][0]) % mod;
            ret[1][1] = (1LL * a[1][0] * m[0][1] + 1LL * a[1][1] * m[1][1] + 1LL * a[1][2] * m[2][1] + 1LL * a[1][3] * m[3][1] + 1LL * a[1][4] * m[4][1]) % mod;
            ret[1][2] = (1LL * a[1][0] * m[0][2] + 1LL * a[1][1] * m[1][2] + 1LL * a[1][2] * m[2][2] + 1LL * a[1][3] * m[3][2] + 1LL * a[1][4] * m[4][2]) % mod;
            ret[1][3] = (1LL * a[1][0] * m[0][3] + 1LL * a[1][1] * m[1][3] + 1LL * a[1][2] * m[2][3] + 1LL * a[1][3] * m[3][3] + 1LL * a[1][4] * m[4][3]) % mod;
            ret[1][4] = (1LL * a[1][0] * m[0][4] + 1LL * a[1][1] * m[1][4] + 1LL * a[1][2] * m[2][4] + 1LL * a[1][3] * m[3][4] + 1LL * a[1][4] * m[4][4]) % mod;
            ret[2][0] = (1LL * a[2][0] * m[0][0] + 1LL * a[2][1] * m[1][0] + 1LL * a[2][2] * m[2][0] + 1LL * a[2][3] * m[3][0] + 1LL * a[2][4] * m[4][0]) % mod;
            ret[2][1] = (1LL * a[2][0] * m[0][1] + 1LL * a[2][1] * m[1][1] + 1LL * a[2][2] * m[2][1] + 1LL * a[2][3] * m[3][1] + 1LL * a[2][4] * m[4][1]) % mod;
            ret[2][2] = (1LL * a[2][0] * m[0][2] + 1LL * a[2][1] * m[1][2] + 1LL * a[2][2] * m[2][2] + 1LL * a[2][3] * m[3][2] + 1LL * a[2][4] * m[4][2]) % mod;
            ret[2][3] = (1LL * a[2][0] * m[0][3] + 1LL * a[2][1] * m[1][3] + 1LL * a[2][2] * m[2][3] + 1LL * a[2][3] * m[3][3] + 1LL * a[2][4] * m[4][3]) % mod;
            ret[2][4] = (1LL * a[2][0] * m[0][4] + 1LL * a[2][1] * m[1][4] + 1LL * a[2][2] * m[2][4] + 1LL * a[2][3] * m[3][4] + 1LL * a[2][4] * m[4][4]) % mod;
            ret[3][0] = (1LL * a[3][0] * m[0][0] + 1LL * a[3][1] * m[1][0] + 1LL * a[3][2] * m[2][0] + 1LL * a[3][3] * m[3][0] + 1LL * a[3][4] * m[4][0]) % mod;
            ret[3][1] = (1LL * a[3][0] * m[0][1] + 1LL * a[3][1] * m[1][1] + 1LL * a[3][2] * m[2][1] + 1LL * a[3][3] * m[3][1] + 1LL * a[3][4] * m[4][1]) % mod;
            ret[3][2] = (1LL * a[3][0] * m[0][2] + 1LL * a[3][1] * m[1][2] + 1LL * a[3][2] * m[2][2] + 1LL * a[3][3] * m[3][2] + 1LL * a[3][4] * m[4][2]) % mod;
            ret[3][3] = (1LL * a[3][0] * m[0][3] + 1LL * a[3][1] * m[1][3] + 1LL * a[3][2] * m[2][3] + 1LL * a[3][3] * m[3][3] + 1LL * a[3][4] * m[4][3]) % mod;
            ret[3][4] = (1LL * a[3][0] * m[0][4] + 1LL * a[3][1] * m[1][4] + 1LL * a[3][2] * m[2][4] + 1LL * a[3][3] * m[3][4] + 1LL * a[3][4] * m[4][4]) % mod;
            ret[4][0] = (1LL * a[4][0] * m[0][0] + 1LL * a[4][1] * m[1][0] + 1LL * a[4][2] * m[2][0] + 1LL * a[4][3] * m[3][0] + 1LL * a[4][4] * m[4][0]) % mod;
            ret[4][1] = (1LL * a[4][0] * m[0][1] + 1LL * a[4][1] * m[1][1] + 1LL * a[4][2] * m[2][1] + 1LL * a[4][3] * m[3][1] + 1LL * a[4][4] * m[4][1]) % mod;
            ret[4][2] = (1LL * a[4][0] * m[0][2] + 1LL * a[4][1] * m[1][2] + 1LL * a[4][2] * m[2][2] + 1LL * a[4][3] * m[3][2] + 1LL * a[4][4] * m[4][2]) % mod;
            ret[4][3] = (1LL * a[4][0] * m[0][3] + 1LL * a[4][1] * m[1][3] + 1LL * a[4][2] * m[2][3] + 1LL * a[4][3] * m[3][3] + 1LL * a[4][4] * m[4][3]) % mod;
            ret[4][4] = (1LL * a[4][0] * m[0][4] + 1LL * a[4][1] * m[1][4] + 1LL * a[4][2] * m[2][4] + 1LL * a[4][3] * m[3][4] + 1LL * a[4][4] * m[4][4]) % mod;
        }
        return ret;
    }
};

struct DSU {
    static const int N = 1e6 + 10;
    int n, fa[N];
    Matrix w[N];
    void init(int _n) {
        n = _n;
        for(int i = 0; i <= n; ++i) fa[i] = i, w[i].setOne();
    }
    inline int find(int x) {
        if(fa[x] == x) return x;
        int f = find(fa[x]);
//        pr(x); pr(fa[x]);prln(f);
//        w[x].see();
//        w[fa[x]].see();
        w[x] = w[x] * w[fa[x]];
        return fa[x] = f;
    }
    inline void add(int i, Matrix& m) {
//        printf("add %d %d\n", i - 1, i);
//        m.see();
//        w[i].see();
        fa[i - 1] = i;
        w[i - 1] = m;
    }
    inline void getSuf(int i, Matrix& m) {
        find(i);
        m = w[i];
    }
} dsu;

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d%d%d", &l, &n, &mod) == 3) {
        Matrix A, B;
        A.read(); B.read();

        int c; scanf("%d", &c);

        dsu.init(l);
        Matrix ans;
        dsu.add(1, A);
        dsu.getSuf(c, ans);
        ans = ans * B;
//        ans.see();

//        vector<Matrix> v(l + 1); v[0] = A;
//        v[1] = A * B;

        for(int i = 2; i <= l; ++i) {
            scanf("%d", &c);
            dsu.add(i, ans);
            dsu.getSuf(c, ans);
            ans = ans * B;

//            ans.see();

//            v[i].setOne();
//            for(int j = c; j < i; ++j) v[i] = v[i] * v[j];
//            v[i] = v[i] * B;
        }
        ans.see();
//        v[l].see();
//        puts("");

    }

    return 0;
}
