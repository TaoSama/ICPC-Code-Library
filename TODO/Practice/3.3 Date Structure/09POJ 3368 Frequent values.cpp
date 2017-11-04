//
//  Created by TaoSama on 2015-06-17
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

int n, q;
int lsum[N * 3], rsum[N * 3], msum[N * 3], lv[N * 3], rv[N * 3];

#define root 1, n, 1
#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1 | 1

void push_up(int rt, int m) {
    lsum[rt] = lsum[rt << 1];
    rsum[rt] = rsum[rt << 1 | 1];
    msum[rt] = max(msum[rt << 1], msum[rt << 1 | 1]);
    if(rv[rt << 1] == lv[rt << 1 | 1]) {
        msum[rt] = max(msum[rt], rsum[rt << 1] + lsum[rt << 1 | 1]);
        if(lsum[rt << 1] == m - (m >> 1)) lsum[rt] += lsum[rt << 1 | 1];
        if(rsum[rt << 1 | 1] == m >> 1) rsum[rt] += rsum[rt << 1];
    }

    lv[rt] = lv[rt << 1]; rv[rt] = rv[rt << 1 | 1];
}

void build(int l, int r, int rt) {
    if(l == r) {
        lsum[rt] = rsum[rt] = msum[rt] = 1;
        int x; scanf("%d", &x);
        lv[rt] = rv[rt] = x;
        return;
    }
    int m = l + r >> 1;
    build(lson);
    build(rson);
    push_up(rt, r - l + 1);
}

int query(int L, int R, int l, int r, int rt) {
    if(L <= l && r <= R) return msum[rt];
    int m = l + r >> 1;
    int ret = -INF;
    if(L <= m) ret = max(ret, query(L, R, lson));
    if(R > m) ret = max(ret, query(L, R, rson));
    if(rv[rt << 1] == lv[rt << 1 | 1] && L <= m && m < R) {
        int x = rsum[rt << 1], y = lsum[rt << 1 | 1];
        if(m - x + 1 < L) x = m - L + 1;
        if(m + y > R) y = R - m;
        ret = max(ret, x + y);
    }
    return ret;
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d", &n) == 1 && n) {
        scanf("%d", &q);
        build(root);
        while(q--) {
            int x, y; scanf("%d%d", &x, &y);
            printf("%d\n", query(x, y, root));
        }
    }
    return 0;
}
