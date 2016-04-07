//
//  Created by TaoSama on 2016-03-31
//  Copyright (c) 2016 TaoSama. All rights reserved.
//
#pragma comment(linker, "/STACK:102400000,102400000")
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

int n;
struct Point {
    int x, y;
    void read() {
        scanf("%d%d", &x, &y);
    }
    Point operator-(const Point& p) const {
        return (Point) {x - p.x, y - p.y};
    }
    int operator^(const Point& p) const {
        return x * p.y - y * p.x;
    }
} p[N];

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d", &n) == 1) {
        for(int i = 1; i <= n + 1; ++i) p[i].read();
        int ans = 0;
        for(int i = 2; i <= n; ++i) {
            if(((p[i] - p[i - 1]) ^ (p[i + 1] - p[i])) > 0) ++ans;
        }
        printf("%d\n", ans);
    }
    return 0;
}
