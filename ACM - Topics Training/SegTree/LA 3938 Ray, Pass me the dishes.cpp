//
//  Created by TaoSama on 2015-09-15
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
const int N = 5e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

typedef long long LL;

int n, q;
LL a[N];

#define root 1, n, 1
#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1 | 1

typedef pair<int, int> Interval;

struct Node {
    int l, r;
    int preR, sufL;
    Interval sub;
} dat[N << 2];

LL sum(Interval x) {
    return a[x.second] - a[x.first - 1];
}

Interval getMax(Interval x, Interval y) {
    LL sx = sum(x), sy = sum(y);
    if(sx != sy) return sx > sy ? x : y;
    return x < y ? x : y;
}

Node push_up(Node x, Node y) {
    Node ret;
    ret.l = x.l; ret.r = y.r;
    ret.preR = getMax(Interval(x.l, x.preR), Interval(x.l, y.preR)).second;
    ret.sufL = getMax(Interval(y.sufL, y.r), Interval(x.sufL, y.r)).first;
    ret.sub = getMax(Interval(x.sufL, y.preR), getMax(x.sub, y.sub));
    return ret;
}

void build(int l, int r, int rt) {
    if(l == r) {
        dat[rt].l = dat[rt].r = l;
        dat[rt].preR = dat[rt].sufL = l;
        dat[rt].sub = Interval(l, l);
        return;
    }
    int m = l + r >> 1;
    build(lson);
    build(rson);
    dat[rt] = push_up(dat[rt << 1], dat[rt << 1 | 1]);
}

Node query(int L, int R, int rt) {
    if(L <= dat[rt].l && dat[rt].r <= R) return dat[rt];
    int m = dat[rt].l + dat[rt].r >> 1;

    Node ret;
    if(L <= m && R > m)
        ret = push_up(query(L, R, rt << 1), query(L, R, rt << 1 | 1));
    else if(L <= m) ret = query(L, R, rt << 1);
    else if(R > m) ret = query(L, R, rt << 1 | 1);
    return ret;
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int kase = 0;
    while(scanf("%d%d", &n, &q) == 2) {
        for(int i = 1; i <= n; ++i) {
            int x; scanf("%d", &x);
            a[i] = a[i - 1] + x;
        }
        build(root);
        printf("Case %d:\n", ++kase);
        while(q--) {
            int l, r; scanf("%d%d", &l, &r);
            Interval ans = query(l, r, 1).sub;
            printf("%d %d\n", ans.first, ans.second);
        }
    }
    return 0;
}