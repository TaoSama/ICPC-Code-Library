//
//  Created by TaoSama on 2016-01-30
//  Copyright (c) 2015 TaoSama. All rights reserved.
//
#pragma comment(linker, "/STACK:1024000000,1024000000")
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
const int N = 500 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, m;
char s[N][N];
int f[2][N][N];

void add(int &x, int y) {
    if((x += y) >= MOD) x -= MOD;
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d%d", &n, &m) == 2) {
        for(int i = 1; i <= n; ++i) scanf("%s", s[i] + 1);

        int p = 0;
        memset(f[p], 0, sizeof f[p]);
        f[p][1][n] = s[1][1] == s[n][m];
        int step = (n + m - 2) / 2;
        for(int i = 1; i <= step; ++i) {
            memset(f[!p], 0, sizeof f[!p]);
            for(int x1 = 1; x1 <= i + 1; ++x1) {
                for(int x2 = n; x2 >= n - i; --x2) {
                    int y1 = i + 2 - x1, y2 = n + m - i - x2;
                    if(s[x1][y1] != s[x2][y2]) continue;
                    add(f[!p][x1][x2], f[p][x1][x2]);
                    add(f[!p][x1][x2], f[p][x1][x2 + 1]);
                    add(f[!p][x1][x2], f[p][x1 - 1][x2]);
                    add(f[!p][x1][x2], f[p][x1 - 1][x2 + 1]);
                }
            }
            p = !p;
        }
        int ans = 0;
        for(int i = 1; i <= n; ++i) {
            add(ans, f[p][i][i]);
            if(n + m & 1) add(ans, f[p][i][i + 1]);
        }
        printf("%d\n", ans);
    }
    return 0;
}
