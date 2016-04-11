//
//  Created by TaoSama on 2015-11-19
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

struct Point {
    int x, y;
    void read() {scanf("%d%d", &x, &y);}
    Point operator- (const Point& p) const {
        return (Point) {x - p.x, y - p.y};
    }
    int operator^(const Point& p) const {
        return x * p.y - y * p.x;
    }
} a[3];

int getArea2() {
    return (a[1] - a[0]) ^ (a[2] - a[0]);
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(true) {
        bool ok = false;
        for(int i = 0; i < 3; ++i) {
            a[i].read();
            if(a[i].x || a[i].y) ok = true;
        }
        if(!ok) break;

        //pick theorem S = in + side/2 - 1
        int s = abs(getArea2()), side = 3;
        for(int i = 0; i < 3; ++i) {
            Point t = a[i] - a[(i + 1) % 3];
            side += abs(__gcd(t.x, t.y)) - 1;
        }
        int ans = s + 2 - side >> 1;
        printf("%d\n", ans);
    }
    return 0;
}
