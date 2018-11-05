
//  Created by TaoSama.
//  Copyright (c) 2017 TaoSama. All rights reserved.
//
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

struct SegmentTree {
    int addv[N << 2], maxv[N << 2];
    void build(int l, int r, int rt) {
        addv[rt] = 0;
        maxv[rt] = -INF;
        if(l == r) return;
        int m = (l + r) / 2;
        build(l, m, rt << 1);
        build(m + 1, r, rt << 1 | 1);
    }

    inline void down(int rt) {
        int& lazy = addv[rt];
        if(!lazy) return;
        int ls = rt << 1, rs = ls | 1;
        maxv[ls] += lazy;
        addv[ls] += lazy;
        maxv[rs] += lazy;
        addv[rs] += lazy;
        lazy = 0;
    }
    void update(int L, int R, int v, int l, int r, int rt) {
        if(L > R) return;
        if(L <= l && r <= R) {
            maxv[rt] += v;
            addv[rt] += v;
            return;
        }
        down(rt);
        int m = (l + r) / 2;
        if(L <= m) update(L, R, v, l, m, rt << 1);
        if(R > m) update(L, R, v, m + 1, r, rt << 1 | 1);
        maxv[rt] = max(maxv[rt << 1], maxv[rt << 1 | 1]);
    }
} T[55];

int n, k;
int c[N], pre[N];

int main(){
#ifdef LOCAL
    freopen("/Users/didi/ACM/in.txt", "r", stdin);
//  freopen("/Users/didi/ACM/out.txt", "w", stdout);
#endif
    ios::sync_with_stdio(0); cin.tie(0);
    
    while(scanf("%d%d", &n, &k) == 2) {
        memset(pre, 0, sizeof pre);
        for(int i = 0; i <= k; ++i) T[i].build(0, n, 1);
        T[0].update(0, 0, INF + 0, 0, n, 1);
        // printf("T[0],max1 = %d\n", T[0].maxv[1]);
        for(int i = 1; i <= n; ++i) {
            scanf("%d", c + i);
            for(int j = k; j; --j) {
                T[j - 1].update(0, i - 1, 1, 0, n, 1);
                T[j - 1].update(0, pre[c[i]] - 1, -1, 0, n, 1);
                T[j].update(i, i, INF + T[j - 1].maxv[1], 0, n, 1);
            }
            pre[c[i]] = i;
        }
        int ans = 0;
        for(int i = 1; i <= k; ++i) ans = max(ans, T[i].maxv[1]);
        printf("%d\n", ans);
    }
    return 0;
}
