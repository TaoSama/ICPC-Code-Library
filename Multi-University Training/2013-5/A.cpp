//
//  Created by TaoSama on 2016-03-12
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
const double EPS = 1e-7;

int sgn(double x) {
    return x < -EPS ? -1 : x > EPS;
}

struct Point {
    double x, y;
    void read() {scanf("%lf%lf", &x, &y);}
    Point operator+(const Point& p) {
        return {x + p.x, y + p.y};
    }
    Point operator-(const Point& p) {
        return {x - p.x, y - p.y};
    }
    double operator*(const Point& p) {
        return x * p.x + y * p.y;
    }
    Point operator*(const double& t) {
        return {x * t, y * t};
    }
    double operator^(const Point& p) {
        return x * p.y - y * p.x;
    }
    double length() {
        return hypot(x, y);
    }
} a[55], b[55];
typedef Point Vector;

Point getLineIntersection(Point p, Vector v, Point q, Vector w) {
    Vector u = p - q;
    double t = (w ^ u) / (v ^ w);
    return p + v * t;
}

bool onSeg(Point p, Point a, Point b) {
    return !sgn((a - p) ^ (b - p)) && sgn((a - p) * (b - p)) < 0;
}

struct Line {
    Point p; Vector v;
} l[55][55];

Line getMidLine(Point a, Point b) {
    Point m = (a + b) * 0.5;
    Vector u = b - a;
    return {m, { -u.y, u.x}};
}

int n, m;

bool check(Point o, double d) {
    for(int i = 1; i <= m; ++i)
        if(sgn(d - (o - b[i]).length()) > 0) return false;
    return true;
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d%d", &n, &m) == 2) {
        for(int i = 1; i <= n; ++i) a[i].read();
        for(int i = 1; i <= m; ++i) {
            b[i].read();
            for(int j = 1; j < i; ++j) l[i][j] = getMidLine(b[i], b[j]);
        }
        int q; scanf("%d", &q);
        while(q--) {
            int u, v; scanf("%d%d", &u, &v);
            int ans = 0;
            for(int i = 1; i <= m; ++i) {
                for(int j = 1; j < i; ++j) {
                    if(!sgn(l[i][j].v ^ (a[v] - a[u]))) continue;
                    Point o = getLineIntersection(l[i][j].p, l[i][j].v, a[u], a[v] - a[u]);
                    if(onSeg(o, a[u], a[v])) ans += check(o, (o - b[i]).length());
                }
            }
            printf("%d\n", ans);
        }
    }
    return 0;
}
