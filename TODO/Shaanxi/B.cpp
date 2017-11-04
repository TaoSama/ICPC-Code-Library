//
//  Created by TaoSama on 2017-05-17
//  Copyright (c) 2017 TaoSama. All rights reserved.
//
#pragma comment(linker, "/STACK:102400000,102400000")
#include <bits/stdc++.h>

using namespace std;
#define pr(x) cerr << #x << " = " << x << "  "
#define prln(x) cerr << #x << " = " << x << endl
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, m;
typedef long long LL;
int a[N], b[N], c[N], d[N];

int ans[N];

int quick(int x, int n, int mod) {
    int ret = 1;
    for(; n; n >>= 1) {
        if(n & 1) ret = 1LL * ret * x % mod;
        x = 1LL * x * x % mod;
    }
    return ret;
}

void solve(int l, int r, int aL, int aR) {
    if(l > r) return;
    int x = l + r >> 1;
    pair<int, int> cur = {d[x], d[x]};
    LL p = quick(b[x], aL - 1, d[x]);
    for(int i = aL; i <= aR; ++i) {
        p = p * b[x] % d[x];
        int ret = (1LL * a[x] * p  + c[x]) % d[x];
        cur = min(cur, {ret, i});
    }
//  printf("%d %d %d %d ...\n", l, r, aL, aR);
    ans[x] = cur.second;
//  printf("%d = %d\n", x, cur.second);
    solve(l, x - 1, aL, ans[x]);
    solve(x + 1, r, ans[x], aR);
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d%d", &n, &m) == 2) {
        for(int i = 1; i <= n; ++i) scanf("%d%d%d%d", a + i, b + i, c + i, d + i);
        solve(1, n, 1, m);
        static int kase = 0;
        printf("Case #%d\n", ++kase);
        for(int i = 1; i <= n; ++i) printf("%d\n", ans[i]);
    }

    return 0;
}
