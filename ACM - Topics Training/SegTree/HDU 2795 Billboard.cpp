//
//  Created by TaoSama on 2015-09-18
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
const int N = 2e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int w, n, q;

#define root 1, n, 1
#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1 | 1

int maxv[N << 2];

void push_up(int rt) {
    maxv[rt] = max(maxv[rt << 1], maxv[rt << 1 | 1]);
}

void build(int l, int r, int rt) {
    maxv[rt] = w;
    if(l == r) return;
    int m = l + r >> 1;
    build(lson);
    build(rson);
}

int query(int v, int l, int r, int rt) {
    if(l == r) {
        maxv[rt] -= v;
        return l;
    }
    int m = l + r >> 1;
    int ret = maxv[rt << 1] >= v ? query(v, lson) : query(v, rson);
    push_up(rt);
    return ret;
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d%d%d", &n, &w, &q) == 3) {
        if(n > q) n = q;
        build(root);
        while(q--) {
            int x; scanf("%d", &x);
            if(maxv[1] < x) puts("-1");
            else printf("%d\n", query(x, root));
        }
    }
    return 0;
}
