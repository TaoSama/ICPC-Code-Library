//
//  Created by TaoSama on 2015-09-30
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

int n, q, A[N];
int id[11][10];

#define root 1, n, 1
#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1 | 1

int add[N << 2][55];
bool lazy[N << 2];

int cur;

void push_down(int rt) {
    if(lazy[rt]) {
        for(int i = 0; i < 55; ++i) {
            add[rt << 1][i] += add[rt][i];
            add[rt << 1 | 1][i] += add[rt][i];
            add[rt][i] = 0;
        }
        lazy[rt << 1] = lazy[rt << 1 | 1] = lazy[rt];
        lazy[rt] = 0;
    }
}
void build(int l, int r, int rt) {
    lazy[rt] = 0;
    for(int i = 0; i < 55; ++i) add[rt][i] = 0;
    if(l == r) return;
    int m = l + r >> 1;
    build(lson);
    build(rson);
}
void update(int L, int R, int v, int l, int r, int rt) {
    if(L <= l && r <= R) {
        lazy[rt] = 1;
        add[rt][cur] += v;
        return;
    }
    int m = l + r >> 1;
    push_down(rt);
    if(L <= m) update(L, R, v, lson);
    if(R > m) update(L, R, v, rson);
}
int query(int o, int l, int r, int rt) {
    if(l == r) {
        int ret = A[l];
        for(int k = 1; k <= 10; ++k) ret += add[rt][id[k][o % k]];
        return ret;
    }
    int m = l + r >> 1;
    push_down(rt);
    if(o <= m) return query(o, lson);
    else return query(o, rson);
}


void gao() {
    int cnt = 0;
    for(int i = 1; i <= 10; ++i) for(int j = 0; j < i; ++j) id[i][j] = cnt++;
    //cnt = 55;
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    gao();
    while(scanf("%d", &n) == 1) {
        for(int i = 1; i <= n; ++i) scanf("%d", A + i);
        scanf("%d", &q);
        build(root);
        while(q--) {
            int op, a; scanf("%d%d", &op, &a);
            if(op == 1) {
                int b, k, c; scanf("%d%d%d", &b, &k, &c);
                cur = id[k][a % k];
                update(a, b, c, root);
            } else printf("%d\n", query(a, root));
        }
    }
    return 0;
}
