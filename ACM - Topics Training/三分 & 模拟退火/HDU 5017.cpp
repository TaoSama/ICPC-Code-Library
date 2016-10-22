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
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

double coff[6];

bool read() {
    for(int i = 1; i <= 6; ++i) {
        if(scanf("%lf", coff + i) != 1) return false;
    }
    return true;
}

inline double sq(double x) {
    return x * x;
}

double getZ(double x, double y) {
    double a = coff[3];
    double b = coff[4] * y + coff[5] * x;
    double c = coff[1] * sq(x) + coff[2] * sq(y) + coff[6] * x * y - 1;
    double delta = b * b - 4 * a * c;
    if(delta < 0) return 1e18;
    delta = sqrt(delta);
    double z1 = (-b + delta) / (2 * a);
    double z2 = (-b - delta) / (2 * a);
    return abs(z1) < abs(z2) ? z1 : z2;
}

struct Point {
    double x, y, z;
    void read() {
        scanf("%lf%lf%lf", &x, &y, &z);
    }
} ps[N];

inline double length(Point A) {
    return sqrt(sq(A.x) + sq(A.y) + sq(A.z));
}

inline bool canAccept(double newOne, double old, double T) {
    static int limit = 10000;
    return exp(-(newOne - old) / T) > 1.0 * rand() / limit;
}

//貌似这种单峰的 不Accept差解更好？
double solve() {
    double st = 1, ed = 1e-8, DELTA = 0.99;

    Point p = (Point) {0, 0, 0};
    p.z = getZ(p.x, p.y);
    double ret = length(p);

    int cnt = 0;
    for(double T = st; T > ed; T *= DELTA) {
        ++cnt;

        for(int i = -1; i <= 1; ++i) {
            for(int j = -1; j <= 1; ++j) {
                if(!i && !j) continue;
                Point np = p;
                np.x += i * T;
                np.y += j * T;
                np.z = getZ(np.x, np.y);

                double newD = length(np);
                if(newD < ret)
                    p = np;
                ret = min(ret, newD);
            }
        }
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

    while(read()) {
        printf("%.12f\n", solve());
    }

#ifdef LOCAL
    printf("\nTime cost: %.2fs\n", 1.0 * (clock() - _) / CLOCKS_PER_SEC);
#endif
    return 0;
}
