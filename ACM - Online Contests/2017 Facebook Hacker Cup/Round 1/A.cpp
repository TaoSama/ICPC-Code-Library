//
//  Created by TaoSama on 2017-01-15
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
const int N = 3e2 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, m, c[N][N];
int f[N][N];

int main() {
#ifdef LOCAL
    freopen("pie_progress.txt", "r", stdin);
    freopen("pie_progress_out.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);

    int t; scanf("%d", &t);
    while(t--) {
        scanf("%d%d", &n, &m);
        for(int i = 1; i <= n; ++i) {
            for(int j = 1; j <= m; ++j) scanf("%d", c[i] + j);
            sort(c[i] + 1, c[i] + 1 + m);
            for(int j = 1; j <= m; ++j) c[i][j] += c[i][j - 1];
        }

        memset(f, 0x3f, sizeof f);
        f[0][0] = 0;
        for(int i = 0; i < n; ++i) {
            for(int j = i; j <= n; ++j) {
                for(int k = 0; k <= m && j + k <= n; ++k) {
                    f[i + 1][j + k] = min(f[i + 1][j + k], f[i][j] + c[i + 1][k] + k * k);
                }
            }
        }
        static int kase = 0;
        printf("Case #%d: %d\n", ++kase, f[n][n]);
    }

    return 0;
}
