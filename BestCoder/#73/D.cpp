//
//  Created by TaoSama on 2016-02-27
//  Copyright (c) 2016 TaoSama. All rights reserved.
//
#pragma comment(linker, "/STACK:1024000000,1024000000")
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
const int N = 3e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;
const int C = 1e7 + 10;

typedef long long LL;

bool vis[C];
int phi[C], p[C];
void gao() {
    phi[1] = 1;
    int cnt = 0;
    for(int i = 2; i < C; ++i) {
        if(!vis[i]) {
            p[++cnt] = i;
            phi[i] = i - 1;
        }
        for(int j = 1; j <= cnt && i * p[j] < C; ++j) {
            vis[i * p[j]] = true;
            if(i % p[j] == 0) {phi[i * p[j]] = phi[i] * p[j]; break;}
            else phi[i * p[j]] = phi[i] * (p[j] - 1);
        }
    }
}

struct Node {
    int l, r;
    LL sum, setv;
    void set(int v) {
        setv = v;
        sum = 1LL * v * (r - l + 1);
    }
};

Node operator+(Node A, Node B) {
    Node ret = {A.l, B.r, A.sum + B.sum, 0};
    if(A.setv == B.setv) ret.setv = A.setv;
    return ret;
}

struct SegTree {
    Node dat[N << 2];
    void pushDown(int rt) {
        if(dat[rt].setv) {
            dat[rt << 1].set(dat[rt].setv);
            dat[rt << 1 | 1].set(dat[rt].setv);
            dat[rt].setv = 0;
        }
    }
    void build(int l, int r, int rt) {
        dat[rt] = {l, r, 0, 0};
        if(l == r) {
            int x; scanf("%d", &x);
            dat[rt].sum = dat[rt].setv = x;
            return;
        }
        int m = l + r >> 1;
        build(l, m, rt << 1);
        build(m + 1, r, rt << 1 | 1);
        dat[rt] = dat[rt << 1] + dat[rt << 1 | 1];
    }
    void doPhi(int L, int R, int rt) {
        if(dat[rt].setv && L <= dat[rt].l && dat[rt].r <= R) {
            dat[rt].set(phi[dat[rt].setv]);
            return;
        }
        pushDown(rt);
        int m = dat[rt].l + dat[rt].r >> 1;
        if(L <= m) doPhi(L, R, rt << 1);
        if(R > m) doPhi(L, R, rt << 1 | 1);
        dat[rt] = dat[rt << 1] + dat[rt << 1 | 1];
    }
    void update(int L, int R, int v, int rt) {
        if(L <= dat[rt].l && dat[rt].r <= R) {
            dat[rt].set(v);
            return;
        }
        pushDown(rt);
        int m = dat[rt].l + dat[rt].r >> 1;
        if(L <= m) update(L, R, v, rt << 1);
        if(R > m) update(L, R, v, rt << 1 | 1);
        dat[rt] = dat[rt << 1] + dat[rt << 1 | 1];
    }
    LL query(int L, int R, int rt) {
        if(L <= dat[rt].l && dat[rt].r <= R) return dat[rt].sum;
        pushDown(rt);
        int m = dat[rt].l + dat[rt].r >> 1;
        LL ret = 0;
        if(L <= m) ret += query(L, R, rt << 1);
        if(R > m)  ret += query(L, R, rt << 1 | 1);
        return ret;
    }
} T;

int n, q;

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int t; scanf("%d", &t);
    gao();
    while(t--) {
        scanf("%d%d", &n, &q);
        T.build(1, n, 1);
        while(q--) {
            int op, l, r; scanf("%d%d%d", &op, &l, &r);
            if(op == 1) T.doPhi(l, r, 1);
            else if(op == 2) {
                int x; scanf("%d", &x);
                T.update(l, r, x, 1);
            } else printf("%I64d\n", T.query(l, r, 1));
        }
    }
    return 0;
}
