//
//  Created by TaoSama on 2016-04-10
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
const int N = 3e3 + 10, INF = 0x3f3f3f3f, MOD = 19970303;

int n, a[N], s[N];
long long f[2][N];
void add(int& x, int y) {
    if((x += y) >= MOD) x -= MOD;
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d", &n) == 1) {
        for(int i = 1; i <= n; ++i) scanf("%d", a + i), s[i] = a[i];
        sort(s + 1, s + 1 + n);

        int p = 0;
        memset(f[p], 0, sizeof f[p]);
        for(int i = 1; i <= n; ++i) {
            memset(f[!p], 0, sizeof f[!p]);
            for(int j = 1; j <= n; ++j)
                f[!p][j] = f[p][j] + abs(a[i] - s[j]);
            for(int j = 2; j <= n; ++j)
                f[!p][j] = min(f[!p][j], f[!p][j - 1]);
            p = !p;
        }
        printf("%lld\n", f[p][n] % MOD);
    }
    return 0;
}
