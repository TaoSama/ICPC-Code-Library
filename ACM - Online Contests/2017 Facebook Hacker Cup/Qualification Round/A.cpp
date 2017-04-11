//
//  Created by TaoSama on 2017-01-08
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

double p, x, y;

int sq(int x) {return x * x;}

int main() {
#ifdef LOCAL
    freopen("progress_pie.txt", "r", stdin);
    freopen("progress_pie_out.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);

    int t; scanf("%d", &t);
    while(t--) {
        scanf("%lf%lf%lf", &p, &x, &y);
        p = p * 360 / 100;
        string ans = "white";
        if(x == 50 && y == 50) {
            if(p > 1e-8) ans = "black";
        } else {
            double ax = 50 - 50, ay = 100 - 50;
            double bx = x - 50, by = y - 50;
            double dotPdt = (ax * bx + ay * by);
            double disA = sqrt(sq(ax) + sq(ay));
            double disB = sqrt(sq(bx) + sq(by));
            double cosTheta = dotPdt / (disA * disB);
            double theta = acos(cosTheta) * 180 / acos(-1);
            if(x < 50) theta = 360 - theta;
            if(theta <= p - 1e-8 && disB <= 50 - 1e-8) ans = "black";
//            pr(theta); prln(p); prln(disB);
        }
        static int kase = 0;
        printf("Case #%d: %s\n", ++kase, ans.c_str());
    }

    return 0;
}
