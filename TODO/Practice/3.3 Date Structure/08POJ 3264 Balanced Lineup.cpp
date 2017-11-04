//
//  Created by TaoSama on 2015-05-21
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
const int N = 5e4 + 10;

#define root 1, n, 1
#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1 | 1
int n, q, maxv[N * 3], minv[N * 3];

void push_up(int rt) {
    maxv[rt] = max(maxv[rt << 1], maxv[rt << 1 | 1]);
    minv[rt] = min(minv[rt << 1], minv[rt << 1 | 1]);
}

void build(int l, int r, int rt) {
    if(l == r) {
        int x; scanf("%d", &x);
        maxv[rt] = minv[rt] = x;
        return;
    }
    int m = l + r >> 1;
    build(lson);
    build(rson);
    push_up(rt);
}

int query(int op, int L, int R, int l, int r, int rt) {
    if(L <= l && r <= R) {
        return op ? maxv[rt] : minv[rt];
    }
    int Max = -INF, Min = INF;
    int m = l + r >> 1;
    if(op) {
        if(L <= m) Max = max(Max, query(op, L, R, lson));
        if(R > m) Max = max(Max, query(op, L, R, rson));
    } else {
        if(L <= m) Min = min(Min, query(op, L, R, lson));
        if(R > m) Min = min(Min, query(op, L, R, rson));
    }
    return op ? Max : Min;
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
            int x, y; scanf("%d%d", &x, &y);
            int Max = query(1, x, y, root);
            int Min = query(0, x, y, root);
            printf("%d\n", Max - Min);
        }
    }
    return 0;
}
