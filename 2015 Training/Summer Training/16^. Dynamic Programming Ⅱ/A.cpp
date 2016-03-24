//
//  Created by TaoSama on 2015-08-07
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

const double eps = 1e-10;
int dcmp(double x) {
    if(fabs(x) < eps) return 0;
    else return x < 0 ? -1 : 1;
}

struct Point {
    double x, y;
    Point(double x = 0, double y = 0): x(x), y(y) { }
};

typedef Point Vector;

Vector operator + (const Vector& A, const Vector& B) { return Vector(A.x + B.x, A.y + B.y); }
Vector operator - (const Point& A, const Point& B) { return Vector(A.x - B.x, A.y - B.y); }
Vector operator * (const Vector& A, double p) { return Vector(A.x * p, A.y * p); }

bool operator < (const Point& a, const Point& b) {
    return a.x < b.x || (a.x == b.x && a.y < b.y);
}

bool operator == (const Point& a, const Point &b) {
    return dcmp(a.x - b.x) == 0 && dcmp(a.y - b.y) == 0;
}

double Dot(const Vector& A, const Vector& B) { return A.x * B.x + A.y * B.y; }
double Cross(const Vector& A, const Vector& B) { return A.x * B.y - A.y * B.x; }
double Length(Vector A) { return sqrt(Dot(A, A)); }

bool SegmentProperIntersection(const Point& a1, const Point& a2,
                               const Point& b1, const Point& b2) {
    double c1 = Cross(a2 - a1, b1 - a1), c2 = Cross(a2 - a1, b2 - a1),
           c3 = Cross(b2 - b1, a1 - b1), c4 = Cross(b2 - b1, a2 - b1);
    return dcmp(c1) * dcmp(c2) < 0 && dcmp(c3) * dcmp(c4) < 0;
}

bool OnSegment(const Point& p, const Point& a1, const Point& a2) {
    return dcmp(Cross(a1 - p, a2 - p)) == 0 && dcmp(Dot(a1 - p, a2 - p)) < 0;
}

typedef vector<Point> Polygon;

int isPointInPolygon(const Point& p, const Polygon& poly) {
    int n = poly.size();
    int wn = 0;
    for(int i = 0; i < n; i++) {
        const Point& p1 = poly[i];
        const Point& p2 = poly[(i + 1) % n];
        if(p1 == p || p2 == p || OnSegment(p, p1, p2)) return -1; // 在边界上
        int k = dcmp(Cross(p2 - p1, p - p1));
        int d1 = dcmp(p1.y - p.y);
        int d2 = dcmp(p2.y - p.y);
        if(k > 0 && d1 <= 0 && d2 > 0) wn++;
        if(k < 0 && d2 <= 0 && d1 > 0) wn--;
    }
    if(wn != 0) return 1;  // 内部
    return 0; // 外部
}

bool isDiagonal(const Polygon& poly, int a, int b) {
    int n = poly.size();
    for(int i = 0; i < n; i++)
        if(i != a && i != b
                && OnSegment(poly[i], poly[a],
                             poly[b])) return false; // 中间不能有其他点
    for(int i = 0; i < n; i++)
        if(SegmentProperIntersection(poly[i], poly[(i + 1) % n], poly[a],
                                     poly[b])) return false; // 不能和多边形的边规范相交
    Point midp = (poly[a] + poly[b]) * 0.5;
    return (isPointInPolygon(midp, poly) == 1); // 整条线段在多边形内
}

int n;
double dp[105][105];

double solve(const Polygon& poly) {
    int n = poly.size();

    memset(dp, 0xc0, sizeof dp);
    for(int i = n - 2; i >= 0; --i) {
        for(int j = i + 1; j < n; ++j) {
            if(i + 1 == j) dp[i][j] = 0;
            //凹多边形非法对角线 排除最后一条边(不是对角线)的 非法情况
            else if(!(i == 0 && j == n - 1) && !isDiagonal(poly, i, j)) dp[i][j] = INF;
            else {
                dp[i][j] = INF;
                for(int k = i + 1; k < j; ++k) {
                    double v = max(dp[i][k], dp[k][j]);
                    double area = abs(Cross(poly[j] - poly[i],
                                            poly[k] - poly[i])) / 2.0; // triangle i-j-k
                    v = max(v, area);
                    dp[i][j] = min(dp[i][j], v);
                }
            }
        }
    }
    return dp[0][n - 1];
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int t; cin >> t;
    while(t--) {
        cin >> n;
        Polygon poly;
        for(int i = 1; i <= n; ++i) {
            double x, y; cin >> x >> y;
            poly.push_back(Point(x, y));
        }
        cout << fixed << setprecision(1) << solve(poly) << '\n';
    }
    return 0;
}
