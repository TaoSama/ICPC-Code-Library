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
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;
const int Q = 5e4 + 10;

typedef long long LL;

struct Query {
    int a, b; LL c;
    int id;
} q[Q], q1[Q], q2[Q];

struct SegTree {
    LL sum[N << 2], add[N << 2];
    void pushUp(int rt) {
        sum[rt] = sum[rt << 1] + sum[rt << 1 | 1];
    }
    void pushDown(int rt, int m) {
        if(add[rt]) {
            sum[rt << 1] += (m - m / 2) * add[rt];
            sum[rt << 1 | 1] += (m / 2) * add[rt];
            add[rt << 1] += add[rt];
            add[rt << 1 | 1] += add[rt];
            add[rt] = 0;
        }
    }
    void update(int L, int R, int v, int l, int r, int rt) {
        if(L <= l && r <= R) {
            sum[rt] += v * (r - l + 1);
            add[rt] += v;
            return;
        }
        pushDown(rt, r - l + 1);
        int m = l + r >> 1;
        if(L <= m) update(L, R, v, l, m, rt << 1);
        if(R > m) update(L, R, v, m + 1, r, rt << 1 | 1);
        pushUp(rt);
    }
    LL query(int L, int R, int l, int r, int rt) {
        if(L <= l && r <= R) return sum[rt];
        pushDown(rt, r - l + 1);
        int m = l + r >> 1;
        LL ret = 0;
        if(L <= m) ret += query(L, R, l, m, rt << 1);
        if(R > m) ret += query(L, R, m + 1, r, rt << 1 | 1);
        return ret;
    }
} T;

int n, m;
int ans[Q];

void solve(int L, int R, int l, int r) {
    if(L > R) return;
    if(l == r) {
        for(int i = L; i <= R; ++i)
            if(q[i].id > 0) ans[q[i].id] = l;
        return;
    }
    int m = l + r >> 1;
    int f = 0, g = 0;
    for(int i = L; i <= R; ++i) {
        if(q[i].id < 0) {
            if(q[i].c <= m) {
                T.update(q[i].a, q[i].b, 1, 1, n, 1);
//              printf("add %d: %d %d %lld %d\n", i, q[i].a, q[i].b, q[i].c, m);
                q1[f++] = q[i];
            } else q2[g++] = q[i];
        } else {
            LL small = T.query(q[i].a, q[i].b, 1, n, 1);
//          printf("query %d: %d %d %lld small=%lld\n", i,
//                  q[i].a, q[i].b, q[i].c, small);
            if(small >= q[i].c) q1[f++] = q[i];
            else {
                q[i].c -= small;
                q2[g++] = q[i];
            }
        }
    }
    for(int i = 0; i < f; ++i)
        if(q1[i].id < 0) T.update(q1[i].a, q1[i].b, -1, 1, n, 1);

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
        memset(&T, 0, sizeof T);
        int cnt = 0;
        for(int i = 1; i <= m; ++i) {
            int op, a, b; LL c; scanf("%d%d%d%lld", &op, &a, &b, &c);
            if(op == 1) c = n - c + 1;  //change number so as to be k-th
            q[i] = (Query) {a, b, c, op == 1 ? -1 : ++cnt};
        }
        solve(1, m, 1, 2 * n + 1);
        for(int i = 1; i <= cnt; ++i)
            printf("%d\n", n - ans[i] + 1); //change back
    }
    return 0;
}
