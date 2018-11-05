
//  Created by TaoSama.
//  Copyright (c) 2017 TaoSama. All rights reserved.
//
#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int maxv[N << 2];

void down(int rt) {
    maxv[rt << 1] = max(maxv[rt << 1], maxv[rt]);
    maxv[rt << 1 | 1] = max(maxv[rt << 1 | 1], maxv[rt]);
}

void update(int L, int R, int v, int l, int r, int rt) {
    if (L <= l && r <= R) {
        maxv[rt] = max(maxv[rt], v);
        return;
    }
    down(rt);
    int m = (l + r) / 2;
    if (L <= m) update(L, R, v, l, m, rt << 1);
    if (R > m) update(L, R, v, m + 1, r, rt << 1 | 1);
}

int query(int o, int l, int r, int rt) {
    if(l == r) return maxv[rt];
    int m = (l + r) / 2;
    down(rt);
    if(o <= m) return query(o, l, m, rt << 1);
    return query(o, m + 1, r, rt << 1 | 1);
}

int a[N], b[N], m1[N], m2[N];

int main(){
#ifdef LOCAL
    freopen("/Users/didi/ACM/in.txt", "r", stdin);
//  freopen("/Users/didi/ACM/out.txt", "w", stdout);
#endif
    ios::sync_with_stdio(0); cin.tie(0);
    
    int n, q;
    while(cin >> n >> q) {
        memset(m1, 0x3f, sizeof m1);
        memset(m2, 0, sizeof m2);
        for(int i = 1; i <= n; ++i) {
            cin >> a[i];
            m1[a[i]] = min(m1[a[i]], i);
            m2[a[i]] = max(m2[a[i]], i);
        }
        memset(maxv, 0, sizeof maxv);
        update(1, n, 1, 1, n, 1);
        for(int i = 2; i <= q; ++i) {
            if(m2[i] == 0) continue;
            update(m1[i], m2[i], i, 1, n, 1);
        }
        int ok = 1;
        for(int i = 1; i <= n; ++i) {
            b[i] = query(i, 1, n, 1);
            if(a[i] == 0) continue;
            ok &= a[i] == b[i];
        }
        if(m2[q] == 0) {
            ok = 0;
            for(int i = 1; i <= n; ++i) {
                if(a[i] == 0) {
                    b[i] = q;
                    ok = 1;
                    break;
                }
            }
        }
        if(ok) {
            cout << "YES\n";
            for(int i = 1; i <= n; ++i) cout << b[i] << " \n"[i == n];
        }
        else cout << "NO\n";
    }
    return 0;
}
