//
//  Created by TaoSama on 2016-01-20
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

#define double long double
const double PI = acosl(-1);

int x1, y1, r1, x2, y2, r2;

typedef long long LL;
LL sq(LL x) {return x * x;}

double gao() {
    double ret = 0;
    long long dis = sq(x1 - x2) + sq(y1 - y2);
    if(dis >= sq(r1 + r2)) return 0;
    if(dis <= sq(abs(r1 - r2))) return PI * sq(min(r1, r2));
    double alpha = 2 * acosl((sq(r1) + dis - sq(r2)) / 2.0 / r1 / sqrt(dis));
    double beta = 2 * acosl((sq(r2) + dis - sq(r1)) / 2.0 / r2 / sqrt(dis));
    ret += 0.5 * (alpha * sq(r1) + beta * sq(r2));
    ret -= 0.5 * (sinl(alpha) * sq(r1) + sinl(beta) * sq(r2));
    return ret;
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
//    ios_base::sync_with_stdio(0);

    while(scanf("%d%d%d%d%d%d", &x1, &y1, &r1, &x2, &y2, &r2) == 6) {
        cout << fixed << setprecision(20) << gao() << '\n';
    }
    return 0;
}
