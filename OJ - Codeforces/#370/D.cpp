//
//  Created by TaoSama on 2016-09-11
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
#include <complex>

using namespace std;
#define pr(x) cout << #x << " = " << x << "  "
#define prln(x) cout << #x << " = " << x << endl
const int N = 4e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int a, b, k, t;
const int OFF = 2e5 + 1;
int f[2][N], s[2][N];

int getSum(int p, int l, int r, int D) {
    l = max(l, -D), r = min(r, D);
    if(l > r) return 0;
    l += OFF; r += OFF;
    return (s[p][r] - s[p][l - 1] + MOD) % MOD;
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(cin >> a >> b >> k >> t) {
        int D = 2 * t * k;

        int p = 0;
        memset(f[p], 0, sizeof f[p]);
        memset(s[p], 0, sizeof s[p]);
        f[p][OFF] = 1;
        for(int i = OFF; i <= D + OFF; ++i) s[p][i] = 1;

        for(int i = 1; i <= 2 * t; ++i) {
            for(int j = -D; j <= D; ++j) {
                f[!p][j + OFF] = getSum(p, j - k, j + k, D);
                s[!p][j + OFF] = (s[!p][j - 1 + OFF] + f[!p][j + OFF]) % MOD;
            }
            p = !p;
        }
        int st = b - a + 1;
        int ans = getSum(p, st, D, D);
        cout << ans << endl;
    }

    return 0;
}
