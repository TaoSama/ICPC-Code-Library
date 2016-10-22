//
//  Created by TaoSama on 2016-02-16
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

using P = pair<int, int>;

struct Point {
    int x, y, z;
    void read() {scanf("%d%d%d", &x, &y, &z);}
    int id;
    bool operator<(const Point& p) const {
        return x < p.x;
    }
} p[N], q[N];

void getMax(P& x, P y) {
    if(x.first < y.first) x = y;
    else if(x.first == y.first) {
        if((x.second += y.second) >= 1 << 30)
            x.second -= 1 << 30;
    }
}

P f[N]; //LIS length, count

int vis[N], kase;
struct BIT {
    int n; P b[N];
    void init(int _n) {
        n = _n;
        for(int i = 1; i <= n; ++i) b[i] = P(0, 0);
    }
    void add(int i, P v) {
        for(; i <= n; i += i & -i) {
            if(vis[i] != kase) vis[i] = kase, b[i] = P(0, 0);
            getMax(b[i], v);
        }
    }
    P sum(int i) {
        P ret(0, 0);
        for(; i; i -= i & -i) if(vis[i] == kase) getMax(ret, b[i]);
        return ret;
    }
} bit;

bool cmpy(const Point& a, const Point& b) {
    return a.y < b.y;
}

void cdq(int l, int r) {
    if(l == r) return;

    int m = l + r >> 1;
    cdq(l, m);

    ++kase;
    for(int i = l; i <= r; ++i)
        q[i] = p[i], q[i].x = i <= m;
    sort(q + l, q + r + 1, cmpy);
    for(int i = l; i <= r; ++i) {
        if(q[i].x) bit.add(q[i].z, f[q[i].id]);
        else {
            P cur = bit.sum(q[i].z);
            ++cur.first;
            getMax(f[q[i].id], cur);
        }
    }
    cdq(m + 1, r);
}

int n;

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int t; scanf("%d", &t);
    while(t--) {
        scanf("%d", &n);
        for(int i = 1; i <= n; ++i) f[i] = P(1, 1);
        vector<int> xs;
        for(int i = 1; i <= n; ++i) {
            p[i].read();
            xs.push_back(p[i].z);
            p[i].id = i;
        }

        sort(xs.begin(), xs.end());
        xs.resize(unique(xs.begin(), xs.end()) - xs.begin());
        for(int i = 1; i <= n; ++i)
            p[i].z = lower_bound(xs.begin(), xs.end(), p[i].z) - xs.begin() + 1;

        bit.init(xs.size());
        sort(p + 1, p + 1 + n);
        cdq(1, n);

        P ans(0, 0);
        for(int i = 1; i <= n; ++i) getMax(ans, f[i]);
        printf("%d %d\n", ans.first, ans.second);
    }
    return 0;
}
