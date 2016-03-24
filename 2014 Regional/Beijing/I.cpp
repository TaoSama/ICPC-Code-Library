//
//  Created by TaoSama on 2015-10-11
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
const double PI = acos(-1), EPS = 1e-10;

int sgn(double a) {
    return a < -EPS ? -1 : a < EPS ? 0 : 1;
}

struct Point {
    double x, y;
};

double getDis(const Point& p1, const Point& p2) {
    return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}

double getAngle(double a, double b, double c) {
    return acos((a * a + b * b - c * c) / 2 / a / b);
}

struct Circle {
    double r;
    Point p;
    Circle() {}
    Circle(double r, double x, double y) {
        this->r = r;
        p = (Point) {x, y};
    }
};

double getIntersectionArea(const Circle& c1, const Circle& c2) {
    double dis = getDis(c1.p, c2.p);
    if(sgn(dis - (c1.r + c2.r)) > 0) return 0;
    if(sgn(dis - abs(c1.r - c2.r)) <= 0) {
        double minr = min(c1.r, c2.r);
        return PI * minr * minr;
    }
    double alpha = getAngle(c1.r, dis, c2.r) * 2;
    double beta = getAngle(c2.r, dis, c1.r) * 2;
    double area = 0.5 * alpha * c1.r * c1.r + 0.5 * beta * c2.r * c2.r;
    area -= 0.5 * c1.r * c1.r * sin(alpha) + 0.5 * c2.r * c2.r * sin(beta);
    return area;
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
        double r, R;
        double x1, y1, x2, y2;
        scanf("%lf%lf%lf%lf%lf%lf", &r, &R, &x1, &y1, &x2, &y2);
        Circle a1(R, x1, y1), a2(R, x2, y2);
        Circle b1(r, x1, y1), b2(r, x2, y2);
        double ans = getIntersectionArea(a1, a2) - getIntersectionArea(a1, b2)
                     - getIntersectionArea(a2, b1) + getIntersectionArea(b1, b2);
        printf("Case #%d: %.6f\n", ++kase, ans);
    }
    return 0;
}
