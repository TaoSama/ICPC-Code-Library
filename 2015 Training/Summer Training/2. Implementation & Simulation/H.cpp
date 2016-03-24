//
//  Created by TaoSama on 2015-07-19
//  Copyright (c) 2015 TaoSama. All rights reserved.
//
//#pragma comment(linker, "/STACK:1024000000,1024000000")
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
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, m;
bool lined[15][15][15][15];

bool isSquare(int x, int y, int sz) {
    for(int i = 0; i < sz; ++i)
        if(!lined[x + i][y][x + i + 1][y] || !lined[x + i][y + sz][x + i + 1][y + sz] ||
                !lined[x][y + i][x][y + i + 1] || !lined[x + sz][y + i][x + sz][y + i + 1])
            return false;
    return true;
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int kase = 0;
    while(scanf("%d%d", &n, &m) == 2) {
        memset(lined, false, sizeof lined);
        for(int i = 1; i <= m; ++i) {
            char op[2]; int x, y;
            scanf("%s%d%d", op, &x, &y);
            if(op[0] == 'H') lined[x][y][x][y + 1] = true;
            else lined[y][x][y + 1][x] = true;
        }
//
//        for(int i = 1; i <= n; ++i) {
//            for(int j = 1; j <= n; ++j) {
//                printf("lef[%d][%d] = %d\n", i, j, lef[i][j]);
//                printf("rig[%d][%d] = %d\n", i, j, rig[i][j]);
//                printf("down[%d][%d] = %d\n", i, j, down[i][j]);
//                printf("up[%d][%d] = %d\n\n", i, j, up[i][j]);
//
//            }
//        }

        if(kase) printf("\n**********************************\n\n");
        printf("Problem #%d\n\n", ++kase);
        bool have = false;
        for(int sz = 1; sz <= n; ++sz) {
            int cnt = 0;
            for(int i = 1; i <= n - sz; ++i) {
                for(int j = 1; j <= n - sz; ++j) {
                    cnt += isSquare(i, j, sz);
                }
            }
            if(cnt) {
                have = true;
                printf("%d square (s) of size %d\n", cnt, sz);
            }
        }
        if(!have) printf("No completed squares can be found.\n");
    }
    return 0;
}
