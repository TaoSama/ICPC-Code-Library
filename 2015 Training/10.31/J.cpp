//
//  Created by TaoSama on 2015-10-31
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

int n, q;

struct Node {
    int l, r, sz;
    int pre, suf, sub, lv, rv;
    Node(int l = 0, int r = 0): l(l), r(r) {
        sz = r - l + 1;
        sub = -INF;
    }
    void set(int a, int b, int c, int d, int e) {
        pre = a; sub = b; suf = c;
        lv = d; rv = e;
    }
} dat[N << 2];

Node operator+ (const Node& A, const Node& B) {
    if(A.sub == -INF) return B;
    if(B.sub == -INF) return A;
    Node ret(A.l, B.r);
    ret.set(A.pre, max(A.sub, B.sub), B.suf, A.lv, B.rv);
    if(A.rv == B.lv) {
        if(ret.pre == A.sz) ret.pre += B.pre;
        if(ret.suf == B.sz) ret.suf += A.suf;
        ret.sub = max(ret.sub, A.suf + B.pre);
    }
    return ret;
}

void build(int l, int r, int rt) {
    dat[rt] = Node(l, r);
    if(l == r) {
        int x; scanf("%d", &x);
        dat[rt].set(1, 1, 1, x, x);
        return;
    }
    int m = l + r >> 1;
    build(l, m, rt << 1);
    build(m + 1, r, rt << 1 | 1);
    dat[rt] = dat[rt << 1] + dat[rt << 1 | 1];
}

Node query(int L, int R, int rt) {
    if(L <= dat[rt].l && dat[rt].r <= R) return dat[rt];
    int m = dat[rt].l + dat[rt].r >> 1;
    Node ret;
    if(L <= m) ret = ret + query(L, R, rt << 1);
    if(R > m) ret = ret + query(L, R, rt << 1 | 1);
    return ret;
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d", &n) == 1 && n) {
        scanf("%d", &q);
        build(1, n, 1);
        while(q--) {
            int l, r; scanf("%d%d", &l, &r);
            printf("%d\n", query(l, r, 1).sub);
        }
    }
    return 0;
}
