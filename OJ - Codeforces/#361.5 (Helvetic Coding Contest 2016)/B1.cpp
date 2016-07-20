//
//  Created by TaoSama on 2016-07-10
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

int n, a[55][55];

#define rep(i, a, b) for(int i = a; i <= b; ++i)
#define repv(i, a, b) for(int i = a; i >= b; --i)

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);
    clock_t _ = clock();

    while(scanf("%d", &n) == 1) {
        for(int i = 1; i <= n; ++i)
            for(int j = 1; j <= n; ++j)
                scanf("%1d", a[i] + j);

        int sx, tx, sy, ty;
        sx = tx = sy = ty = 0;
        rep(i, 1, n) {
            rep(j, 1, n) {
                if(a[i][j] == 1) {
                    sx = i, sy = j;
                    break;
                }
            }
            if(sx) break;
        }
        repv(i, n, 1) {
            repv(j, n, 1) {
                if(a[i][j] == 1) {
                    tx = i, ty = j;
                    break;
                }
            }
            if(tx) break;
        }
//        printf("%d %d %d %d\n", sx, sy, tx, ty);


        bool ok = true;
        //out
        rep(i, 1, n) rep(j, 1, n)
        if(i < sx || i > tx || j < sy || j > ty) {
            if(a[i][j]) {
                ok = false;
//                printf("a[%d][%d] = %d\n", i, j, a[i][j]),;
            }
        }
//        prln(ok);

        //in
        rep(i, sx, tx) rep(j, sy, ty) {
            if(i == sx && j == sy) ok &= a[i][j] == 1;
            else if(i == sx && j == ty) ok &= a[i][j] == 1;
            else if(i == tx && j == sy) ok &= a[i][j] == 1;
            else if(i == tx && j == ty) ok &= a[i][j] == 1;
            else if(i == sx) ok &= a[i][j] == 2;
            else if(i == tx) ok &= a[i][j] == 2;
            else if(j == sy) ok &= a[i][j] == 2;
            else if(j == ty) ok &= a[i][j] == 2;
            else ok &= a[i][j] == 4;
        }

        puts(ok ? "Yes" : "No");
    }

#ifdef LOCAL
    printf("\nTime cost: %.2fs\n", 1.0 * (clock() - _) / CLOCKS_PER_SEC);
#endif
    return 0;
}
