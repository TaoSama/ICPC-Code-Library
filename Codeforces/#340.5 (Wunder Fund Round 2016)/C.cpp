//
//  Created by TaoSama on 2016-01-30
//  Copyright (c) 2015 TaoSama. All rights reserved.
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
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;
const long double EPS = 1e-10;

int n;
struct Point {
    int x, y, id;
    void read() {
        scanf("%d%d", &x, &y);
    }
    Point operator-(const Point& p) const {
        return (Point) {x - p.x, y - p.y};
    }
    long long operator^(const Point& p) const {
        return 1LL * x * p.y - 1LL * y * p.x;
    }
    long long length() {
        return 1LL * x * x + 1LL * y * y;
    }
} p[N];

bool cmp(Point A, Point B) {
    Point c = A - p[1], d = B - p[1];
    return atan2l(c.y, c.x) < atan2l(d.y, d.x);
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d", &n) == 1) {
        for(int i = 1; i <= n; ++i) p[i].read(), p[i].id = i;
        sort(p + 2, p + 1 + n, cmp);
        int ans2 = 2, ans3;
        for(int i = 3; i <= n; ++i) {
            while(i <= n && ((p[i] - p[1]) ^ (p[ans2] - p[1])) == 0) {
                Point c = p[i] - p[1], d = p[ans2] - p[1];
                if(c.length() < d.length()) {
                    ans2 = i;
                }
                ++i;
            }
            ans3 = i;
            break;
        }

        for(int i = ans3 + 1; i <= n; ++i) {
            while(i <= n && ((p[i] - p[1]) ^ (p[ans3] - p[1])) == 0) {
                Point c = p[i] - p[1], d = p[ans3] - p[1];
                if(c.length() < d.length()) {
                    ans3 = i;
                }
                ++i;
            }
            break;
        }
        printf("%d %d %d\n", p[1].id, p[ans2].id, p[ans3].id);
    }
    return 0;
}
