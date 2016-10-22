//
//  Created by TaoSama on 2016-05-10
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
const int N = 2e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, m, q[N];
double sum[N], rev[N], pre[N];
double f[55][N];

double up(int p, int k, int j) {
    return (f[p][j] - pre[j] + rev[j] * sum[j]) -
           (f[p][k] - pre[k] + rev[k] * sum[k]);
}

double dw(int k, int j) {
    return sum[j] - sum[k];
}

bool check(int p, int k, int j, int i) {
    return up(p, k, j) * dw(j, i) >= up(p, j, i) * dw(k, j);
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);
    clock_t _ = clock();

    while(scanf("%d%d", &n, &m) == 2) {
        for(int i = 1; i <= n; ++i) {
            int x; scanf("%d", &x);
            sum[i] = sum[i - 1] + x;
            rev[i] = rev[i - 1] + 1. / x;
            pre[i] = pre[i - 1] + sum[i] / x;
            f[1][i] = pre[i];
        }

        for(int j = 2; j <= m; ++j) {
            int L = 0, R = 0;
            q[R++] = 0;
            for(int i = 1; i <= n; ++i) {
                while(L + 1 < R && up(j - 1, q[L], q[L + 1]) <=
                        rev[i] * dw(q[L], q[L + 1])) ++L;
                int k = q[L];
                f[j][i] = f[j - 1][k] + pre[i] - pre[k] - sum[k] * (rev[i] - rev[k]);
                while(L + 1 < R && check(j - 1, q[R - 2], q[R - 1], i)) --R;
                q[R++] = i;
            }
        }
        printf("%.12f\n", f[m][n]);
    }

#ifdef LOCAL
    printf("\nTime cost: %.2fs\n", 1.0 * (clock() - _) / CLOCKS_PER_SEC);
#endif
    return 0;
}
