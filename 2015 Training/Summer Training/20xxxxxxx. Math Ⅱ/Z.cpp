//
//  Created by TaoSama on 2015-08-15
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

int n;
double R, x[505], y[505], line[505][505];

double getArea(double x, double y, double z) {
    double p = (x + y + z) / 2.0;
    return sqrt(p * (p - x) * (p - y) * (p - z));
}

double getlen(int i, int j) {
    return sqrt((x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]));
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
//  ios_base::sync_with_stdio(0);

    while(scanf("%d%lf", &n, &R) == 2 && n) {
        for(int i = 1; i <= n; ++i) {
            double angle; scanf("%lf", &angle);
            x[i] = R * cos(angle / 180 * PI);
            y[i] = R * sin(angle / 180 * PI);
        }
        if(n < 3) {puts("0"); continue;}

        for(int i = 1; i <= n; ++i) {
            for(int j = i + 1; j <= n; ++j) {
                line[i][j] = getlen(i, j);
                line[j][i] = line[i][j];
            }
        }

        double ans = 0;
        for(int i = 1; i <= n - 2; ++i) {
            for(int j = i + 1; j <= n - 1; ++j)
                for(int k = j + 1; k <= n; ++k)
                    ans += getArea(line[i][j], line[j][k], line[i][k]);
        }
        printf("%.0f\n", ans);
    }
    return 0;
}
