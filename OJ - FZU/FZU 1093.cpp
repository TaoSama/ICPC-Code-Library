//
//  Created by TaoSama on 2016-09-09
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
const int N = 50 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, m;
double f[N][N][15];

#define rep(i, a, b) for(int i = a; i <= b; ++i)

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d%d", &n, &m) == 2) {
        rep(i, 1, n) {
            rep(j, 1, n) {
                int x; scanf("%d", &x);
                rep(k, 0, m) {
                    if(i != j && !x) f[i][j][k] = INF;
                    else f[i][j][k] = x / pow(2.0, k);
                }
            }
        }

        rep(k, 1, n) rep(i, 1, n) rep(j, 1, n) rep(x, 0, m) rep(y, 0, x)
        f[i][j][x] = min(f[i][j][x], f[i][k][y] + f[k][j][x - y]);

        printf("%.2f\n", f[1][n][m]);
    }
    return 0;
}
