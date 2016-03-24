//
//  Created by TaoSama on 2015-09-26
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
const double PI = acos(-1);

struct Point {
    double x, y;
    void read() {
        scanf("%lf%lf", &x, &y);
    }
} A, B, C, M;

double getdis(Point& a, Point& b) {
    return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int t; scanf("%d", &t);
    int kase = 0;
    while(t--) {
        A.read(), B.read(), C.read();
        M.x = (B.x + C.x) / 2, M.y = (B.y + C.y) / 2;
        double a = getdis(B, M), b = getdis(A, B), h = getdis(A, M);
        double r = 2 * a * h / (2 * a + 2 * b);  //ÄÚ½ÓÔ²°ë¾¶
        double R = (a * a - r * r) / r / 2 + r; //
        double ans = 2 * R * asin(a / R) + h;
        printf("Case #%d: %.4f\n", ++kase, ans);
    }
    return 0;
}
