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
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, k, q, need[10];

#define root 1, n, 1
#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1 | 1

int ex[N << 2][12], lazy[N << 2];

void build(int l, int r, int rt) {
    ex[rt][1] = lazy[rt] = 0;
    for(int i = 2; i <= k; ++i) ex[rt][i] = -1;
    if(l == r) return;
    int m = l + r >> 1;
    build(lson);
    build(rson);
}

void push_up(int rt) {
    for(int i = 1; i <= k; ++i)
        ex[rt][i] = max(ex[rt << 1][i], ex[rt << 1 | 1][i]);
}

void push_down(int rt) {
    if(lazy[rt]) {
        lazy[rt << 1] += lazy[rt];
        lazy[rt << 1 | 1] += lazy[rt];
        for(int i = 1; i <= k; ++i) {
            if(~ex[rt << 1][i]) ex[rt << 1][i] += lazy[rt] * i;
            if(~ex[rt << 1 | 1][i]) ex[rt << 1 | 1][i] += lazy[rt] * i;
        }
        lazy[rt] = 0;
    }
}

void level_up(int lv, int l, int r, int rt) {
    if(l == r) {
        while(lv < k) {
            if(ex[rt][lv] < need[lv]) break;
            ex[rt][lv + 1] = ex[rt][lv];
            ex[rt][lv] = -1;
            ++lv;
        }
        return;
    }
    push_down(rt);
    int m = l + r >> 1;
    if(ex[rt << 1][lv] >= need[lv]) level_up(lv, lson);
    if(ex[rt << 1 | 1][lv] >= need[lv]) level_up(lv, rson);
    push_up(rt);
}

void update(int L, int R, int v, int l, int r, int rt) {
    if(L <= l && r <= R) {
        lazy[rt] += v;
        for(int i = k; i; --i) {
            if(~ex[rt][i]) ex[rt][i] += v * i;
            if(i < k && ex[rt][i] >= need[i])
                level_up(i, l, r, rt);
        }
        return;
    }
    push_down(rt);
    int m = l + r >> 1;
    if(L <= m) update(L, R, v, lson);
    if(R > m) update(L, R, v, rson);
    push_up(rt);
}

int query(int L, int R, int l, int r, int rt) {
    if(L <= l && r <= R) {
        for(int i = k; i; --i) if(~ex[rt][i]) return ex[rt][i];
    }
    push_down(rt);
    int m = l + r >> 1, ret = 0;
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
