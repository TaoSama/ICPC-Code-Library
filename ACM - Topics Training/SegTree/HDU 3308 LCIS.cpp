//
//  Created by TaoSama on 2015-09-29
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

int n, q, a[N];

typedef pair<int, int> Interval;

struct Node {
    Node() {}
    Node(int l, int r): l(l), r(r) {sz = r - l + 1;}
    int l, r, sz;
    int preR, sufL;
    Interval sub;
} dat[N << 2];

Interval getMax(Interval x, Interval y) {
    return x.second - x.first > y.second - y.first ? x : y;
}

Node push_up(Node x, Node y) {
    Node ret(x.l, y.r);
    ret.preR = x.preR;
    ret.sufL = y.sufL;
    ret.sub = getMax(x.sub, y.sub);
    if(a[x.r] < a[x.r + 1]) {
        if(ret.preR - ret.l + 1 == x.sz) ret.preR = y.preR;
        if(ret.r - ret.sufL + 1 == y.sz) ret.sufL = x.sufL;
        ret.sub = getMax(ret.sub, Interval(x.sufL, y.preR));
    }
    return ret;
}

void build(int l, int r, int rt) {
    if(l == r) {
        dat[rt] = Node(l, r);
        dat[rt].preR = dat[rt].sufL = l;
        dat[rt].sub = Interval(l, l);
        scanf("%d", a + l);
        return;
    }
    int m = l + r >> 1;
    build(l, m, rt << 1);
    build(m + 1, r, rt << 1 | 1);
    dat[rt] = push_up(dat[rt << 1], dat[rt << 1 | 1]);
}

void update(int o, int v, int rt) {
    if(dat[rt].l == dat[rt].r) {
        a[dat[rt].l] = v;
        return;
    }
    int m = dat[rt].l + dat[rt].r >> 1;
    if(o <= m) update(o, v, rt << 1);
    else update(o, v, rt << 1 | 1);
    dat[rt] = push_up(dat[rt << 1], dat[rt << 1 | 1]);
}

Node query(int L, int R, int rt) {
    if(L <= dat[rt].l && dat[rt].r <= R) return dat[rt];
    int m = dat[rt].l + dat[rt].r >> 1;

    if(L <= m && R > m)
        return push_up(query(L, R, rt << 1),
                       query(L, R, rt << 1 | 1));
    else if(L <= m) return query(L, R, rt << 1);
    else return query(L, R, rt << 1 | 1);
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int t; scanf("%d", &t);
    while(t--) {
        scanf("%d%d", &n, &q);
        build(0, n - 1, 1);
        while(q--) {
            char op[2]; int x, y;
            scanf("%s%d%d", op, &x, &y);
            if(*op == 'U') update(x, y, 1);
            else {
                Interval ans = query(x, y, 1).sub;
                printf("%d\n", ans.second - ans.first + 1);
            }
        }
    }
    return 0;
}
