//
//  Created by TaoSama on 2016-02-29
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
const int N = 30 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;
const double EPS = 1e-8;

int sgn(double x) {
    return x < -EPS ? -1 : x > EPS;
}

struct Point3 {
    double x, y, z;
    void read() {
        scanf("%lf%lf%lf", &x, &y, &z);
    }
    Point3 operator+(const Point3& p) {
        return {x + p.x, y + p.y, z + p.z};
    }
    Point3 operator-(const Point3& p) {
        return {x - p.x, y - p.y, z - p.z};
    }
    double operator*(const Point3& p) {
        return x * p.x + y * p.y + z * p.z;
    }
    Point3 operator^(const Point3& p) {
        return {y * p.z - z * p.y, z * p.x - x * p.z, x * p.y - y * p.x};
    }
    double length() {
        return sqrt(*this **this);
    }
} p[N][3];


using Vector3 = Point3;

double r[N];
Vector3 normal[N];

bool isParallel(Vector3 A, Vector3 B) {
    return sgn((A ^ B).length()) <= 0;
}

double point3ToLine(Point3 P, Point3 A, Vector3 v) {
    Vector3 w = P - A;
    return (v ^ w).length() / v.length();
}

double lineToLine(Point3 P, Vector3 v, Point3 Q, Vector3 w) {
    Vector3 z = v ^ w;
    return abs((P - Q) * z) / z.length();
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int t; scanf("%d", &t);
    while(t--) {
        int n; scanf("%d", &n);
        for(int i = 1; i <= n; ++i) {
            for(int j = 0; j < 3; ++j)
                p[i][j].read();
            r[i] = (p[i][1] - p[i][0]).length();
            normal[i] = (p[i][1] - p[i][0]) ^ (p[i][2] - p[i][0]);
        }
        double ans = 1e18;
        for(int i = 1; i <= n; ++i) {
            for(int j = i + 1; j <= n; ++j) {
                double d = 0;
                if(isParallel(normal[i], normal[j]))
                    d = point3ToLine(p[i][0], p[j][0], normal[j]);
                else d = lineToLine(p[i][0], normal[i], p[j][0], normal[j]);
                ans = min(ans, max(0.0, d - r[i] - r[j]));
            }
        }
        if(sgn(ans) == 0) puts("Lucky");
        else printf("%.2f\n", ans);
    }
    return 0;
}
