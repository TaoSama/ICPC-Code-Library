//
//  Created by TaoSama on 2015-08-13
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
const double PI = acos(-1);

int n, m;
double x[45], l[45][45];
double dp[45][45][45]; //dp[i][j][k]:= [i,j] choose k points

double gao() {
    for(int i = 1; i <= n; ++i) {
        for(int j = i + 1; j <= n; ++j) {
            double angle = x[j] - x[i];
            if(angle > 0.5) angle = 1 - angle;
            angle *= 2 * PI;
            l[i][j] = l[j][i] = sqrt(2 - 2 * cos(angle));
        }
    }
}

//calculate isosceles triangle's area with Heron's formula
double getArea(int i, int j, int k) {
    double p = (l[i][j] + l[j][k] + l[i][k]) / 2;
    return sqrt(p * (p - l[i][j]) * (p - l[j][k]) * (p - l[i][k]));
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d%d", &n, &m) == 2 && (n || m)) {
        for(int i = 1; i <= n; ++i) scanf("%lf", x + i);

        gao();
        memset(dp, 0, sizeof dp);
        double ans = -INF;
        for(int k = 3; k <= m; ++k) {
            for(int i = 1; i <= n - k + 1; ++i) {
                for(int j = i + k - 1; j <= n; ++j) {
                    for(int z = i + k - 2; z <= j - 1; ++z) {
                        //choose point j
                        dp[i][j][k] = max(dp[i][j][k], dp[i][z][k - 1] + getArea(i, z, j));
                        if(k == m) ans = max(ans, dp[i][j][k]);
                    }
                }
            }
        }
        printf("%.6f\n", ans);
    }
    return 0;
}
