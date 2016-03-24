//
//  Created by TaoSama on 2015-11-04
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

int a[N], minv[N << 2];

void push_up(int rt) {
    minv[rt] = min(minv[rt << 1], minv[rt << 1 | 1]);
}

void build(int l, int r, int rt) {
    minv[rt] = INF;
    if(l == r) {
        scanf("%d", a + l);
        minv[rt] = a[l];
        return;
    }
    int m = l + r >> 1;
    build(l, m, rt << 1);
    build(m + 1, r, rt << 1 | 1);
    push_up(rt);
}

void update(int o, int v, int l, int r, int rt) {
    if(l == r) {
        a[l] = minv[rt] = v;
        return;
    }
    int m = l + r >> 1;
    if(o <= m) update(o, v, l, m, rt << 1);
    else update(o, v, m + 1, r, rt << 1 | 1);
    push_up(rt);
}

int query(int L, int R, int l, int r, int rt) {
    if(L <= l && r <= R) return minv[rt];
    int m = l + r >> 1, ret = INF;
    if(L <= m) ret = min(ret, query(L, R, l, m, rt << 1));
    if(R > m) ret = min(ret, query(L, R, m + 1, r, rt << 1 | 1));
    return ret;
}

int b[30], c, x;
void handle(char *op) {
    c = x = 0;
    for(int i = 0; op[i]; ++i) {
        if(isdigit(op[i])) x = x * 10 + op[i] - '0';
        else {
            b[++c] = x;
            x = 0;
        }
    }
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d%d", &n, &q) == 2) {
        build(1, n, 1);
        while(q--) {
            char op[35]; scanf("%s", op);
            handle(op + 6);
            if(*op == 's') {
                int f = a[b[1]];
                for(int i = 1; i < c; ++i)
                    update(b[i], a[b[i + 1]], 1, n, 1);
                update(b[c], f, 1, n, 1);
            } else printf("%d\n", query(b[1], b[2], 1, n, 1));
        }
    }
    return 0;
}
