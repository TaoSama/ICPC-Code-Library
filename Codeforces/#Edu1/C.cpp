//
//  Created by TaoSama on 2015-11-13
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
const long double PI = acosl(-1), EPS = 1e-10;

int n;

int sgn(long double x) {
    return x < -EPS ? -1 : x < EPS ? 0 : 1;
}

struct Point {
    int x, y, id;
    long double ang;
    void read() {
        scanf("%d%d", &x, &y);
        ang = atan2l(y, x);
    }
    Point operator- (const Point& p) const {
        return (Point) {x - p.x, y - p.y};
    }
    int operator* (const Point& p) const {
        return x * p.x + y * p.y;
    }
    int operator^ (const Point& p) const {
        return x * p.y - y * p.x;
    }
    bool operator< (const Point& p) const {
        return ang < p.ang;
    }
} a[N];

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d", &n) == 1) {
        for(int i = 0; i < n; ++i) {
            a[i].read();
            a[i].id = i + 1;
        }
        sort(a, a + n);
        a[n] = a[0];
        a[n].ang += 2 * PI;

        long double angle = INF;
        int ansx, ansy;
        for(int i = 1; i <= n; ++i) {
            long double tmp = a[i].ang - a[i - 1].ang;
            if(tmp < angle) {
                angle = tmp;
                ansx = a[i - 1].id;
                ansy = a[i].id;
            }
        }
        printf("%d %d\n", ansx, ansy);
    }
    return 0;
}
