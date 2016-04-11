//
//  Created by TaoSama on 2016-03-11
//  Copyright (c) 2016 TaoSama. All rights reserved.
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
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, a[205];
char s[205];
double p[205], f[205][21][2]; //前i个数运算的值, j位为0/1的概率

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d", &n) == 1) {
        ++n;
        for(int i = 1; i <= n; ++i) scanf("%d", a + i);
        for(int i = 2; i <= n; ++i) scanf(" %c", s + i);
        for(int i = 2; i <= n; ++i) scanf("%lf", p + i);

        memset(f, 0, sizeof f);
        for(int i = 0; i < 21; ++i) f[1][i][a[1] >> i & 1] = 1;
        for(int i = 2; i <= n; ++i) {
            for(int j = 0; j < 21; ++j) {
                int b = a[i] >> j & 1;
                for(int k = 0; k < 2; ++k) {
                    f[i][j][k] += f[i - 1][j][k] * p[i];
                    if(s[i] == '^') f[i][j][k ^ b] += f[i - 1][j][k] * (1 - p[i]);
                    else if(s[i] == '&') f[i][j][k & b] += f[i - 1][j][k] * (1 - p[i]);
                    else f[i][j][k | b] += f[i - 1][j][k] * (1 - p[i]);
                }
            }
        }

        double ans = 0;
        for(int i = 0; i < 21; ++i) ans += f[n][i][1] * (1 << i);
        static int kase = 0;
        printf("Case %d:\n%.6f\n", ++kase, ans);
    }
    return 0;
}
