//
//  Created by TaoSama on 2016-08-23
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
const int N = 300 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;
const double EPS = 1e-8;

int sgn(double x) {
    return x < -EPS ? -1 : x > EPS;
}

int n;
struct Point {
    double x, y;
    Point() {}
    Point(double x, double y): x(x), y(y) {}
    inline void read() {
        scanf("%lf%lf", &x, &y);
    }
    inline Point operator+(const Point& p) const {
        return Point(x + p.x, y + p.y);
    }
    inline Point operator-(const Point& p) const {
        return Point(x - p.x, y - p.y);
    }
    inline Point operator*(const double& k) const {
        return Point(k * x, k * y);
    }
    inline double operator*(const Point& p) const {
        return x * p.x + y * p.y;
    }
    inline double operator^(const Point& p) const {
        return x * p.y - y * p.x;
    }
    inline Point rotate(double rad) {
        return Point(x * cos(rad) - y * sin(rad), x * sin(rad) + y * cos(rad));
    }
    inline double length() {
        return sqrt(x * x + y * y);
    }
    inline void norm() {
        double l = length();
        x /= l, y /= l;
    }
    void see() {
        printf("%.4f %.4f\n", x, y);
    }
} ps[N];

typedef Point Vector;

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
//    ios_base::sync_with_stdio(0);

    while(scanf("%d", &n) == 1 && n) {
        for(int i = 1; i <= n; ++i) ps[i].read();

        int ans = 1;
        for(int i = 1; i <= n; ++i) {
            for(int j = i + 1; j <= n; ++j) {
                if(i == j) continue;

                Vector AB = ps[j] - ps[i]; //B-A=AB
                double c = AB.length();
                if(sgn(c - 2) > 0) continue;

                double cosTheta = (c * c + 1 - 1) / (2 * c);
                double theta = acos(cosTheta);
                Vector AO = AB.rotate(theta); AO.norm();
                Point O = ps[i] + AO;

                int cnt = 0;
                for(int k = 1; k <= n; ++k)
                    if(sgn((ps[k] - O).length() - 1) <= 0) ++cnt;
                ans = max(ans, cnt);
            }
        }
        printf("%d\n", ans);
    }

    return 0;
}
