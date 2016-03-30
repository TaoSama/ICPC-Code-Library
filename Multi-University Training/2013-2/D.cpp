//
//  Created by TaoSama on 2016-02-28
//  Copyright (c) 2016 TaoSama. All rights reserved.
//
#pragma comment(linker, "/STACK:1024000000,1024000000")
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

struct SegTree {
    int sum[N << 1], lazy[N << 1];
    void build(int l, int r, int rt) {
        sum[rt] = r - l + 1;
        lazy[rt] = -1;
        if(l == r) return;
        int m = l + r >> 1;
        build(l, m, rt << 1);
        build(m + 1, r, rt << 1 | 1);
    }
    void pushUp(int rt) {
        sum[rt] = sum[rt << 1] + sum[rt << 1 | 1];
    }
    void pushDown(int rt, int m) {
        if(~lazy[rt]) {
            sum[rt << 1] = lazy[rt] * (m - (m >> 1));
            sum[rt << 1 | 1] = lazy[rt] * (m >> 1);
            lazy[rt << 1] = lazy[rt << 1 | 1] = lazy[rt];
            lazy[rt] = -1;
        }
    }
    int update(int L, int R, int v, int l, int r, int rt) {
        if(L <= l && r <= R) {
            int ret = sum[rt];
            sum[rt] = v * (r - l + 1);
            lazy[rt] = v;
            return ret;
        }
        int m = l + r >> 1, ret = 0;
        pushDown(rt, r - l + 1);
        if(L <= m) ret += update(L, R, v, l, m, rt << 1);
        if(R > m) ret += update(L, R, v, m + 1, r, rt << 1 | 1);
        pushUp(rt);
        return ret;
    }
    int query(int L, int R, int l, int r, int rt) {
        if(L <= l && r <= R) return sum[rt];
        int m = l + r >> 1, ret = 0;
        pushDown(rt, r - l + 1);
        if(L <= m) ret += query(L, R, l, m, rt << 1);
        if(R > m) ret += query(L, R, m + 1, r, rt << 1 | 1);
        return ret;
    }
} T;

int get(int st, int k) {
    int l = st, r = n;
    while(l <= r) {
        int m = l + r >> 1;
        if(T.query(st, m, 1, n, 1) >= k)  r = m - 1;
        else l = m + 1;
    }
    return l == n + 1 ? -1 : l;
}

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
        while(q--) {
            int op, x, y; scanf("%d%d%d", &op, &x, &y);
            if(op == 1) {
                int all = T.query(x + 1, n, 1, n, 1);
                if(all == 0) {
                    puts("Can not put any one.");
                } else {
                    int l = get(x + 1, 1), r = get(x + 1, min(all, y));
                    T.update(l, r, 0, 1, n, 1);
                    printf("%d %d\n", l - 1, r - 1);
                }
            } else {
                int tmp = T.update(x + 1, y + 1, 1, 1, n, 1);
                int ans = y - x + 1 - tmp;
                printf("%d\n", ans);
            }
        }
        puts("");
    }
    return 0;
}
