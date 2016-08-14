//
//  Created by TaoSama on 2016-08-09
//  Copyright (c) 2016 TaoSama. All rights reserved.
//
#pragma comment(linker, "/STACK:102400000,102400000")
#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
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
const int N = 20 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

typedef long long LL;
int p, n, m, a[N];
LL f[N][N], fact[N];

LL C(int n, int m) {
    if(n < m) return 0;
    return fact[n] / fact[m] / fact[n - m];
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    fact[0] = 1;
    for(int i = 1; i <= 20; ++i) fact[i] = fact[i - 1] * i;
    f[0][0] = 1;
    for(int i = 0; i <= 20; ++i) {
        for(int j = 0; j <= i; ++j) {
            f[i + 1][j] += f[i][j];
            f[i][j + 1] += f[i][j];
        }
    }

    int t; scanf("%d", &t);
    while(t--) {
        scanf("%d%d%d", &p, &n, &m);
        for(int i = 0; i < m; ++i) scanf("%d", a + i);

        LL up = 0, dw = fact[n + m];
        for(int i = 1; i < 1 << m; ++i) {
            int sum = 0, k = 0;
            for(int j = 0; j < m; ++j)
                if(i >> j & 1) ++k, sum += a[j];
            if(sum < p) continue;
            up += f[k - 1][k] * C(n, k - 1) * fact[k - 1] * fact[k]
                  * fact[n + m - (2 * k - 1)];

            if(k == m && k - 1 < n) up += f[n][m] * fact[n] * fact[m];
        }

        LL g = __gcd(up, dw);
        printf("%I64d/%I64d\n", up / g, dw / g);
    }

    return 0;
}

