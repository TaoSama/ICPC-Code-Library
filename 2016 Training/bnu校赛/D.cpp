//
//  Created by TaoSama on 2016-04-23
//  Copyright (c) 2016 TaoSama. All rights reserved.
//
#pragma comment(linker, "/STACK:102400000,102400000")
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

struct Point {
    double x, y;
    void read() {
        scanf("%lf%lf", &x, &y);
    }
    Point operator+(const Point& p) {
        return {x + p.x, y + p.y};
    }
    Point operator-(const Point& p) {
        return {x - p.x, y - p.y};
    }
    Point operator*(const double k) {
        return {k * x, k * y};
    }
    double length() {
        return hypot(x, y);
    }
} x, vx, y, vy;
int rx, ry;

double get(double m) {
    Point p = x + vx * m, q = y + vy * m;
    return (p - q).length();
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int t; scanf("%d", &t);
    while(t--) {
        x.read(); scanf("%d", &rx); vx.read();
        y.read(); scanf("%d", &ry); vy.read();
        double l = 0, r = 1e9;
        for(int i = 1; i <= 100; ++i) {
            double ll = (2 * l + r) / 3;
            double rr = (l + 2 * r) / 3;
            if(get(ll) < get(rr)) r = rr;
            else l = ll;
        }
        double dis = get(l) - rx - ry, t = l;
        if(sgn(dis) <= 0) { //hit
            double l = 0, r = t;
            for(int i = 1; i <= 100; ++i) {
                double m = (l + r) / 2;
                if(get(m) < rx + ry) r = m;
                else l = m;
            }
            printf("%.12f\n", l);
        } else printf("%.12f\n", dis);
    }
    return 0;
}
