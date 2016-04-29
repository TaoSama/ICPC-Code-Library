//
//  Created by TaoSama on 2016-04-22
//  Copyright (c) 2016 TaoSama. All rights reserved.
//
#pragma comment(linker, "/STACK:102400000,102400000")
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
const int N = 1e6 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

typedef long long LL;
LL g[N];
LL inv[N];

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

//    f[0][0] = 1;
//    for(int i = 1; i <= 100; ++i) {
//        for(int j = 0; j <= 100; ++j) {
//            if(j > 0) f[i][j] += f[i - 1][j - 1];
//            f[i][j] += f[i - 1][j];
//            f[i][j] += f[i - 1][j + 1];
//        }
//    }
//    for(int i = 1; i <= 10; ++i) printf("f[%d] = %d\n", i, f[i][0]);

    inv[0] = inv[1] = 1;
    for(int i = 2; i < N; i++)
        inv[i] = (MOD - MOD / i) * inv[MOD % i] % MOD;

    g[0] = g[1] = 1;
    for(int i = 2; i < N; ++i) {
        g[i] = ((2 * i + 1) * g[i - 1] + (3 * i - 3) * g[i - 2]) % MOD;
        g[i] = g[i] * inv[i + 2] % MOD;
        g[i] = (g[i] + MOD) % MOD;
    }

    int t; scanf("%d", &t);
    while(t--) {
        int n; scanf("%d", &n);
        printf("%I64d\n", g[n]);
    }

    return 0;
}
