//
//  Created by TaoSama on 2015-06-03
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
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int N = 1e5 + 10;

int n, q, sum[N << 2], add[N << 2];

#define root 1, n, 1
#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1 | 1

void push_up(int rt) {
    sum[rt] = sum[rt << 1] + sum[rt << 1 | 1];
}

void push_down(int rt, int m) {
    if(add[rt]) {
        sum[rt << 1] += add[rt] * (m - (m >> 1));
        sum[rt << 1 | 1] += add[rt] * (m >> 1);
        add[rt << 1] += add[rt];
        add[rt << 1 | 1] += add[rt];
        add[rt] = 0;
    }
}

void build(int l, int r, int rt) {
    add[rt] = 0;
    if(l == r) {
        scanf("%d", &sum[rt]);
        return;
    }
    int m = l + r >> 1;
    build(lson);
    build(rson);
    push_up(rt);
}

void update(int o, int v, int l, int r, int rt) {
    if(l == r) {
        sum[rt] = v;
        return;
    }
    push_down(rt, r - l + 1);
    int m = l + r >> 1;
    if(o <= m) update(o, v, lson);
    else update(o, v, rson);
    push_up(rt);
}

void update(int L, int R, int v, int l, int r, int rt) {
    if(L <= l && r <= R) {
        add[rt] += v;
        sum[rt] += v * (r - l + 1);
        return;
    }
    push_down(rt, r - l + 1);
    int m = l + r >> 1;
    if(L <= m) update(L, R, v, lson);
    if(R > m) update(L, R, v, rson);
    push_up(rt);
}

int query(int o, int l, int r, int rt) {
    if(l == r) {
        return sum[rt];
    }
    push_down(rt, r - l + 1);
    int m = l + r >> 1;
    if(o <= m) query(o, lson);
    else query(o, rson);
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    scanf("%d%d", &n, &q);
    build(root);
    while(q--) {
        int x, y, z; scanf("%d%d", &x, &y);
        if(x == 1) {
            scanf("%d", &z);
            update(y, z, root);
        } else if(x == 2) {
            update(1, n, y, root);
        } else printf("%d\n", query(y, root));
    }
    return 0;
}
