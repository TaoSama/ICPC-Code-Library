//
//  Created by TaoSama on 2015-09-27
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

int n, L, a[N], all[N];
int f[N], g[N], h[N];

int maxv[N << 2];
void update(int o, int v, int l, int r, int rt) {
    if(l == r) {
        maxv[rt] = max(maxv[rt], v);
        return;
    }
    int m = l + r >> 1;
    if(o <= m) update(o, v, l, m, rt << 1);
    else update(o, v, m + 1, r, rt << 1 | 1);
    maxv[rt] = max(maxv[rt << 1], maxv[rt << 1 | 1]);
}

int query(int L, int R, int l, int r, int rt) {
    if(L <= l && r <= R) return maxv[rt];
    int m = l + r >> 1, ret = -INF;
    if(L <= m) ret = max(ret, query(L, R, l, m, rt << 1));
    if(R > m) ret = max(ret, query(L, R, m + 1, r, rt << 1 | 1));
    return ret;
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int t; scanf("%d", &t);
    int kase = 0;
    while(t--) {
        scanf("%d%d", &n, &L);
        for(int i = 1; i <= n; ++i) {
            scanf("%d", a + i);
            all[i] = a[i];
        }
        sort(all + 1, all + 1 + n);
        int m = unique(all + 1, all + 1 + n) - all - 1;

        memset(h, 0x3f, sizeof h);
        for(int i = 1; i <= n; ++i) {
            int k = lower_bound(h + 1, h + 1 + n, a[i]) - h;
            f[i] = k;
            h[k] = a[i];
        }
        memset(h, 0x3f, sizeof h);
        for(int i = n; i; --i) {
            int k = lower_bound(h + 1, h + 1 + n, -a[i]) - h;
            g[i] = k;
            h[k] = -a[i];
        }

        int ans = 0;
        a[n + 1] = INF; g[n + 1] = 0;
        memset(maxv, 0, sizeof maxv);
        //delete [i-l,i-1] length:l   [0,i-l-1]->maxv
        for(int i = L + 1; i <= n + 1; ++i) {
            int o = lower_bound(all + 1, all + 1 + m, a[i]) - all;
            ans = max(ans, query(0, o - 1, 0, m, 1) + g[i]);
            o = lower_bound(all + 1, all + 1 + m, a[i - L]) - all; //插入一个新的
            if(i <= n) update(o, f[i - L], 0, m, 1);
        }
        printf("Case #%d: %d\n", ++kase, ans);
    }
    return 0;
}
