//
//  Created by TaoSama on 2016-07-30
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
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n;
typedef long long LL;
LL k;
LL f[35][N], g[35][N];
int nxt[35][N];

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d%I64d", &n, &k) == 2) {
        for(int i = 0; i < n; ++i) scanf("%d", nxt[0] + i);
        for(int i = 0; i < n; ++i) {
            scanf("%I64d", f[0] + i);
            g[0][i] = f[0][i];
        }

        for(int i = 1; 1LL << i <= k; ++i) {
            for(int u = 0; u < n; ++u) {
                f[i][u] = f[i - 1][u] + f[i - 1][nxt[i - 1][u]];
                nxt[i][u] = nxt[i - 1][nxt[i - 1][u]];
                g[i][u] = min(g[i - 1][u], g[i - 1][nxt[i - 1][u]]);
            }
        }

        for(int i = 0; i < n; ++i) {
            LL sum = 0, minv = INF;
            int u = i;
            for(int j = 0; j < 35; ++j) {
                if(k >> j & 1) {
                    sum += f[j][u];
                    minv = min(minv, g[j][u]);
                    u = nxt[j][u];
                }
            }
            printf("%I64d %I64d\n", sum, minv);
        }

    }

    return 0;
}
