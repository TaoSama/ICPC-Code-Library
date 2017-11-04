//
//  Created by TaoSama on 2017-05-17
//  Copyright (c) 2017 TaoSama. All rights reserved.
//
#pragma comment(linker, "/STACK:102400000,102400000")
#include <bits/stdc++.h>

using namespace std;
#define pr(x) cerr << #x << " = " << x << "  "
#define prln(x) cerr << #x << " = " << x << endl
const int N = 20 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, k, p;
typedef long long LL;
LL x;

int digit[N];
LL f[N][N];

LL dfs(int i, int c, int e) {
    if(!i) return c == p;
    if(!e && ~f[i][c]) return f[i][c];
    LL ret = 0;
    int to = e ? digit[i] : n;
    for(int d = 1; d <= to; ++d) {
        ret += dfs(i - 1, c + (d == 1), e && d == to);
    }
    return e ? ret : f[i][c] = ret;
}

LL calc(LL x) {
    int cnt = 0;
    memset(f, -1, sizeof f);
    for(int i = 1; i <= k; ++i, x /= n) digit[i] = x % n + 1;
    return dfs(k, 0, 1);
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d%d%d%lld", &n, &k, &p, &x) == 4) {
        LL l = 0, r = 0, ans = -1;
        for(int i = 0; i < k; ++i) r = r * n + n - 1;
        while(l <= r) {
            LL m = l + r >> 1;
            if(calc(m) >= x) ans = m, r = m - 1;
            else l = m + 1;
        }
        if(ans == -1) puts("poor god wan");
        else {
            char s[20] = {};
            for(int i = k; i; ans /= n, --i)
                s[i] = '0' + ans % n + 1;
            puts(s + 1);
        }
    }

    return 0;
}
