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

struct Point {
    int x, y;
    Point() {}
    Point(int x, int y): x(x), y(y) {}
    void read() {
        scanf("%d%d", &x, &y);
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
    bool operator<(const Point& p) const {
        return x == p.x && y < p.y || x < p.x;
    }
    int length() {
        return *this * *this;
    }
} ps[N];

//输入不能有重点，函数执行完后输入顺序被破坏
Point ch[N];
int convexHull(Point* p, int n, Point* ch) {
    sort(p, p + n);

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

int rotatingCalipers(Point* ch, int n) {
    if(n < 3) return 0;

    int ret = 0;
    ch[n] = ch[0];
    for(int i = 0; i < n; ++i) {
        for(int j = i + 1, k = j + 1; j < n; ++j) {
            while(((ch[j] - ch[i]) ^ (ch[k + 1] - ch[i]))
                    > ((ch[j] - ch[i]) ^ (ch[k] - ch[i])))
                k = (k + 1) % n;
            ret = max(ret, abs((ch[k] - ch[i]) ^ (ch[j] - ch[i])));
        }
    }
    return ret;
}

int n;

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d", &n) == 1 && (~n)) {
        for(int i = 0; i < n; ++i) ps[i].read();
        int m = convexHull(ps, n, ch);
        int ans = rotatingCalipers(ch, m);
        printf("%.2f\n", 0.5 * ans + 1e-5);
    }

    return 0;
}
