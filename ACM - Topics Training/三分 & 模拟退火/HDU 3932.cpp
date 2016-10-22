//
//  Created by TaoSama on 2016-07-12
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

struct Point {
    double x, y;
    Point() {}
    Point(double x, double y) : x(x), y(y) {}
    void read() { scanf("%lf%lf", &x, &y); }
    Point operator-(const Point& p) const {
        return Point(x - p.x, y - p.y);
    }
    double operator*(const Point& p) const {
        return x * p.x + y * p.y;

    }
    bool operator<(const Point& p) const {
        return make_pair(x, y) < make_pair(p.x, p.y);
    }
    double length() {
        return sqrt(*this * *this);
    }
} ps[1005];

int X, Y, n;

double getMax(Point p) {
    double ret = -1e18;
    for(int i = 1; i <= n; ++i)
        ret = max(ret, (p - ps[i]).length());
    return ret;
}

bool canAccept(double newOne, double old, double T) {
    static int limit = 10000;
    return exp(-(newOne - old) / T) > 1.0 * rand() / limit;
}

double nextRandom(int limit) {
    static int sgn[2] = { -1, 1};
    return sgn[rand() % 2] * (rand() % limit + 1);
}

const double PI = acos(-1);

//最小圆覆盖 随机角度更好？
void solve() {
    double st = 1e3, ed = 1e-3, DELTA = 0.9;

    pair<double, Point> ret = {1e18, { -1, -1}};
    vector<Point> v(20);
    for(auto& p : v) {
        p = ps[rand() % n + 1];
        ret = min(ret, {getMax(p), p});
    }

    int cnt = 0;
    for(double T = st; T > ed; T *= DELTA) {
        ++cnt;
        for(auto& p : v) {
            for(int i = 0; i < v.size(); ++i) {
                Point np = p;
                double theta = 2 * PI * rand() / RAND_MAX;
                np.x += T * cos(theta);
                np.y += T * sin(theta);
                if(np.x < 0 || np.x > X) continue;
                if(np.y < 0 || np.y > Y) continue;
                double old = getMax(p);
                double newOne = getMax(np);
                if(newOne < old || canAccept(newOne, old, T)) p = np;
                ret = min(ret, {newOne, np});
            }
        }
    }
//    prln(cnt);

    double d; Point p; tie(d, p) = ret;
    printf("(%.1f,%.1f).\n%.1f\n", p.x, p.y, d);
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);
    clock_t _ = clock();
    srand(time(0));

    while(scanf("%d%d%d", &X, &Y, &n) == 3) {
        for(int i = 1; i <= n; ++i) ps[i].read();
        solve();
    }

#ifdef LOCAL
    printf("\nTime cost: %.2fs\n", 1.0 * (clock() - _) / CLOCKS_PER_SEC);
#endif
    return 0;
}

