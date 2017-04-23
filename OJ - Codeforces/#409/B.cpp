//
//  Created by TaoSama on 2017-04-16
//  Copyright (c) 2017 TaoSama. All rights reserved.
//
#pragma comment(linker, "/STACK:102400000,102400000")
#include <bits/stdc++.h>

using namespace std;
#define pr(x) cerr << #x << " = " << x << "  "
#define prln(x) cerr << #x << " = " << x << endl
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

const double EPS = 1e-10;

int sgn(double x) {
    return x < -EPS ? -1 : x > EPS;
}

typedef double Type;
struct Point {
    Type x, y;
    Point() {}
    Point(Type x, Type y) : x(x), y(y) {}
    void read() {scanf("%lf%lf", &x, &y);}
    void write() {printf("%f %f\n", x, y);}
    Point operator+(const Point& p) const {
        return Point(x + p.x, y + p.y);
    }
    Point operator-(const Point& p) const {
        return Point(x - p.x, y - p.y);
    }
    bool operator<(const Point& p) const {
        return x != p.x ? x < p.x : y < p.y;
    }
};
typedef Point Vec;

Type dot(const Vec& A, const Vec& B) {
    return A.x * B.x + A.y * B.y;
}
Type det(const Vec& A, const Vec& B) {
    return A.x * B.y - A.y * B.x;
}
Type length(const Vec& A) {
    return sqrt(dot(A, A));
}
Type distanceToLine(Point P, Point A, Point B) {
    Vec v1 = B - A, v2 = P - A;
    return abs(det(v1, v2)) / length(v1);
}

int n;
Point ps[N];
bool check(double x) {
    for(int i = 0; i < n; ++i) {
        Point& lst = ps[(i - 1 + n) % n], &cur = ps[i], &nxt = ps[(i + 1) % n];
        double d = distanceToLine(cur, lst, nxt) / 2;
        if(d <= x) return false;
    }
    return true;
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d", &n) == 1) {
        for(int i = 0; i < n; ++i) ps[i].read();
        double l = 0, r = 1e18;
        for(int i = 1; i <= 200; ++i) {
            double m = (l + r) / 2;
            if(check(m)) l = m;
            else r = m;
        }
        printf("%.20f\n", l);
    }

    return 0;
}
