//
//  Created by TaoSama on 2015-08-22
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
const int N = 5e4 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

#define root 1, n, 1
#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1 | 1

int n;
long long minv[N * 3];
long long dp[N];

const long long LLINF = 0x3f3f3f3f3f3f3f3fLL;

void push_up(int rt) {
    minv[rt] = min(minv[rt << 1], minv[rt << 1 | 1]);
}

void push_down(int rt) {
    if(minv[rt] != LLINF) {
        minv[rt << 1] = min(minv[rt << 1], minv[rt]);
        minv[rt << 1 | 1] = min(minv[rt << 1 | 1], minv[rt]);
        minv[rt] = LLINF;
    }
}

void build(int l, int r, int rt) {
    minv[rt] = LLINF;
    if(l == r) return;
    int m = l + r >> 1;
    build(lson);
    build(rson);
    push_up(rt);
}

void update(int L, int R, long long v, int l, int r, int rt) {
    if(L <= l && r <= R) {
        minv[rt] = min(minv[rt], v);
        return;
    }
    push_down(rt);
    int m = l + r >> 1;
    if(L <= m) update(L, R, v, lson);
    if(R > m) update(L, R, v, rson);
}

long long query(int o, int l, int r, int rt) {
    if(l == r) return minv[rt];
    push_down(rt);
    int m = l + r >> 1;
    if(o <= m) return query(o, lson);
    else return query(o, rson);
}

int cost[N], tim[N];

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d", &n) == 1) {
        for(int i = 1; i <= n; ++i) scanf("%d", cost + i);
        for(int i = 1; i <= n; ++i) scanf("%d", tim + i);

        dp[0] = 0;
        build(1, n, 1);
        for(int i = 1; i <= n; ++i) {
            int r = i + tim[i] - 1;
//          printf("%d: %d\n", i, r);
            long long cur = dp[i - 1] + cost[i];
            update(i, r, cur, root);
            dp[i] = query(i, root);
        }
        printf("%lld\n", dp[n]);
    }
    return 0;
}
