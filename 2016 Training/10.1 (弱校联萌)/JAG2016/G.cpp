//
//  Created by TaoSama on 2016-10-03
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

typedef long long LL;

struct Point {
    LL x, y;
    Point() {}
    Point(LL x, LL y): x(x), y(y) {}
    void read() {
        scanf("%lld%lld", &x, &y);
    }
    Point operator-(const Point& p) const {
        return Point(x - p.x, y - p.y);
    }
    LL operator*(const Point& p) const {
        return x * p.x + y * p.y;
    }
    LL operator^(const Point& p) const {
        return x * p.y - y * p.x;
    }
    bool operator<(const Point& p) const {
        return x == p.x && y < p.y || x < p.x;
    }
    LL length() {
        return *this * *this;
    }
} ps[N];

//输入不能有重点，函数执行完后输入顺序被破坏
Point ch[N], ch2[N];
int convexHull(vector<Point>& p, int n, Point* ch) {

    sort(p.begin(), p.end());

    n = p.size();

    int m = 0;
    for(int i = 0; i < n; ++i) {
        while(m > 1 && ((ch[m - 1] - ch[m - 2]) ^ (p[i] - ch[m - 2])) <= 0) --m;
        ch[m++] = p[i];
    }
    for(int i = n - 2, t = m; ~i; --i) {
        while(m > t && ((ch[m - 1] - ch[m - 2]) ^ (p[i] - ch[m - 2])) <= 0) --m;
        ch[m++] = p[i];
    }
    if(n > 1) --m;
    return m;
}

LL area(int n, Point* p) {
    LL ret = 0;
    for(int i = 1; i + 1 < n; ++i) {
        ret += (p[i] - p[0]) ^ (p[i + 1] - p[0]);
    }
    return abs(ret);
}

int n;

LL get(vector<Point>& l) {
    if(l.size() == 0) return 0;

    vector<int> xs, ys;
    for(int i = 0; i < l.size(); ++i) {
        xs.push_back(l[i].x);
        ys.push_back(l[i].y);
    }
    sort(xs.begin(), xs.end());
    xs.resize(unique(xs.begin(), xs.end()) - xs.begin());
    sort(ys.begin(), ys.end());
    ys.resize(unique(ys.begin(), ys.end()) - ys.begin());

    if(xs.size() == 1 || ys.size() == 1) return 0;

    int m1 = convexHull(l, 0, ch);
    LL area1 = area(m1, ch);
    return area1;
}

LL calc(int x) {
    vector<Point> l, r;
    for(int i = 0; i < n; ++i)
        if(ps[i].x < x) l.push_back(ps[i]);
        else r.push_back(ps[i]);


//  prln(x);
//  pr(get(l)); prln(get(r));
    return get(l) + get(r);
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d", &n) == 1) {
        vector<int> xs;
        for(int i = 0; i < n; ++i) {
            ps[i].read();
            xs.push_back(ps[i].x);
        }
        sort(xs.begin(), xs.end());
        xs.resize(unique(xs.begin(), xs.end()) - xs.begin());

        if(xs.size() == 1) {
            puts("0");
            continue;
        }

//        int l = 0, r = xs.size() - 1;
//        for(int i = 0; i < 40; ++i) {
//            int ll = (2 * l + r) / 3, rr = (l + 2 * r) / 3;
//            if(calc(xs[ll]) < calc(xs[rr])) l = ll + 1;
//            else r = rr - 1;
//        }

//      prln(1);

        LL ans = 9e18;

//      for(int i = 0; i < xs.size(); ++i){
//          pr(xs[i]); prln(calc(xs[i]));
//      }

        for(int i = 0; i <= 300; ++i) {
            int t = rand() % xs.size();
            ans = min(ans, calc(xs[t]));
        }
        printf("%I64d\n", (ans + 1) / 2);

//      return 0;
    }

    return 0;
}
