//
//  Created by TaoSama on 2015-12-09
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
double p[6], q[12]; //f(x), f(x)^2 coefficients
int a, b, slices, stacks;

double f(double *p, int n, double x) {
    double ret = 0;
    for(int i = n; ~i; --i)
        ret = ret * x + p[i];
    return ret;
}

double getArea(double x) {
    double y = f(p, n, x), theta = 2 * PI / slices;
    double triangleArea = y * y * sin(theta) / 2;
    return triangleArea * slices;
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int t; scanf("%d", &t);
    int kase = 0;
    while(t--) {
        scanf("%d", &n);
        for(int i = n; ~i; --i) scanf("%lf", p + i);
        scanf("%d%d%d%d", &a, &b, &slices, &stacks);

        //calculate f(x)^2 coefficients
        memset(q, 0, sizeof q);
        for(int i = 0; i <= n; ++i)
            for(int j = 0; j <= n; ++j)
                q[i + j] += p[i] * p[j];  //index for powers

        //integral, calculate f(x)^2 original function's coefficients
        for(int i = n * 2 + 1; i; --i)
            q[i] = q[i - 1] / i;
        q[0] = 0; //definite integral with no constants

        double trueValue = PI * (f(q, n * 2 + 1, b) - f(q, n * 2 + 1, a));
        double apprValue = 0;
        double x = a, dx = 1.0 * (b - a) / stacks;
        for(int i = 1; i <= stacks; ++i, x += dx) {
            double up = getArea(x), down = getArea(x + dx);
            apprValue += (up + down + sqrt(up * down)) * dx / 3;
        }
        double ans = 100 * (trueValue - apprValue) / trueValue;
        pr(apprValue); prln(trueValue);
        printf("Case %d: %.4f\n", ++kase, abs(ans));
    }
    return 0;
}
