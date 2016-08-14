//
//  Created by TaoSama on 2016-08-11
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

int n, q;
struct Node {
    int l, r, len;
    LL addv, tag, sum;
    void add(LL v) {
        addv += v;
        if(tag) tag += v, addv = 0;
        sum += len * v;
    }
    void set(LL v) {
        tag = v;
        sum = tag * len;
        addv = 0;
    }
    void see() {
        pr(l); pr(r); pr(addv); pr(tag); prln(sum);
    }
} ;
struct SegTree {
    Node dat[N << 2];
    void up(int rt) {
        int ls = rt << 1, rs = ls | 1;
        dat[rt].sum = dat[ls].sum + dat[rs].sum;
        if(dat[ls].tag == dat[rs].tag) dat[rt].tag = dat[ls].tag;
        else dat[rt].tag = 0;
    }
    void down(int rt) {
        int ls = rt << 1, rs = ls | 1;
        if(dat[rt].tag) {
            LL& v = dat[rt].tag;
            dat[ls].set(v);
            dat[rs].set(v);
        }
        if(dat[rt].addv) {
            LL& v = dat[rt].addv;
            dat[ls].add(v);
            dat[rs].add(v);
            v = 0;
        }
    }
    void build(int l, int r, int rt) {
        dat[rt] = {l, r, r - l + 1, 0, 0, 0};
        if(l == r) {
            scanf("%I64d", &dat[rt].sum);
            dat[rt].tag = dat[rt].sum;
            return;
        }
        int m = l + r >> 1;
        build(l, m, rt << 1);
        build(m + 1, r, rt << 1 | 1);
        up(rt);
    }
    void update(int L, int R, int rt) {
        if(dat[rt].tag && L <= dat[rt].l && dat[rt].r <= R) {
            dat[rt].set(sqrt(dat[rt].tag));
            return;
        }
        down(rt);
        int m = dat[rt].l + dat[rt].r >> 1;
        if(L <= m) update(L, R, rt << 1);
        if(R > m) update(L, R, rt << 1 | 1);
        up(rt);
    }
    void update(int L, int R, int v, int rt) {
        if(L <= dat[rt].l && dat[rt].r <= R) {
            dat[rt].add(v);
            return;
        }
        down(rt);
        int m = dat[rt].l + dat[rt].r >> 1;
        if(L <= m) update(L, R, v, rt << 1);
        if(R > m) update(L, R, v, rt << 1 | 1);
        up(rt);
    }
    LL query(int L, int R, int rt) {
        if(L <= dat[rt].l && dat[rt].r <= R) return dat[rt].sum;
        down(rt);
        int m = dat[rt].l + dat[rt].r >> 1;
        LL ret = 0;
        if(L <= m) ret += query(L, R, rt << 1);
        if(R > m) ret += query(L, R, rt << 1 | 1);
        return ret;
    }
} T;

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int t; scanf("%d", &t);
    while(t--) {
        scanf("%d%d", &n, &q);
        T.build(1, n, 1);
//        prln(T.query(1, n, 1));
//        prln(1);
        for(int i = 1; i <= q; ++i) {
//          prln(i);
            int op, l, r; scanf("%d%d%d", &op, &l, &r);
            if(op == 1) {
                int v; scanf("%d", &v);
                T.update(l, r, v, 1);
            } else if(op == 2) {
                T.update(l, r, 1);
            } else {
                printf("%I64d\n", T.query(l, r, 1));
            }
//            prln(T.query(1, n, 1));
        }
    }

    return 0;
}
