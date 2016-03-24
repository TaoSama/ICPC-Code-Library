//
//  Created by TaoSama on 2015-05-07
//  Copyright (c) 2015 TaoSama. All rights reserved.
//
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
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int N = 1e5 + 10;

struct   TPoint {
    double x, y;
};
TPoint a[5], d;
double r;

double   getdis(TPoint   p1,   TPoint   p2) {
    return (sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y)));
}
double multiply(TPoint   p1,   TPoint   p2,   TPoint   p0) {
    return ((p1.x - p0.x) * (p2.y - p0.y) - (p2.x - p0.x) * (p1.y - p0.y));
}
void MiniDiscWith2Point(TPoint   p, TPoint   q, int   n) {
    d.x = (p.x + q.x) / 2.0;
    d.y = (p.y + q.y) / 2.0;
    r = getdis(p, q) / 2;
    int k;
    double c1, c2, t1, t2, t3;
    for(k = 1; k <= n; k++) {
        if(getdis(d, a[k]) <= r)continue;
        if(multiply(p, q, a[k]) != 0.0) {
            c1 = (p.x * p.x + p.y * p.y - q.x * q.x - q.y * q.y) / 2.0;
            c2 = (p.x * p.x + p.y * p.y - a[k].x * a[k].x - a[k].y * a[k].y) / 2.0;

            d.x = (c1 * (p.y - a[k].y) - c2 * (p.y - q.y)) / ((p.x - q.x) *
                    (p.y - a[k].y) - (p.x - a[k].x) * (p.y - q.y));
            d.y = (c1 * (p.x - a[k].x) - c2 * (p.x - q.x)) / ((p.y - q.y) *
                    (p.x - a[k].x) - (p.y - a[k].y) * (p.x - q.x));
            r = getdis(d, a[k]);
        } else {
            t1 = getdis(p, q);
            t2 = getdis(q, a[k]);
            t3 = getdis(p, a[k]);
            if(t1 >= t2 && t1 >= t3)
            {d.x = (p.x + q.x) / 2.0; d.y = (p.y + q.y) / 2.0; r = getdis(p, q) / 2.0;}
            else if(t2 >= t1 && t2 >= t3)
            {d.x = (a[k].x + q.x) / 2.0; d.y = (a[k].y + q.y) / 2.0; r = getdis(a[k], q) / 2.0;}
            else
            {d.x = (a[k].x + p.x) / 2.0; d.y = (a[k].y + p.y) / 2.0; r = getdis(a[k], p) / 2.0;}
        }
    }

}
void MiniDiscWithPoint(TPoint   pi, int   n) {
    d.x = (pi.x + a[1].x) / 2.0;
    d.y = (pi.y + a[1].y) / 2.0;
    r = getdis(pi, a[1]) / 2.0;
    int j;
    for(j = 2; j <= n; j++) {
        if(getdis(d, a[j]) <= r)continue;
        else {
            MiniDiscWith2Point(pi, a[j], j - 1);
        }
    }

}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int i, n = 3;
    int t; scanf("%d", &t);
    int kase = 0;
    while(t--) {
        printf("Case #%d: ", ++kase);
        for(i = 1; i <= n; i++) {
            scanf("%lf %lf", &a[i].x, &a[i].y);
        }
        scanf("%lf%lf", &a[4].x, &a[4].y);
        if(n == 1) {
            printf("%.2lf %.2lf 0.00\n", a[1].x, a[1].y);
            continue;
        }
        r = getdis(a[1], a[2]) / 2.0;
        d.x = (a[1].x + a[2].x) / 2.0;
        d.y = (a[1].y + a[2].y) / 2.0;
        for(i = 3; i <= n; i++) {
            if(getdis(d, a[i]) <= r)continue;
            else
                MiniDiscWithPoint(a[i], i - 1);
        }
        //printf("%.2lf %.2lf %.2lf\n", d.x, d.y, r);
        if(getdis(d, a[4]) <= r) printf("Danger\n");
        else printf("Safe\n");
    }
    return 0;
}
