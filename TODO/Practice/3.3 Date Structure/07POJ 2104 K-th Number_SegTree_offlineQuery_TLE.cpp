//
//  Created by TaoSama on 2015-07-17
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

int n, q, a[N], ans[N];
struct P {
    int l, r, k, id;
    bool operator< (const P& rhs) const {
        if(r == rhs.r) return l < rhs.l;
        return r < rhs.r;
    }
} op[N];

int sum[N << 2];

void push_up(int rt) {
    sum[rt] = sum[rt << 1] + sum[rt << 1 | 1];
}

void update(int o, int v, int l, int r, int rt) {
    if(l == r) {
        sum[rt] += v;
        return;
    }
    int m = l + r >> 1;
    if(o <= m) update(o, v, l, m, rt << 1);
    else update(o, v, m + 1, r, rt << 1 | 1);
    push_up(rt);
}

int query(int k, int l, int r, int rt) {
    if(l == r) return l;
    int cnt = sum[rt << 1], m = l + r >> 1;
    if(cnt >= k) return query(k, l, m, rt << 1);
    else return query(k - cnt, m + 1, r, rt << 1 | 1);
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

//    int t; scanf("%d", &t);
    while(scanf("%d%d", &n, &q) == 2) {
        vector<int> xs;
        for(int i = 1; i <= n; ++i) {
            scanf("%d", a + i);
            xs.push_back(a[i]);
        }
        sort(xs.begin(), xs.end());
        xs.resize(unique(xs.begin(), xs.end()) - xs.begin());
        for(int i = 1; i <= n; ++i)
            a[i] = lower_bound(xs.begin(), xs.end(), a[i]) - xs.begin() + 1;

        for(int i = 1; i <= q; ++i) {
            scanf("%d%d%d", &op[i].l, &op[i].r, &op[i].k);
            op[i].id = i;
        }
        sort(op + 1, op + 1 + q);

        memset(sum, 0, sizeof sum);
        int lef = 1, rig = 0;
        for(int i = 1; i <= q; ++i) {
            P& now = op[i];
            while(rig + 1 <= now.r) {
                rig++;
                update(a[rig], 1, 1, xs.size(), 1);
//                prln(a[rig]);
            }
            while(lef < now.l) {
                update(a[lef], -1, 1, xs.size(), 1);
//                prln(a[lef]);
                lef++;
            }
            while(lef - 1 >= now.l) {
                lef--;
                update(a[lef], 1, 1, xs.size(), 1);
//                cout << "+" << endl;
//                prln(a[lef]);
            }
//            pr(lef); prln(rig);
            int idx = query(now.k, 1, xs.size(), 1);
//            prln(idx);
            ans[now.id] = xs[idx - 1];
        }

        for(int i = 1; i <= q; ++i) printf("%d\n", ans[i]);
    }
    return 0;
}
