//
//  Created by TaoSama on 2016-05-26
//  Copyright (c) 2016 TaoSama. All rights reserved.
//
#pragma comment(linker, "/STACK:102400000,102400000")
#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <set>
#include <vector>
#include <cassert>

using namespace std;
#define pr(x) cout << #x << " = " << x << "  "
#define prln(x) cout << #x << " = " << x << endl
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, a[N], wh[N], ans[N];

#define MP make_pair

struct SegTree {
    int lazy[N << 2], maxv[N << 2];
    void up(int rt) {
        maxv[rt] = max(maxv[rt << 1], maxv[rt << 1 | 1]);
    }
    void down(int rt) {
        if(lazy[rt]) {
            int ls = rt << 1, rs = ls | 1;
            lazy[ls] = lazy[rs] = lazy[rt];
            maxv[ls] = maxv[rs] = lazy[rt] = 0;
        }
    }
    void build(int l, int r, int rt) {
        lazy[rt] = 0;
        if(l == r) {
            maxv[rt] = a[l];
            return;
        }
        int m = l + r >> 1;
        build(l, m, rt << 1);
        build(m + 1, r, rt << 1 | 1);
        up(rt);
    }
    void del(int L, int R, int l, int r, int rt) {
        if(L <= l && r <= R) {
            lazy[rt] = 1;
            maxv[rt] = 0;
            return ;
        }
        int m = l + r >> 1;
        down(rt);
        if(L <= m) del(L, R, l, m, rt << 1);
        if(R > m) del(L, R, m + 1, r, rt << 1 | 1);
        up(rt);
    }
    int query(int L, int R, int l, int r, int rt) {
        if(L <= l && r <= R) return maxv[rt];
        int m = l + r >> 1;
        down(rt);
        int ret = 0;
        if(L <= m) ret = max(ret, query(L, R, l, m, rt << 1));
        if(R > m) ret = max(ret, query(L, R, m + 1, r, rt << 1 | 1));
        return ret;
    }
} T;

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);
    clock_t _ = clock();

    int t; scanf("%d", &t);
    while(t--) {
        scanf("%d", &n);
        for(int i = 1; i <= n; ++i) scanf("%d", a + i), wh[a[i]] = i;

        T.build(1, n, 1);
        set<pair<int, int> > done;
        memset(ans, 0, sizeof ans);
        for(int i = 1; i <= n; ++i) {
            if(ans[i]) continue;
            int p = wh[i];

            int l = 1, r = min(n, p + 1);
            auto iter = done.lower_bound({p, p});
            if(iter != done.begin()) l = (--iter)->second + 1;

            int maxv = T.query(l, r, 1, n, 1);
            int from = wh[maxv];

            if(from == p + 1) {
                ans[a[p]] = a[from];
                T.del(from, from, 1, n, 1); //delete
            } else {
                //link
                for(int j = from; j < p; ++j) ans[a[j]] = a[j + 1];
                ans[a[p]] = a[from];

                T.del(from, p, 1, n, 1); //delete
                done.insert({from, p}); //maintain the cycled intervals
            }
        }

        for(int i = 1; i <= n; ++i) printf("%d%c", ans[i], " \n"[i == n]);
    }

#ifdef LOCAL
    printf("\nTime cost: %.2fs\n", 1.0 * (clock() - _) / CLOCKS_PER_SEC);
#endif
    return 0;
}
