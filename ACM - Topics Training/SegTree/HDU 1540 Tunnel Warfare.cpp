//
//  Created by TaoSama on 2015-09-17
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

int n, q;
int lsum[N << 2], rsum[N << 2], stk[N], top;

#define root 1, n, 1
#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1 | 1

void push_up(int rt, int m) {
    lsum[rt] = lsum[rt << 1];
    rsum[rt] = rsum[rt << 1 | 1];
    if(lsum[rt << 1] == m - (m >> 1)) lsum[rt] += lsum[rt << 1 | 1];
    if(rsum[rt << 1 | 1] == m >> 1) rsum[rt] += rsum[rt << 1];
}

void build(int l, int r, int rt) {
    lsum[rt] = rsum[rt] = r - l + 1;
    if(l == r) return;
    int m = l + r >> 1;
    build(lson);
    build(rson);
}

void update(int o, int v, int l, int r, int rt) {
    if(l == r) {
        lsum[rt] = rsum[rt] = v;
        return;
    }
    int m = l + r >> 1;
    if(o <= m) update(o, v, lson);
    else update(o, v, rson);
    push_up(rt, r - l + 1);
}

int query(int o, int l, int r, int rt) {
    if(l == r) return 0;
    int m = l + r >> 1;
    if(o >= m - rsum[rt << 1] + 1 && o <= m + lsum[rt << 1 | 1])
        return rsum[rt << 1] + lsum[rt << 1 | 1];
    if(o <= m) return query(o, lson);
    else return query(o, rson);
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d%d", &n, &q) == 2) {
        build(root);
        top = 0;
        while(q--) {
            char op[2]; int x;
            scanf("%s", op);
            if(*op == 'R') {
                x = stk[--top];
                update(x, 1, root);
            } else {
                scanf("%d", &x);
                if(*op == 'D') {
                    stk[top++] = x;
                    update(x, 0, root);
                } else printf("%d\n", query(x, root));
            }
        }
    }
    return 0;
}
