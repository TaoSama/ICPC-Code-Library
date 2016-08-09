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
const int N = 1e3 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, m, x, y;
char s[N][N];
int need[N][2], f[N][N][2];

void getMin(int& x, int y) {
    if(x > y) x = y;
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d%d%d%d", &n, &m, &x, &y) == 4) {
        for(int i = 1; i <= n; ++i) scanf("%s", s[i] + 1);

        for(int j = 1; j <= m; ++j) {
            need[j][0] = need[j][1] = 0;
            for(int i = 1; i <= n; ++i) {
                need[j][0] += s[i][j] == '#';
                need[j][1] += s[i][j] == '.';
            }
        }

        memset(f, 0x3f, sizeof f);
        f[1][1][0] = need[1][0];
        f[1][1][1] = need[1][1];

        for(int i = 2; i <= m; ++i) {
            for(int j = 1; j <= y; ++j) {
                for(int k = 0; k < 2; ++k) {
                    getMin(f[i][j + 1][k], f[i - 1][j][k] + need[i][k]);
                    if(j >= x) getMin(f[i][1][k ^ 1], f[i - 1][j][k] + need[i][k ^ 1]);
                }
            }
        }
        int ans = INF;
        for(int j = x; j <= y; ++j)
            for(int k = 0; k < 2; ++k)
                getMin(ans, f[m][j][k]);
        printf("%d\n", ans);
    }

    return 0;
}
