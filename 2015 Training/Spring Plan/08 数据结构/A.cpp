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

int minv[N << 2];

#define root 1, n, 1
#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1 | 1

void push_up(int rt) {
    minv[rt] = min(minv[rt << 1], minv[rt << 1 | 1]);
}

void update(int o, int v, int l, int r, int rt) {
    if(l == r) {
        minv[rt] = v;
        return;
    }
    int m = l + r >> 1;
    if(o <= m) update(o, v, lson);
    else update(o, v, rson);
    push_up(rt);
}

int query(int L, int R, int l, int r, int rt) {
    if(L <= l && r <= R) return minv[rt];
    int m = l + r >> 1, ret = INF;
    if(L <= m) ret = min(ret, query(L, R, lson));
    if(R > m) ret = min(ret, query(L, R, rson));
    return ret;
}

int n, k, a[N], all[N], pre[N];

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d%d", &n, &k) == 2) {
        memset(minv, 0x3f, sizeof minv);
        memset(pre, 0, sizeof pre);

        for(int i = 1; i <= n; ++i) {
            scanf("%d", a + i);
            all[i] = a[i];
        }
        sort(all + 1, all + 1 + n);
        for(int i = 1; i <= k; ++i) {
            int l, r; scanf("%d%d", &l, &r);
            l = lower_bound(all + 1, all + 1 + n, a[l]) - all;
            r = lower_bound(all + 1, all + 1 + n, a[r]) - all;
            if(l > r) swap(l, r);
            pre[r] = max(pre[r], l);
        }

        int pos = 0, ans = 0;
        for(int i = 1; i <= n; ++i) {
            pos = max(pos, pre[i]);
            if(pos && i > 1) ans = query(pos, i - 1, root);
            if(i < n) update(i, ans + all[i + 1] - all[i], root);
        }
        printf("%d\n", ans);
    }
    return 0;
}
