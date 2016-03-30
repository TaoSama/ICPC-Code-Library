//
//  Created by TaoSama on 2015-12-07
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
const double PI = acos(-1), EPS = 1e-8;

int sgn(double x) {
    return x < -EPS ? -1 : x < EPS ? 0 : 1;
}

int d, n, b;
int p[15], h[15];

double solve(int b) {
    double l = 1.0 * d / (b + 1), maxv = 0;
    for(int i = 1; i <= n; ++i) {
        double x = fmod(p[i], l);
        if(sgn(x) == 0) return 1e20; //collision
        double a = h[i] / x / (x - l), k = -a * l;
        double ang = max(atan2(k, 1), PI / 4); // >= 45;
        maxv = max(maxv, l / sin(2 * ang));
    }
    return maxv;
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d%d%d", &d, &n, &b) == 3) {
        for(int i = 1; i <= n; ++i) scanf("%d%d", p + i, h + i);
        double ans = 1e20;
        for(int i = 0; i <= b; ++i)
            ans = min(ans, solve(i));
        printf("%.5f\n", sqrt(ans));
    }
    return 0;
}
