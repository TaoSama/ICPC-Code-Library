//
//  Created by TaoSama on 2017-05-25
//  Copyright (c) 2017 TaoSama. All rights reserved.
//
#pragma comment(linker, "/STACK:102400000,102400000")
#include <bits/stdc++.h>

using namespace std;
#define pr(x) cerr << #x << " = " << x << "  "
#define prln(x) cerr << #x << " = " << x << endl
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n;
const double EPS = 1e-8;
int sgn(double x) {return x < -EPS ? -1 : x > EPS;}

// 直线与一般多边形交
struct Point {
    double x, y;
    Point() {}
    Point(double x, double y): x(x), y(y) {}
    void read() {cin >> x >> y;}
    Point operator-(const Point& p) {
        return Point(x - p.x, y - p.y);
    }
    double operator*(const Point& p) {
        return x * p.x + y * p.y;
    }
    double operator^(const Point& p) {
        return x * p.y - y * p.x;
    }
    double length() {return hypotl(x, y);}
} poly[N];
using Vec = Point;

double getIntersection(Point p, Vec v, Point q, Vec w) {
    return (w ^ (p - q)) / (v ^ w);
}

double gao(Point p, Vec v) {
    double ret = 0;
    vector<pair<double, int> > pos;
    for(int i = 1; i <= n; ++i) {
        int s1 = sgn(v ^ (poly[i] - p));
        int s2 = sgn(v ^ (poly[i + 1] - p));
        if(s1 == s2) continue; //collinear or no intersection
        double o = getIntersection(p, v, poly[i], poly[i + 1] - poly[i]);
        if(s1 > s2) pos.push_back({o, s1&& s2 ? 2 : 1});
        else pos.push_back({o, s1&& s2 ? -2 : -1});
    }
    sort(pos.begin(), pos.end());
    int flag = 0;
    for(int i = 0; i + 1 < pos.size(); ++i) {
        flag += pos[i].second;
        if(flag) ret += pos[i + 1].first - pos[i].first;
        else if(flag < 0) return 0;
    }
    return ret * v.length();
}


int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d", &n) == 1) {
        for(int i = 1; i <= n; ++i) {
            int x, y; scanf("%d%d", &x, &y);
            poly[i] = Point(x, y);
        }
        double ans = 0;
        for(int i = 1; i <= n; ++i) {
            for(int j = i + 1; j <= n; ++j) {
                ans = max(ans, (poly[i] - poly[j]).length());
                ans = max(ans, gao(poly[i], poly[j]));
            }
        }
        printf("%.12f\n", ans);
    }

    return 0;
}
