
//  Created by TaoSama.
//  Copyright (c) 2017 TaoSama. All rights reserved.
//
#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, q;
int a[N];
int mp[N], pre[N], nxt[N];
int ans[N];
pair<int, int> t[N << 2];
vector<pair<int, int>> qs[N];

void down(int rt) {
    t[rt << 1] = max(t[rt << 1], t[rt]);
    t[rt << 1 | 1] = max(t[rt << 1 | 1], t[rt]);
}

void update(int L, int R, pair<int, int> v, int l, int r, int rt) {
    if(L <= l && r <= R) {
        t[rt] = max(t[rt], v);
        // cout << rt << ' ' << t[rt].first << ' ' << t[rt].second << endl;
        return;
    }
    down(rt);
    int m = (l + r) / 2;
    if(L <= m) update(L, R, v, l, m, rt << 1);
    if(R > m) update(L, R, v, m + 1, r, rt << 1 | 1);
}

pair<int, int> query(int o, int l, int r, int rt) {
    if(l == r) {
        return t[rt];
    }
    down(rt);
    int m = (l + r) / 2;
    if(o <= m) return query(o, l, m, rt << 1);
    return query(o, m + 1, r, rt << 1 | 1);
}

int main(){
#ifdef LOCAL
    freopen("/Users/didi/ACM/in.txt", "r", stdin);
//  freopen("/Users/didi/ACM/out.txt", "w", stdout);
#endif
    ios::sync_with_stdio(0); cin.tie(0);
    
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i) scanf("%d", a + i);
    scanf("%d", &q);
    for(int i = 1; i <= q; ++i) {
        int l, r; scanf("%d%d", &l, &r);
        qs[r].push_back({l, i});
    }
    memset(mp, 0, sizeof mp);
    for(int i = 1; i <= n; ++i) {
        if(!mp[a[i]]) pre[i] = 0;
        else pre[i] = mp[a[i]];
        mp[a[i]] = i;
    }
    memset(mp, 0, sizeof mp);
    for(int i = n; i >= 1; --i) {
        if(!mp[a[i]]) nxt[i] = n + 1;
        else nxt[i] = mp[a[i]];
        mp[a[i]] = i;
    }
    for(int i = 1; i <= n; ++i) {
        update(pre[i] + 1, i, {nxt[i], a[i]}, 1, n, 1);
        // cout << "u " << pre[i] + 1 << ' ' << i << ' ' << nxt[i] << ' ' << a[i] << endl;;
        for(const auto& p : qs[i]) {
            auto o = query(p.first, 1, n, 1);
            // cout << "q " << p.first << ' ' << p.second << endl;
            // cout << "r " << o.first << ' ' << o.second << endl;
            ans[p.second] = o.first > i ? o.second : 0;
        }
    }
    for(int i = 1; i <= q; ++i) printf("%d\n", ans[i]);
    return 0;
}
