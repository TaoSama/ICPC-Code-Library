//
//  Created by TaoSama on 2017-05-06
//  Copyright (c) 2017 TaoSama. All rights reserved.
//
#pragma comment(linker, "/STACK:102400000,102400000")
#include <bits/stdc++.h>

using namespace std;
#define pr(x) cerr << #x << " = " << x << "  "
#define prln(x) cerr << #x << " = " << x << endl
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

const double EPS = 1e-8;

struct Point {
    double x, y;
    void read() {
        scanf("%lf%lf", &x, &y);
    }
    Point operator-(const Point& p) const {
        return {x - p.x, y - p.y};
    }
};

int sgn(double x) {
    return x < -EPS ? -1 : x > EPS;
}

double det(const Point& A, const Point& B) {
    return A.x * B.y - A.y * B.x;
}
double dot(const Point& A, const Point& B) {
    return A.x * B.x + A.y * B.y;
}

bool onSeg(Point p, Point a, Point b) {
    return sgn(det(a - p, b - p)) == 0 &&
           sgn(dot(a - p, b - p)) <= 0;
}

int isPointInPolygon(Point p, Point* a, int n) {
    int wn = 0;
    for(int i = 0; i < n; ++i) {
        if(onSeg(p, a[i], a[(i + 1) % n])) return -1;
        int k = sgn(det(a[(i + 1) % n] - a[i], p - a[i]));
        int d1 = sgn(a[i].y - p.y);
        int d2 = sgn(a[(i + 1) % n].y - p.y);
        if(k > 0 && d1 <= 0 && d2 > 0) ++wn;
        if(k < 0 && d2 <= 0 && d1 > 0) --wn;
    }
    if(wn != 0) return 1;
    return 0;
}

int n, m;
Point poly[2][N];

//This code is wrong, although it gets an AC.
int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d", &n) == 1) {
        for(int i = 0; i < n; ++i) poly[0][i].read();
        scanf("%d", &m);
        for(int i = 0; i < m; ++i) poly[1][i].read();

        bool ok = false;
        for(int i = 0; i < n; ++i) {
            Point p = poly[0][i], q = poly[0][(i + 1) % n];
            ok |= isPointInPolygon(p, poly[1], m) == 1;
            Point v = q - p;
            Point a = {p.x + 1000 * EPS * v.x, p.y + 1000 * EPS * v.y};
            ok |= isPointInPolygon(a, poly[1], m) == 1;
            Point b = {q.x - 1000 * EPS * v.x, q.y - 1000 * EPS * v.y};
            ok |= isPointInPolygon(b, poly[1], m) == 1;
        }
        for(int i = 0; i < m; ++i) {
            Point p = poly[1][i], q = poly[1][(i + 1) % n];
            ok |= isPointInPolygon(p, poly[0], n) == 1;
            Point v = q - p;
            Point a = {p.x + 1000 * EPS * v.x, p.y + 1000 * EPS * v.y};
            ok |= isPointInPolygon(a, poly[0], n) == 1;
            Point b = {q.x - 1000 * EPS * v.x, q.y - 1000 * EPS * v.y};
            ok |= isPointInPolygon(b, poly[0], n) == 1;
        }
        static int kase = 0;
        printf("Case %d: %s\n", ++kase, ok ? "Yes" : "No");
    }

    return 0;
}
