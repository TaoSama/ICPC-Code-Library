//
//  Created by TaoSama on 2017-04-10
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
#define pr(x) cerr << #x << " = " << x << "  "
#define prln(x) cerr << #x << " = " << x << endl
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

typedef long long Type;
struct Point {
    Type x, y;
    Point() {}
    Point(Type x, Type y) : x(x), y(y) {}
    void read() {scanf("%lld%lld", &x, &y);}
    void write() {printf("%lld %lld\n", x, y);}
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

Type dot(const Point& A, const Point& B) {
    return A.x * B.x + A.y * B.y;
}
Type det(const Point& A, const Point& B) {
    return A.x * B.y - A.y * B.x;
}

//输入不能有重点，函数执行完后输入顺序被破坏
Point ps[N], ch[N];
int convexHull(Point* p, int n, Point* ch) {
    sort(p, p + n);

    int m = 0;
    for(int i = 0; i < n; ++i) {
        while(m > 1 && det(ch[m - 1] - ch[m - 2], p[i] - ch[m - 2]) <= 0) --m;
        ch[m++] = p[i];
    }
    for(int i = n - 2, t = m; ~i; --i) {
        while(m > t && det(ch[m - 1] - ch[m - 2], p[i] - ch[m - 2]) <= 0) --m;
        ch[m++] = p[i];
    }
    if(n > 1) --m;
    return m;
}

vector<int> rotatingCalipers(Point* ch, int n) {
    if(n < 3) return vector<int>();

    Type ans = 0;
    vector<int> ret(3);

    ch[n] = ch[0];
    for(int i = 0; i < n; ++i) {
        for(int j = i + 1, k = j; j < n; ++j) {
            while(det(ch[j] - ch[i], ch[k + 1] - ch[i])
                    > det(ch[j] - ch[i], ch[k] - ch[i]))
                k = (k + 1) % n;
            if(det(ch[j] - ch[i], ch[k] - ch[i]) > ans) {
                ans = det(ch[j] - ch[i], ch[k] - ch[i]);
                ret = {i, j, k};
            }
        }
    }
    return ret;
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int n; long long s;
    scanf("%d%lld", &n, &s);
    for(int i = 0; i < n; ++i) ps[i].read();
    int m = convexHull(ps, n, ch);

    vector<int> triangle = rotatingCalipers(ch, m);
    for(int i = 0; i < 3; ++i) {
        Point p = ch[triangle[i]] + ch[triangle[(i + 1) % 3]] - ch[triangle[(i + 2) % 3]];
        p.write();
    }


    return 0;
}
