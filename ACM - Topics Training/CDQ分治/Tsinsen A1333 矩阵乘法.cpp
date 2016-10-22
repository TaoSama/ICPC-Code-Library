//
//  Created by TaoSama on 2016-02-15
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
const int N = 5e2 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;
const int Q = 6e4 + 10;

struct Query {
    int x1, y1, x2, y2, k;
    int id;
} q[N * N + Q], q1[N * N + Q], q2[N * N + Q];

struct BIT {
    int n, b[N][N];
    void init(int _n) {n = _n; memset(b, 0, sizeof b);}
    void add(int x, int y, int v) {
        for(int i = x; i <= n; i += i & -i)
            for(int j = y; j <= n; j += j & -j)
                b[i][j] += v;
    }
    int sum(int x, int y) {
        int ret = 0;
        for(int i = x; i; i -= i & -i)
            for(int j = y; j; j -= j & -j)
                ret += b[i][j];
        return ret;
    }
    int sum(int x1, int y1, int x2, int y2) {
        return sum(x2, y2) - sum(x1 - 1, y2) - sum(x2, y1 - 1)
               + sum(x1 - 1, y1 - 1);
    }
} bit;

int n, m, ans[Q];

void solve(int L, int R, int l, int r) {
    if(L > R) return;
    if(l == r) {
        for(int i = L; i <= R; ++i)
            if(q[i].id) ans[q[i].id] = l;
        return;
    }
    int m = l + r >> 1;
    int f = 0, g = 0;
    for(int i = L; i <= R; ++i) {
        if(!q[i].id) {
            if(q[i].k <= m) {
                bit.add(q[i].x1, q[i].y1, 1);
                q1[f++] = q[i];
            } else q2[g++] = q[i];
        } else {
            int small = bit.sum(q[i].x1, q[i].y1, q[i].x2, q[i].y2);
            if(small >= q[i].k) q1[f++] = q[i];
            else {
                q[i].k -= small;
                q2[g++] = q[i];
            }
        }
    }
    for(int i = 0; i < f; ++i)
        if(!q1[i].id) bit.add(q1[i].x1, q1[i].y1, -1);

    memcpy(q + L, q1, f * sizeof(Query));
    memcpy(q + L + f, q2, g * sizeof(Query));

    solve(L, L + f - 1, l, m);
    solve(L + f, R, m + 1, r);
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d%d", &n, &m) == 2) {
        bit.init(n);
        int idx = 0;
        for(int i = 1; i <= n; ++i) {
            for(int j = 1; j <= n; ++j) {
                int x; scanf("%d", &x);
                q[++idx] = (Query) {i, j, 0, 0, x, 0};
            }
        }
        for(int i = 1; i <= m; ++i) {
            int x1, y1, x2, y2, k;
            scanf("%d%d%d%d%d", &x1, &y1, &x2, &y2, &k);
            q[++idx] = (Query) {x1, y1, x2, y2, k, i};
        }
        solve(1, idx, 1, INF);
        for(int i = 1; i <= m; ++i)
            printf("%d\n", ans[i]);
    }
    return 0;
}
