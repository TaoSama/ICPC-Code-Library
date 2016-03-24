//
//  Created by TaoSama on 2015-08-24
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

char name[10];
double h, vx, vy, t, v1, v2, v3;

const double g = 9.8;
double getT(double vy, double h) {
    return (vy + sqrt(vy * vy + 2 * g * h)) / g;
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%lf%s%lf%lf", &h, name, &vx, &vy) == 4) {
        double T = getT(vy, h);
        if(name[0] == 'R') printf("%.3f\n", T * vx);
        else if(name[0] == 'B') {
            scanf("%lf%lf%lf%lf", &t, &v1, &v2, &v3);
            if(t >= T) printf("%.3f\n", T * vx);
            else {
                T -= t;
                printf("%.3f %.3f %.3f\n", T * v1 + t * vx, T * v2 + t * vx, T * v3 + t * vx);
            }
        } else {
            scanf("%lf", &t);
            if(t >= T) printf("%.3f\n", T * vx);
            else {
                h += vy * t - g * t * t / 2;
                vy -= g * t;
                T = getT(2 * vy, h);
                printf("%.3f\n", T * 2 * vx + vx * t);
            }
        }
    }
    return 0;
}
