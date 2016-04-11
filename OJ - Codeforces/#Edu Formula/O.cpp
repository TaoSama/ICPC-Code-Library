//
//  Created by TaoSama on 2016-02-24
//  Copyright (c) 2016 TaoSama. All rights reserved.
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
const double EPS = 1e-8;

int sgn(double x) {
    return x < -EPS ? -1 : x > EPS;
}

double px, py, vx, vy, a, b, c, d;

struct Point {
    double x, y;
    void read() {scanf("%lf%lf", &x, &y);}
    void print() {printf("%.12f %.12f\n", x, y);}

    Point operator+(const Point& p) {
        return {x + p.x, y + p.y};
    }
    Point operator-(const Point& p) {
        return {x - p.x, y - p.y};
    }
    Point operator*(const double& c) {
        return {c * x, c * y};
    }
    double length() {return hypot(x, y);}
    void normalize() {
        double len = length();
        x /= len;
        y /= len;
    }
    Point rotate() { //clock-wise;
        return {y, -x};
    }
};

using Vector = Point;

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
//  ios_base::sync_with_stdio(0);

    cin >> px >> py >> vx >> vy >> a >> b >> c >> d;
    Point p = {px, py};
    Vector v = {vx, vy};
    v.normalize();
    Vector w = v.rotate();

    (p + v * b).print();
    (p - w * (a / 2.)).print();
    (p - w * (c / 2.)).print();
    (p - w * (c / 2.) - v * d).print();
    (p + w * (c / 2.) - v * d).print();
    (p + w * (c / 2.)).print();
    (p + w * (a / 2.)).print();

    return 0;
}
