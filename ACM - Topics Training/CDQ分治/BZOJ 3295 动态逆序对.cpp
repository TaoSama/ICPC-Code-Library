//
//  Created by TaoSama on 2016-03-01
//  Copyright (c) 2016 TaoSama. All rights reserved.
//
#pragma comment(linker, "/STACK:1024000000,1024000000")
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
int a[N], wh[N];

struct Query {
    int tim, pos, val;
} qs[N], tmp[N];

struct BIT {
    int n, tim, vis[N], b[N];
    void init(int _n) {
        n = _n;
        tim = 0;
        memset(vis, 0, sizeof vis);
    }
    void newOne() {++tim;}
    void add(int i, int v, int dir) {
        for(; i && i <= n; i += dir * (i & -i)) {
            if(vis[i] != tim) vis[i] = tim, b[i] = 0;
            b[i] += v;
        }
    }
    int sum(int i, int dir) {
        int ret = 0;
        for(; i && i <= n; i += dir * (i & -i))
            if(vis[i] == tim) ret += b[i];
        return ret;
    }
} bit;

int cnt[N]; //inversions caused by i-th number
long long more[N], ans; //inversions of i-th deleting sequence

bool cmpByPos(const Query& x, const Query& y) {
    return x.pos < y.pos;
}

void cdq(int l, int r) {
    if(l == r) {
        printf("%lld\n", ans);
        ans += more[l] - cnt[qs[l].pos];
        return;
    }

    int m = l + r >> 1;
    cdq(l, m);

    for(int i = l; i <= r; ++i) {
        tmp[i] = qs[i];
        tmp[i].tim *= i <= m ? -1 : 1;
    }
    sort(tmp + l, tmp + r + 1, cmpByPos);

    bit.newOne();
    for(int i = l; i <= r; ++i) {
        if(tmp[i].tim < 0) bit.add(tmp[i].val, 1, -1);
        else more[tmp[i].tim] += bit.sum(tmp[i].val + 1, 1);
    }
    bit.newOne();
    for(int i = r; i >= l; --i) {
        if(tmp[i].tim < 0) bit.add(tmp[i].val, 1, 1);
        else more[tmp[i].tim] += bit.sum(tmp[i].val - 1, -1);
    }

    cdq(m + 1, r);
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d%d", &n, &q) == 2) {
        bit.init(n);
        memset(more, 0, sizeof more);

        ans = 0;
        bit.newOne();
        for(int i = 1; i <= n; ++i) {
            scanf("%d", a + i);
            wh[a[i]] = i;
            cnt[i] = bit.sum(a[i] + 1, 1); //bigger
            bit.add(a[i], 1, -1);
            ans += cnt[i];
        }
        bit.newOne();
        for(int i = n; i; --i) {
            cnt[i] += bit.sum(a[i] - 1, -1); //smaller
            bit.add(a[i], 1, 1);
        }

        for(int i = 1; i <= q; ++i) {
            int x; scanf("%d", &x);
            qs[i] = (Query) {i, wh[x], x};
        }
        cdq(1, q);
    }
    return 0;
}
