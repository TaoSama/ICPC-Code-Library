//
//  Created by TaoSama on 2016-08-07
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
const int N = 300 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, a[N][N];
int f[N][N][N];
int d[][2] = {1, 0, 0, 1};

int calc(int ax, int ay, int bx, int by) {
    int ret = a[ax][ay];
    if(ax != bx || ay != by) ret += a[bx][by];
    return ret;
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d", &n) == 1) {
        for(int i = 1; i <= n; ++i)
            for(int j = 1; j <= n; ++j)
                scanf("%d", a[i] + j);

        memset(f, 0xc0, sizeof f);
        f[1][1][1] = a[1][1];
        for(int ax = 1; ax <= n; ++ax) {
            for(int ay = 1; ay <= n; ++ay) {
                for(int bx = 1; bx <= n; ++bx) {
                    int by = ax + ay - bx;
                    if(by < 1 || by > n) continue;
                    for(int d1 = 0; d1 < 2; ++d1) {
                        int nax = ax + d[d1][0], nay = ay + d[d1][1];
                        for(int d2 = 0; d2 < 2; ++d2) {
                            int nbx = bx + d[d2][0], nby = by + d[d2][1];
                            f[nax][nay][nbx] = max(f[nax][nay][nbx],
                                                   f[ax][ay][bx] + calc(nax, nay, nbx, nby));
                        }
                    }
                }
            }
        }
        printf("%d\n", f[n][n][n]);
    }

    return 0;
}
