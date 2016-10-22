//
//  Created by TaoSama on 2016-07-12
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

struct Point {
    double x, y;
    Point() {}
    Point(double x, double y) : x(x), y(y) {}
    void read() { scanf("%lf%lf", &x, &y); }
    Point operator-(const Point& p) const {
        return Point(x - p.x, y - p.y);
    }
    double operator*(const Point& p) const {
        return x * p.x + y * p.y;

    }
    bool operator<(const Point& p) const {
        return make_pair(x, y) < make_pair(p.x, p.y);
    }
    double length() {
        return sqrt(*this * *this);
    }
} ps[105];

int n;

double getSum(Point p) {
    double ret = 0;
    for(int i = 1; i <= n; ++i) ret += (p - ps[i]).length();
    return ret;
}

bool canAccept(double newOne, double old, double T) {
    static int limit = 10000;
    return exp(-(newOne - old) / T) > 1.0 * rand() / limit;
}

//板题 随意就好
double solve() {
    double st = 1e4, ed = 1e-4, DELTA = 0.99;

    Point p = ps[1];
    double ret = getSum(p);
    int cnt = 0;
    for(double T = st; T > ed; T *= DELTA) {
        ++cnt;
        static int d[][2] = { -1, 0, 0, -1, 1, 0, 0, 1};
        for(int i = 0; i < 4; ++i) {
            Point np = p;
            np.x += T * d[i][0];
            np.y += T * d[i][1];
            double newOne = getSum(np);
            if(newOne < ret || canAccept(newOne, ret, T)) {
                p = np;
                ret = newOne;
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
    srand(36);

    while(scanf("%d", &n) == 1) {
        for(int i = 1; i <= n; ++i) ps[i].read();
        printf("%.0f\n", solve());
    }

#ifdef LOCAL
    printf("\nTime cost: %.2fs\n", 1.0 * (clock() - _) / CLOCKS_PER_SEC);
#endif
    return 0;
}
