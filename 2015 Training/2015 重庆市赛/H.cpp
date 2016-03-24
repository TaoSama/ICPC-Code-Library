//
//  Created by TaoSama on 2015-11-19
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
const double EPS = 1e-8;

int n;

int sgn(double x) {return x < -EPS ? -1 : x < EPS ? 0 : 1;}

struct Point {
    double x, y, ang;
    Point(double x = 0, double y = 0): x(x), y(y) {}
    void read() {scanf("%lf%lf", &x, &y); ang = atan2(y, x);}
    Point operator- (const Point& p) const {
        return (Point) {x - p.x, y - p.y};
    }
    double operator* (const Point& p) const {
        return x * p.x + y * p.y;
    }
    double operator^ (const Point& p) const {
        return x * p.y - y * p.x;
    }
    bool operator< (const Point& p) const {
        return ang < p.ang;
    }
} a[20];

bool onSeg(Point p, Point a, Point b) {
    return sgn((a - p ^ b - p) == 0 && sgn((a - p) * (b - p)) <= 0);
}

int isPointInPolygon(Point p) {
    int wn = 0;
    for(int i = 0; i < n; ++i) {
        if(onSeg(p, a[i], a[i + 1])) return -1;
        int k = sgn(a[i + 1] - a[i] ^ p - a[i]);
        int d1 = sgn(a[i].y - p.y);
        int d2 = sgn(a[i + 1].y - p.y);
        if(k > 0 && d1 <= 0 && d2 > 0) ++wn;
        if(k < 0 && d2 <= 0 && d1 > 0) --wn;
    }
    if(wn != 0) return 1;
    return 0;
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int kase = 0;
    while(scanf("%d", &n) == 1 && n) {
        for(int i = 0; i < n; ++i) a[i].read();
        int p, q; scanf("%d%d", &p, &q);
        a[n] = a[0];

        printf("Pilot %d\n", ++kase);
        if(isPointInPolygon(Point(0, 0)) == 0) {
            puts("The pilot is safe.\n");
            continue;
        }
        puts("The pilot is in danger!");
        printf("The secret number is %d.\n\n", (p - 1) * (q - 1) >> 1);
    }
    return 0;
}
