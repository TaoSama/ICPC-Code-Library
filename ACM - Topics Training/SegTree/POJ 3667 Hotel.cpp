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
const int N = 5e4 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int pre[N << 2], suf[N << 2], sub[N << 2], cov[N << 2];

#define root 1, n, 1
#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1 | 1

void build(int l, int r, int rt) {
    cov[rt] = -1;
    pre[rt] = suf[rt] = sub[rt] = r - l + 1;
    if(l == r) return;
    int m = l + r >> 1;
    build(lson);
    build(rson);
}

void push_up(int rt, int m) {
    pre[rt] = pre[rt << 1];
    if(pre[rt] == m - (m >> 1)) pre[rt] += pre[rt << 1 | 1];
    suf[rt] = suf[rt << 1 | 1];
    if(suf[rt] == m >> 1) suf[rt] += suf[rt << 1];
    sub[rt] = max(max(sub[rt << 1], sub[rt << 1 | 1]),
                  suf[rt << 1] + pre[rt << 1 | 1]);
}

void push_down(int rt, int m) {
    if(~cov[rt]) {
        pre[rt << 1] = suf[rt << 1] = sub[rt << 1] = cov[rt] ? 0 : m - (m >> 1);
        pre[rt << 1 | 1] = suf[rt << 1 | 1] = sub[rt << 1 | 1] = cov[rt] ? 0 : m >> 1;
        cov[rt << 1] = cov[rt << 1 | 1] = cov[rt];
        cov[rt] = -1;
    }
}

void update(int L, int R, int v, int l, int r, int rt) {
    if(L <= l && r <= R) {
        cov[rt] = v;
        pre[rt] = suf[rt] = sub[rt] = cov[rt] ? 0 : r - l + 1;
        return;
    }
    push_down(rt, r - l + 1);
    int m = l + r >> 1;
    if(L <= m) update(L, R, v, lson);
    if(R > m) update(L, R, v, rson);
    push_up(rt, r - l + 1);
}

int query(int d, int l, int r, int rt) {
    if(l == r) return l;
    push_down(rt, r - l + 1);
    int m = l + r >> 1;
    if(sub[rt << 1] >= d) return query(d, lson);
    else if(suf[rt << 1] + pre[rt << 1 | 1] >= d) return m - suf[rt << 1] + 1;
    else return query(d, rson);
}

int n, q;

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d%d", &n, &q) == 2) {
        build(root);
        while(q--) {
            int op; scanf("%d", &op);
            if(op == 1) {
                int d; scanf("%d", &d);
                if(sub[1] < d) puts("0");
                else {
                    int o = query(d, root);
                    update(o, o + d - 1, 1, root);
                    printf("%d\n", o);
                }
            } else {
                int l, d; scanf("%d%d", &l, &d);
                update(l, l + d - 1, 0, root);
            }
        }
    }
    return 0;
}
