//
//  Created by TaoSama on 2016-08-24
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
const double PI = acos(-1), EPS = 1e-8;

int sgn(double x) {
    return x < -EPS ? -1 : x > EPS;
}

struct Point {
    double x, y;
    Point() {}
    Point(double x, double y): x(x), y(y) {}
    void read() {
        scanf("%lf%lf", &x, &y);
    }
    Point operator-(const Point& p) const {
        return Point(x - p.x, y - p.y);
    }
    double operator*(const Point& p) const {
        return x * p.x + y * p.y;
    }
    double operator^(const Point& p) const {
        return x * p.y - y * p.x;
    }
    bool operator<(const Point& p) const {
        return x == p.x && y < p.y || x < p.x;
    }
    double length() {
        return *this * *this;
    }
    double arg() {
        return atan2(y, x);
    }
} ps[N];

//输入不能有重点，函数执行完后输入顺序被破坏
Point ch[N];
int convexHull(Point* p, int n, Point* ch) {
    sort(p, p + n);

    int m = 0;
    for(int i = 0; i < n; ++i) {
        while(m > 1 && sgn((ch[m - 1] - ch[m - 2]) ^ (p[i] - ch[m - 2])) <= 0) --m;
        ch[m++] = p[i];
    }
    for(int i = n - 2, t = m; i >= 0; --i) {
        while(m > t && sgn((ch[m - 1] - ch[m - 2]) ^ (p[i] - ch[m - 2])) <= 0) --m;
        ch[m++] = p[i];
    }
    if(n > 1) --m;
    return m;
}

int n;

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    scanf("%d", &n);
    for(int i = 0; i < n; ++i) ps[i].read();
    int m = convexHull(ps, n, ch);
    ch[m] = ch[0];

    vector<pair<double, int> > args(m);
    for(int i = 0; i < m; ++i) {
        double arg = (ch[i + 1] - ch[i]).arg();
        args[i] = make_pair(arg, i);
    }
    sort(args.begin(), args.end());

    Point A, B;
    while(scanf("%lf%lf%lf%lf", &A.x, &A.y, &B.x, &B.y) == 4) {
        if(m <= 1) {
            puts("GOOD");
            continue;
        }
        double arg1 = (B - A).arg();
        double arg2 = (A - B).arg();
        int i = upper_bound(args.begin(), args.end(), make_pair(arg1, INF))
                - args.begin();
        int j = upper_bound(args.begin(), args.end(), make_pair(arg2, INF))
                - args.begin();
        if(i == args.size()) i = 0; //cycle
        if(j == args.size()) j = 0;
        double c1 = (B - A) ^ (ch[args[i].second] - A);
        double c2 = (B - A) ^ (ch[args[j].second] - A);
        puts(sgn(c1 * c2) < 0 ? "BAD" : "GOOD");
    }

    return 0;
}
