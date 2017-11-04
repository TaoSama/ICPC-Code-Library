//
//  Created by TaoSama on 2015-05-19
//  Copyright (c) 2015 TaoSama. All rights reserved.
//
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

#define root 1, n, 1
#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1 | 1

typedef long long LL;
int n, q;
LL sum[N * 3], add[N * 3];

void push_up(int rt) {
    sum[rt] = sum[rt << 1] + sum[rt << 1 | 1];
}

void push_down(int rt, int m) {
    if(add[rt]) {
        add[rt << 1] += add[rt];
        add[rt << 1 | 1] += add[rt];
        sum[rt << 1] += add[rt] * (m - (m >> 1));
        sum[rt << 1 | 1] += add[rt] * (m >> 1);
        add[rt] = 0;
    }
}

void build(int l, int r, int rt) {
    add[rt] = 0;
    if(l == r) {
        scanf("%lld", &sum[rt]);
        return;
    }
    int m = l + r >> 1;
    build(lson);
    build(rson);
    push_up(rt);
}

void update(int L, int R, int v, int l, int r, int rt) {
    if(L <= l && r <= R) {
        add[rt] += v;
        sum[rt] += (LL)v * (r - l + 1);
        return;
    }
    push_down(rt, r - l  + 1);
    int m = l + r >> 1;
    if(L <= m) update(L, R, v, lson);
    if(R > m)update(L, R, v, rson);
    push_up(rt);
}

LL query(int L, int R, int l, int r, int rt) {
    if(L <= l && r <= R) return sum[rt];
    push_down(rt, r - l + 1);
    int m = l + r >> 1;
    LL ret = 0;
    if(L <= m) ret += query(L, R, lson);
    if(R > m) ret += query(L, R, rson);
    return ret;
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d%d", &n, &q) == 2) {
        build(root);
        while(q--) {
            char op[2]; int x, y, z;
            scanf("%s%d%d", op, &x, &y);
            if(op[0] == 'Q') printf("%lld\n", query(x, y, root));
            else {
                scanf("%d", &z);
                update(x, y, z, root);
            }
        }
    }
    return 0;
}
