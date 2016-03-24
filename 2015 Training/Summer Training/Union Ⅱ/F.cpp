//
//  Created by TaoSama on 2015-08-27
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
const int N = 1e4 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, k, q, need[10];

#define root 1, n, 1
#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1 | 1

int ex[N << 2], lv[N << 2], to[N << 2], lazy[N << 2];

void push_up(int rt) {
    ex[rt] = max(ex[rt << 1], ex[rt << 1 | 1]);
    lv[rt] = max(lv[rt << 1], lv[rt << 1 | 1]);
    to[rt] = min(to[rt << 1], to[rt << 1 | 1]);
}

void push_down(int rt) {
    if(lazy[rt]) {
        lazy[rt << 1] += lazy[rt];
        lazy[rt << 1 | 1] += lazy[rt];
        ex[rt << 1] += lv[rt << 1] * lazy[rt];
        ex[rt << 1 | 1] += lv[rt << 1 | 1] * lazy[rt];
        to[rt << 1] -= lazy[rt];
        to[rt << 1 | 1] -= lazy[rt];
        lazy[rt] = 0;
    }
}

void build(int l, int r, int rt) {
    ex[rt] = lazy[rt] = 0;
    lv[rt] = 1; to[rt] = need[1];
    if(l == r) return;
    int m = l + r >> 1;
    build(lson);
    build(rson);
}

void update(int L, int R, int v, int l, int r, int rt) {
    if(l == r) {
        ex[rt] += lv[rt] * v;
        while(lv[rt] < k && ex[rt] >= need[lv[rt]]) ++lv[rt];
        to[rt] = lv[rt] == k ? INF : (need[lv[rt]] - ex[rt] + lv[rt] - 1) / lv[rt];
        return;
    }
    if(L <= l && r <= R && to[rt] > v) {
        lazy[rt] += v;
        to[rt] -= v;
        ex[rt] += lv[rt] * v;
        return;
    }

    push_down(rt);
    int m = l + r >> 1;
    if(L <= m) update(L, R, v, lson);
    if(R > m) update(L, R, v, rson);
    push_up(rt);
}

int query(int L, int R, int l, int r, int rt) {
    if(L <= l && r <= R) return ex[rt];
    int m = l + r >> 1, ret = 0;
    push_down(rt);
    if(L <= m) ret = max(ret, query(L, R, lson));
    if(R > m) ret = max(ret, query(L, R, rson));
    return ret;
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int t; scanf("%d", &t);
    int kase = 0;
    while(t--) {
        scanf("%d%d%d", &n, &k, &q);
        for(int i = 1; i < k; ++i) scanf("%d", need + i);
        printf("Case %d:\n", ++kase);
        build(root);
        while(q--) {
            char op[2]; int l, r, e;
            scanf("%s%d%d", op, &l, &r);
            if(op[0] == 'W') {
                scanf("%d", &e);
                update(l, r, e, root);
            } else printf("%d\n", query(l, r, root));
        }
        puts("");
    }
    return 0;
}
