//
//  Created by TaoSama on 2015-05-07
//  Copyright (c) 2015 TaoSama. All rights reserved.
//
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
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int N = 1e5 + 10;

int n;
double x[305], y[305], vx[305], vy[305];

double getdis(int i, int j, double t) {
    return ((x[i] + t * vx[i]) - (x[j] + t * vx[j])) *
           ((x[i] + t * vx[i]) - (x[j] + t * vx[j])) +
           ((y[i] + t * vy[i]) - (y[j] + t * vy[j])) *
           ((y[i] + t * vy[i]) - (y[j] + t * vy[j]));
}

double cal(double t) {
    double Max = 0;
    for(int i = 1; i <= n; ++i) {
        for(int j = i + 1; j <= n; ++j) {
            Max = max(Max, getdis(i, j, t));
        }
    }
    return Max;
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
        scanf("%d", &n);
        for(int i = 1; i <= n; ++i) {
            scanf("%lf%lf%lf%lf",
                  x + i, y + i, vx + i, vy + i);
        }

        double l = 0, r = 1e10;
        for(int i = 1; i <= 100; ++i) {
            double ll = l + (r - l) / 3, rr =  r - (r - l) / 3;
            //cout << ll << ' ' << cal(ll) << endl;
            //cout << rr << ' ' << cal(rr) << endl;

            if(cal(ll) < cal(rr)) r = rr;
            else l = ll;
        }
        printf("Case #%d: %.2f %.2f\n", ++kase, l, sqrt(cal(l)));
    }
    return 0;
}
