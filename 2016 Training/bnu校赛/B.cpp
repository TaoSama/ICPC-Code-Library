//
//  Created by TaoSama on 2016-04-23
//  Copyright (c) 2016 TaoSama. All rights reserved.
//
#pragma comment(linker, "/STACK:102400000,102400000")
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

int n, q, a[N], wh[N];

typedef long long LL;
LL sum[N << 2];
void pushUp(int rt) {
    sum[rt] = sum[rt << 1] + sum[rt << 1 | 1];
}
void build(int l, int r, int rt) {
    if(l == r) {
        sum[rt] = a[a[l]];
        return;
    }
    int m = l + r >> 1;
    build(l, m, rt << 1);
    build(m + 1, r, rt << 1 | 1);
    pushUp(rt);
}

void update(int o, int v, int l, int r, int rt) {
    if(l == r) {
        sum[rt] = v;
        return;
    }
    int m = l + r >> 1;
    if(o <= m) update(o, v, l, m, rt << 1);
    else update(o, v, m + 1, r, rt << 1 | 1);
    pushUp(rt);
}

LL query(int L, int R, int l, int r, int rt) {
    if(L <= l && r <= R) return sum[rt];
    int m = l + r >> 1;
    LL ret = 0;
    if(L <= m) ret += query(L, R, l, m, rt << 1);
    if(R > m) ret += query(L, R, m + 1, r, rt << 1 | 1);
    return ret;
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int t; scanf("%d", &t);
    while(t--) {
        scanf("%d", &n);
        for(int i = 1; i <= n; ++i) {
            scanf("%d", a + i);
            wh[a[i]] = i;
        }
        build(1, n, 1);

        scanf("%d", &q);
        while(q--) {
            int op, l, r; scanf("%d%d%d", &op, &l, &r);
            if(op == 1) {
                swap(a[l], a[r]);
                swap(wh[a[l]], wh[a[r]]);
                update(l, a[a[l]], 1, n, 1);
                update(r, a[a[r]], 1, n, 1);
                update(wh[l], a[l], 1, n, 1);
                update(wh[r], a[r], 1, n, 1);
            } else printf("%lld\n", query(l, r, 1, n, 1));
        }
    }
    return 0;
}
