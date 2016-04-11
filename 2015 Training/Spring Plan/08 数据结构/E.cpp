//
//  Created by TaoSama on 2015-09-21
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

int n, q;
int maxv[N << 2];

#define root 1, n, 1
#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1 | 1

void push_up(int rt) {
    maxv[rt] = max(maxv[rt << 1], maxv[rt << 1 | 1]);
}

void build(int l, int r, int rt) {
    if(l == r) {
        scanf("%d", &maxv[rt]);
        return;
    }
    int m = l + r >> 1;
    build(lson);
    build(rson);
    push_up(rt);
}

void update(int o, int v, int l, int r, int rt) {
    if(l == r) {
        maxv[rt] = v;
        return;
    }
    int m = l + r >> 1;
    if(o <= m) update(o, v, lson);
    else update(o, v, rson);
    push_up(rt);
}

int query(int L, int R, int l, int r, int rt) {
    if(L <= l && r <= R) {
        return maxv[rt];
    }
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

    while(scanf("%d", &n) == 1) {
        build(root);
        scanf("%d", &q);
        while(q--) {
            int op, x, y; scanf("%d%d%d", &op, &x, &y);
            if(op) {
                int ans = INF;
                if(x > y) swap(x, y);
                ans = min(ans, query(x, y, root));
                ans = min(ans, max(query(1, x, root), query(y, n, root)));
                printf("%d\n", ans);
            } else update(x, y, root);
        }
    }
    return 0;
}
