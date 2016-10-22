//
//  Created by TaoSama on 2016-02-14
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
const int Q = 2e5 + 10;

struct Query {
    int x, y, k;
    int id, type;
    void print() {
        printf("%d %d %d %d %d\n", x, y, k, id, type);
    }
} q[N + Q], q1[N + Q], q2[N + Q];

struct BIT {
    int n, b[N];
    void init(int _n) {n = _n; memset(b, 0, sizeof b);}
    void add(int i, int x) {
        for(; i <= n; i += i & -i) b[i] += x;
    }
    int sum(int i) {
        int ret = 0;
        for(; i; i -= i & -i) ret += b[i];
        return ret;
    }
} bit;

int n, m, a[N];
int ans[Q];

void solve(int qL, int qR, int l, int r) {
    if(qL > qR) return;
    if(l == r) {
        for(int i = qL; i <= qR; ++i)
            if(q[i].type == 2) ans[q[i].id] = l;
        return;
    }
    int m = l + r >> 1;

    //check m
    int f = 0, g = 0;
    for(int i = qL; i <= qR; ++i) {
        if(q[i].type == 1) {
            if(q[i].x <= m) {
                bit.add(q[i].id, q[i].y);
                q1[f++] = q[i];
            } else q2[g++] = q[i];
        } else {
            int small = bit.sum(q[i].y) - bit.sum(q[i].x - 1);
            if(small >= q[i].k) q1[f++] = q[i];
            else {
                q[i].k -= small;
                q2[g++] = q[i];
            }
        }
    }
    //clear
    for(int i = 0; i < f; ++i)
        if(q1[i].type == 1) bit.add(q1[i].id, -q1[i].y);

    //copy back
    memcpy(q + qL, q1, f * sizeof(Query));
    memcpy(q + qL + f, q2, g * sizeof(Query));

    solve(qL, qL + f - 1, l, m);
    solve(qL + f, qR, m + 1, r);
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d", &n) == 1) {
        bit.init(n);
        int idx = 0, cnt = 0;
        for(int i = 1; i <= n; ++i) {
            scanf("%d", a + i);
            q[++idx] = (Query) {a[i], 1, INF, i, 1};
        }
        scanf("%d", &m);
        for(int i = 1; i <= m; ++i) {
            int op, x, y, k;
            scanf("%d%d%d", &op, &x, &y);
            if(op == 2) {
                scanf("%d", &k);
                q[++idx] = (Query) {x, y, k, ++cnt, 2};
            } else {
                q[++idx] = (Query) {a[x], -1, INF, x, 1};
                a[x] = y;
                q[++idx] = (Query) {a[x], 1, INF, x, 1};
            }
        }

//      for(int i = 1; i <= idx; ++i) q[i].print();

        solve(1, idx, 1, INF);
        for(int i = 1; i <= cnt; ++i)
            printf("%d\n", ans[i]);
    }
    return 0;
}
