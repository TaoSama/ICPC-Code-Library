//
//  Created by TaoSama on 2016-01-15
//  Copyright (c) 2015 TaoSama. All rights reserved.
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
const double EPS = 1e-10;

int sgn(double x) {return x < -EPS ? -1 : x < EPS ? 0 : 1;}

int n, x0, y0;

struct Point {
    double x, y;
    Point() {}
    Point(double x, double y): x(x), y(y) {}
    void read() {scanf("%lf%lf", &x, &y);}
    double operator*(const Point& p) const {
        return x * p.x + y * p.y;
    }
    Point operator-(const Point& p) const {
        return (Point) {x - p.x, y - p.y};
    }
    double operator^(const Point& p) const {
        return x * p.y - y * p.x;
    }
} p[N];

double getLen(Point P) {
    return sqrt(P * P);
}

double disToSegment(Point P, Point A, Point B) {
    Point v1 = B - A, v2 = P - A, v3 = P - B;
    if(sgn(v1 * v2) < 0) return getLen(v2);
    else if(sgn(v1 * v3) > 0) return getLen(v3);
    else return abs(v1 ^ v2) / getLen(v1);
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d%d%d", &n, &x0, &y0) == 3) {
        Point O(x0, y0);
        for(int i = 1; i <= n; ++i) p[i].read();
        p[n + 1] = p[1];
        double R = 0, r = 1e18;
        for(int i = 1; i <= n; ++i) {
            R = max(R, getLen(O - p[i]));
            r = min(r, disToSegment(O, p[i], p[i + 1]));
        }
//      pr(R); prln(r);
        printf("%.12f\n", acos(-1) * (R * R - r * r));
    }
    return 0;
}
