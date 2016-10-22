//
//  Created by TaoSama on 2016-02-02
//  Copyright (c) 2015 TaoSama. All rights reserved.
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

struct Point {
    int x, y, z;
    int id, sum;
    void read() {
        scanf("%d%d%d", &x, &y, &z);
        sum = 0;
    }
    bool operator<(const Point& p) const {
        if(x != p.x) return x < p.x;
        if(y != p.y) return y < p.y;
        return z < p.z;
    }
    bool operator==(const Point& p) const {
        return x == p.x && y == p.y && z == p.z;
    }
} p[N];

struct BIT {
    int b[N];
    void init() {
        memset(b, 0, sizeof b);
    }
    void add(int i, int v) {
        for(; i <= 1e5; i += i & -i) b[i] += v;
    }
    int sum(int i) {
        int ret = 0;
        for(; i; i -= i & -i) ret += b[i];
        return ret;
    }
} bit;

bool cmpy(Point a, Point b) {
    return a.y < b.y;
}

void cdq(int l, int r) {
    if(l == r) return;
    int m = l + r >> 1;
    cdq(l, m);
    cdq(m + 1, r);
    sort(p + l, p + m + 1, cmpy);
    sort(p + m + 1, p + r + 1, cmpy);
    int j = l;
    for(int i = m + 1; i <= r; ++i) {
        for(; j <= m && p[j].y <= p[i].y; ++j) bit.add(p[j].z, 1);
        p[i].sum += bit.sum(p[i].z);
    }
    for(int i = l; i < j; ++i) bit.add(p[i].z, -1);
}

int n, ans[N];

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int t; scanf("%d", &t);
    while(t--) {
        scanf("%d", &n);
        bit.init();
        for(int i = 1; i <= n; ++i) p[i].read(), p[i].id = i;
        sort(p + 1, p + 1 + n);
        cdq(1, n);
        sort(p + 1, p + 1 + n);
        for(int i = 1, j; i <= n; ++i) {
            int maxv = -INF;
            for(j = i; j <= n && p[j] == p[i]; ++j) maxv = max(maxv, p[j].sum);
            for(j = i; j <= n && p[j] == p[i]; ++j) ans[p[j].id] = maxv;
            i = j - 1;
        }
        for(int i = 1; i <= n; ++i) printf("%d\n", ans[i]);
    }
    return 0;
}
