//
//  Created by TaoSama on 2016-12-20
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
    void read() {
        scanf("%d%d", &x, &y);
    }
    bool operator<(const Point& p) const {
        return make_pair(x, y) < make_pair(p.x, p.y);
    }
    Point operator+(const Point& p) {
        return {x + p.x, y + p.y};
    }
    Point operator-(const Point& p) {
        return {x - p.x, y - p.y};
    }
} ps[4];


int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    for(int i = 0; i < 3; ++i) {
        ps[i].read();
    }
    set<Point> v;
    v.insert(ps[0] + ps[1] - ps[2]);
    v.insert(ps[0] + ps[2] - ps[1]);
    v.insert(ps[1] + ps[2] - ps[0]);
    printf("%d\n", v.size());
    for(auto p : v) printf("%d %d\n", p.x, p.y);

    return 0;
}
