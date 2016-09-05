//
//  Created by TaoSama on 2016-09-05
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
const double EPS = 1e-8, PI = acos(-1);

int sgn(double x) {
    return x < -EPS ? -1 : x > EPS;
}

struct Point {
    double x, y;
    Point() {}
    Point(double x, double y) : x(x), y(y) {}
    Point operator +(const Point a)const {
        return Point(a.x + x, a.y + y);
    }
    Point operator -(const Point a)const {
        return Point(x - a.x, y - a.y);
    }
    Point operator *(const double a)const {
        return Point(a * x, a * y);
    }
    double operator *(const Point a)const {
        return a.x * x + a.y * y;
    }
    void see() {
        printf("%.2f %.2f\n", x, y);
    }
};

double cross(Point a, Point b) {
    return a.x * b.y - a.y * b.x;
}

Point getLineIntersection(Point P, Point v, Point Q, Point w) {
    Point u = P - Q;
    double t = cross(w, u) / cross(v, w);
    return P + v * t;
}
bool segI(Point a1, Point a2, Point b1, Point b2) {
    double c1 = cross(a2 - a1, b1 - a1), c2 = cross(a2 - a1, b2 - a1);
    double c3 = cross(b2 - b1, a1 - b1), c4 = cross(b2 - b1, a2 - b1);
    return sgn(c1) * sgn(c2) < 0 && sgn(c3) * sgn(c4) < 0;
}

Point getGravity(vector<Point>& p) {
    Point o(0, 0);
    for(int i = 0; i < p.size(); ++i) o = o + p[i];
    o.x /= p.size(), o.y /= p.size();
    return o;
}

void polarSort(vector<Point>& p) {
    Point o = getGravity(p);
    sort(p.begin(), p.end(), [&](Point a, Point b) {
        Point A = a - o, B = b - o;
        return atan2(A.y, A.x) < atan2(B.y, B.x);
    });
}

double polygonArea(vector<Point>& p) {
    double area = 0;
    for(int i = 1; i + 1 < p.size(); i++)
        area += cross(p[i] - p[0], p[i + 1] - p[0]);
    return abs(area / 2);
}

int isPointInPolygon(Point p, vector<Point>& poly) {
    for(int i = 0; i + 1 < poly.size(); ++i) {
        Point v = poly[i + 1] - poly[i], w = p - poly[i];
        if(sgn(cross(v, w)) < 0) return false;
    }
    return true;
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
//    ios_base::sync_with_stdio(0);

    int x1, y1, x2, y2, x3, y3, x4, y4;
    while(cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4) {
        vector<Point> tri;
        tri.push_back(Point(x1, y1));
        tri.push_back(Point(x1, y2));
        tri.push_back(Point(x2, y1));

        vector<Point> rect;
        rect.push_back(Point(x3, y3));
        rect.push_back(Point(x4, y3));
        rect.push_back(Point(x4, y4));
        rect.push_back(Point(x3, y4));

        polarSort(tri);
        tri.push_back(tri.front());
        polarSort(rect);
        rect.push_back(rect.front());

        vector<Point> poly;
        for(int i = 0; i < 3; ++i) {
            for(int j = 0; j < 4; ++j) {
                if(!segI(tri[i], tri[i + 1], rect[j], rect[j + 1])) continue;
                Point p = getLineIntersection(tri[i], tri[i + 1] - tri[i],
                                              rect[j], rect[j + 1] - rect[j]);
                poly.push_back(p);
            }
        }
        for(int i = 0; i < 3; ++i)
            if(isPointInPolygon(tri[i], rect)) poly.push_back(tri[i]);
        for(int i = 0; i < 4; ++i)
            if(isPointInPolygon(rect[i], tri)) poly.push_back(rect[i]);

        polarSort(poly);
        double ans = poly.size() ? polygonArea(poly) : 0;

        printf("%.12f\n", ans);
    }

    return 0;
}
