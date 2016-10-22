//
//  Created by TaoSama on 2016-07-13
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
const int N = 30 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

struct Point {
    double x, y, z;
    void read() {
        scanf("%lf%lf%lf", &x, &y, &z);
    }
} ps[N];

double sq(double x) {
    return x * x;
}

double length(Point A, Point B) {
    return sqrt(sq(A.x - B.x) + sq(A.y - B.y) + sq(A.z - B.z));
}

bool canAccept(double newOne, double old, double T) {
    static int limit = 10000;
    return exp(-(newOne - old) / T) > 1.0 * rand() / limit;
}

int n;

//离最远的点越近越好
double solve() {
    double st = 100, ed = 1e-8, DELTA = 0.999;

    double ret = 1e18;

    Point p = (Point) {0, 0, 0};
    for(int i = 1; i <= n; ++i) p.x += ps[i].x, p.y += ps[i].y, p.z += ps[i].z;
    p.x /= n; p.y /= n; p.z /= n;

    int cnt = 0;
    for(double T = st; T > ed; T *= DELTA) {
        ++cnt;
        int far = 1;
        for(int i = 2; i <= n; ++i)
            if(length(p, ps[i]) > length(p, ps[far]))
                far = i;

        double newR = length(p, ps[far]);
        if(newR < ret || canAccept(newR, ret, T)) {
            p.x += (ps[far].x - p.x) / newR * T;
            p.y += (ps[far].y - p.y) / newR * T;
            p.z += (ps[far].z - p.z) / newR * T;
        }
        ret = min(ret, newR);
    }
//    prln(cnt);
    return ret;
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);
    clock_t _ = clock();

    while(scanf("%d", &n) == 1 && n) {
        for(int i = 1; i <= n; ++i) ps[i].read();
        printf("%.12f\n", solve());
    }

#ifdef LOCAL
    printf("\nTime cost: %.2fs\n", 1.0 * (clock() - _) / CLOCKS_PER_SEC);
#endif
    return 0;
}
