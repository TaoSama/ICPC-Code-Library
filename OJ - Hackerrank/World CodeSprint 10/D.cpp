//
//  Created by TaoSama on 2017-04-30
//  Copyright (c) 2017 TaoSama. All rights reserved.
//
#pragma comment(linker, "/STACK:102400000,102400000")
#include <bits/stdc++.h>

using namespace std;
#define pr(x) cerr << #x << " = " << x << "  "
#define prln(x) cerr << #x << " = " << x << endl
const int N = 3e3 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

typedef long long LL;
LL f[N][N];

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    f[1][0] = 1;
    for(int i = 2; i < N; ++i) {
        for(int j = 1; j <= i; ++j) {
            //unhappy numbers are not adjacent, make them happy
            f[i][j] = f[i - 1][j - 1] * 2 * (i - 1 - (j - 1)) % MOD;
            //subtract the positions that makes them happy
            f[i][j] += f[i - 1][j] * (i - 2 * (i - 1 - j)) % MOD;
            f[i][j] %= MOD;
        }
    }
    for(int i = 1; i < N; ++i)
        for(int j = i; j >= 0; --j)
            f[i][j] = (f[i][j] + f[i][j + 1]) % MOD;

    int q; scanf("%d", &q);
    while(q--) {
        int n, k; scanf("%d%d", &n, &k);
        printf("%lld\n", f[n][k]);
    }
    return 0;
}
