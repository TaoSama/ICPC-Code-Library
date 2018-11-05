
//  Created by TaoSama.
//  Copyright (c) 2017 TaoSama. All rights reserved.
//
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

const double EPS = 1e-8;

int sgn(double x) {
    return x < -EPS ? -1 : x > EPS;
}

struct Point {
    int x, y;
    Point() {}
    Point(int x, int y): x(x), y(y) {}
    bool read() {
        return scanf("%d%d", &x, &y) == 2;
    }
    Point operator-(const Point& p) const {
        return Point(x - p.x, y - p.y);
    }
    int operator*(const Point& p) const {
        return x * p.x + y * p.y;
    }
    int operator^(const Point& p) const {
        return x * p.y - y * p.x;
    }
} pa[4], pb[4];
bool segmentProperIntersection(Point a1, Point a2, Point b1, Point b2) {
    int c1 = (a2 - a1) ^ (b1 - a1), c2 = (a2 - a1) ^ (b2 - a1);
    int c3 = (b2 - b1) ^ (a1 - b1), c4 = (b2 - b1) ^ (a2 - b1);
    return c1 * c2 <= 0 && c3 * c4 <= 0;
}
bool onSegment(Point p, Point a1, Point a2) {
    return ((a1 - p) ^ (a2 - p)) == 0 && (a1 - p) * (a2 - p) <= 0;
}
int main(){
#ifdef LOCAL
    freopen("/Users/didi/ACM/in.txt", "r", stdin);
//  freopen("/Users/didi/ACM/out.txt", "w", stdout);
#endif
    ios::sync_with_stdio(0); cin.tie(0);
    
    while(pa[0].read()) {
        for(int i = 1; i < 4; ++i) pa[i].read();
        for(int i = 0; i < 4; ++i) pb[i].read();
        bool ok = false;
        for(int i = 0; i < 4; ++i) {
            for(int j = 0; j < 4; ++j) {
                ok |= segmentProperIntersection(pa[i], pa[(i + 1) % 4], pb[j], pb[(j + 1) % 4]);
                ok |= onSegment(pa[i], pb[j], pb[(j + 1) % 4]);
                ok |= onSegment(pb[j], pa[i], pa[(i + 1) % 4]);
                ok |= onSegment(pa[(i + 1) % 4], pb[j], pb[(j + 1) % 4]);
                ok |= onSegment(pb[(j + 1) % 4], pa[i], pa[(i + 1) % 4]);

            }
        }
        int minx = INF, maxx = -INF;
        int miny = INF, maxy = -INF;
        for(int i = 0; i < 4; ++i) {
           minx = min(pa[i].x, minx); 
           miny = min(pa[i].y, miny); 
           maxx = max(pa[i].x, maxx); 
           maxy = max(pa[i].y, maxy); 
        }
        double mina = max(maxx - minx, maxy - miny) / 2.0;
        double midax = 1.0 * (pb[0].x + pb[2].x) / 2;
        double miday = 1.0 * (pb[0].y + pb[2].y) / 2;
        minx = INF, maxx = -INF;
        miny = INF, maxy = -INF;
        for(int i = 0; i < 4; ++i) {
           minx = min(pb[i].x, minx); 
           miny = min(pb[i].y, miny); 
           maxx = max(pb[i].x, maxx); 
           maxy = max(pb[i].y, maxy); 
        }
        double minb = max(maxx - minx, maxy - miny) / 2.0 / sqrt(2);
        double midbx = 1.0 * (pa[0].x + pa[2].x) / 2;
        double midby = 1.0 * (pa[0].y + pa[2].y) / 2;
        double dis = sqrt(pow(midax - midbx, 2) + pow(miday - midby, 2));
        ok |= sgn(dis - max(mina, minb)) <= 0;
        puts(ok ? "YES" : "NO");
    }
    return 0;
}
