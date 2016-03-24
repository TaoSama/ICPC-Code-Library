//
//  Created by TaoSama on 2015-08-22
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
int val[N << 2];

#define root 1, n, 1
#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1 | 1

void push_down(int rt, int l, int r) {
    if(val[rt]) {
//      printf("lazy: %d %d\n", l, r);
        int m = l + r >> 1;
        val[rt << 1] = val[rt];
        val[rt << 1 | 1] = val[rt] + m - l + 1;
        val[rt] = 0;
    }
}

void build(int l, int r, int rt) {
    val[rt] = 0;
    if(l == r) {
        val[rt] = l + n;
        return;
    }
    int m = l + r >> 1;
    build(lson);
    build(rson);
}

void update(int L, int R, int v, int l, int r, int rt) {
    if(L <= l && r <= R) {
//      printf("%d %d: %d\n", l, r, v);
        val[rt] = v + l - L;
        return;
    }
    push_down(rt, l, r);
    int m = l + r >> 1;
    if(L <= m) update(L, R, v, lson);
    if(R > m) update(L, R, v, rson);
}

int query(int o, int l, int r, int rt) {
    if(l == r) return val[rt];
    push_down(rt, l, r);
    int m = l + r >> 1;
    if(o <= m) return query(o, lson);
    else return query(o, rson);
}

int a[N], b[N];

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d%d", &n, &q) == 2) {
        for(int i = 1; i <= n; ++i) scanf("%d", a + i);
        for(int i = 1; i <= n; ++i) scanf("%d", b + i);

        build(root);
        while(q--) {
            int op, x, y, k;
            scanf("%d", &op);
            if(op == 1) {
                scanf("%d%d%d", &x, &y, &k);
//              printf("l: %d r: %d %d\n", y, y + k - 1, x);
                update(y, y + k - 1, x, root);
//              for(int i = y; i <= y + k - 1; ++i) printf("%d ", query(i, root));
//              puts("\n");
            } else {
                scanf("%d", &x);
                int ans = query(x, root);
                if(ans > n) printf("%d\n", b[ans - n]);
                else printf("%d\n", a[ans]);
            }
        }
    }
    return 0;
}
