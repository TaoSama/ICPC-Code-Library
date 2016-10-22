//
//  Created by TaoSama on 2015-09-16
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

int n, q;
long long sum[N << 2];

#define root 1, n, 1
#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1 | 1

void push_up(int rt) {
    sum[rt] = sum[rt << 1] + sum[rt << 1 | 1];
}

void build(int l, int r, int rt) {
    if(l == r) {
        scanf("%I64d", &sum[rt]);
        return;
    }
    int m = l + r >> 1;
    build(lson);
    build(rson);
    push_up(rt);
}

void update(int L, int R, int l, int r, int rt) {
    if(sum[rt] == r - l + 1) return;
    if(l == r) {
        sum[rt] = sqrt(sum[rt]);
        return;
    }
    int m = l + r >> 1;
    if(L <= m) update(L, R, lson);
    if(R > m) update(L, R, rson);
    push_up(rt);
}

long long query(int L, int R, int l, int r, int rt) {
    if(L <= l && r <= R) {
        return sum[rt];
    }
    int m = l + r >> 1;
    long long ret = 0;
    if(L <= m) ret += query(L, R, lson);
    if(R > m) ret += query(L, R, rson);
    return ret;
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int kase = 0;
    while(scanf("%d", &n) == 1) {
        build(root);
        scanf("%d", &q);
        printf("Case #%d:\n", ++kase);
        while(q--) {
            int op, l, r; scanf("%d%d%d", &op, &l, &r);
            if(l > r) swap(l, r);
            if(op) printf("%I64d\n", query(l, r, root));
            else update(l, r, root);
        }
        puts("");
    }
    return 0;
}
