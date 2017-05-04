//
//  Created by TaoSama on 2017-04-29
//  Copyright (c) 2017 TaoSama. All rights reserved.
//
#pragma comment(linker, "/STACK:102400000,102400000")
#include <bits/stdc++.h>

using namespace std;
#define pr(x) cerr << #x << " = " << x << "  "
#define prln(x) cerr << #x << " = " << x << endl
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

typedef long long LL;
LL f[20][11][11], digit[20];

LL dfs(int i, int a, int b, bool first, bool e) {
    if(!i) return a == b;
    if(!e && ~f[i][a][b]) return f[i][a][b];
    LL ret = 0;
    int to = e ? digit[i] : 9;
    for(int d = 0; d <= to; ++d) {
        int newA = a, newB = b;
        if(first) {
            if(d) newA = newB = d;
            else if(i == 1) newA = newB = 0;
        } else newB = d;
        ret += dfs(i - 1, newA, newB, first && !d, e && d == to);
    }
    return e ? ret : f[i][a][b] = ret;
}

LL calc(LL x) {
    int cnt = 0;
    for(; x; x /= 10) digit[++cnt] = x % 10;
    return dfs(cnt, 10, 10, 1, 1);
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    memset(f, -1, sizeof f);
    int t; scanf("%d", &t);
    while(t--) {
        LL l, r; scanf("%lld%lld", &l, &r);
        printf("%lld\n", calc(r) - calc(l - 1));
    }

    return 0;
}
