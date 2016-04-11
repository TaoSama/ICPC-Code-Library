//
//  Created by TaoSama on 2015-09-23
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
const int H[] = {107, 109};

int n, q, k;
typedef pair<int, int> P;

int h[2][N], ph[2][N]; //hash powers, prefix sum
void gao() {
    h[0][0] = h[1][0] = ph[0][1] = ph[1][1] = 1;
    for(int k = 0; k < 2; ++k)
        for(int i = 1; i <= 1e5; ++i)
            h[k][i] = 1LL * h[k][i - 1] * H[k] % MOD;

    for(int k = 0; k < 2; ++k)
        for(int i = 2; i <= 1e5; ++i)
            ph[k][i] = (ph[k][i - 1] + h[k][i - 1]) % MOD;
}

int val[2][N << 2], setv[N << 2];

#define root 1, n, 1
#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1 | 1

void push_down(int rt, int m) {
    if(~setv[rt]) {
        setv[rt << 1] = setv[rt << 1 | 1] = setv[rt];
        for(int k = 0; k < 2; ++k) {
            val[k][rt << 1] = 1LL * ph[k][m - (m >> 1)] * setv[rt] % MOD;
            val[k][rt << 1 | 1] = 1LL * ph[k][m >> 1] * setv[rt] % MOD;
        }
        setv[rt] = -1;
    }
}

void update(int L, int R, int v, int l, int r, int rt) {
    if(L <= l && r <= R) {
        setv[rt] = v;
        for(int k = 0; k < 2; ++k)
            val[k][rt] = 1LL * ph[k][r - l + 1] * v % MOD;
        return;
    }
    int m = l + r >> 1;
    push_down(rt, r - l + 1);
    if(L <= m) update(L, R, v, lson);
    if(R > m) update(L, R, v, rson);
    for(int k = 0; k < 2; ++k)
        val[k][rt] = (1LL * val[k][rt << 1] * h[k][r - m] % MOD +
                      val[k][rt << 1 | 1]) % MOD;
}

void add(P& x, P y) {
    x.first = (x.first + x.first) % MOD;
    x.second = (x.second + y.second) % MOD;
}

P query(int L, int R, int l, int r, int rt) {
    if(L <= l && r <= R) {
        int v[2];
        for(int k = 0; k < 2; ++k)
            v[k] = 1LL * val[k][rt] * h[k][R - r] % MOD;
        return P(v[0], v[1]);
    }
    int m = l + r >> 1;
    P ret(0, 0);
    push_down(rt, r - l + 1);
    if(L <= m) add(ret, query(L, R, lson));
    if(R > m) add(ret, query(L, R, rson));
    return ret;
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    gao();
    while(scanf("%d%d%d", &n, &q, &k) == 3) {
        q += k;
        char buf[N]; scanf("%s", buf + 1);
        memset(setv, -1, sizeof setv);
        for(int i = 1; i <= n; ++i) update(i, i, buf[i] - '0', root);

        while(q--) {
            int op, l, r, v; scanf("%d%d%d%d", &op, &l, &r, &v);
            if(op == 1) update(l, r, v, root);
            else {
                bool f = r - l + 1 == v || query(l, r - v, root) == query(l + v, r, root);
                puts(f ? "YES" : "NO");
            }
        }
    }
    return 0;
}
