//
//  Created by TaoSama on 2015-12-09
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

int w, h, x, xe, ye;
double miu;

double sq(double x) {return x * x;}

bool check(double d) {
    double sinMPE = (xe - w) / (sqrt(sq(xe - w) + sq(ye - h)));
    double sinCPN = sinMPE / miu;
    double rig = (h - d) / (ye - h) * (xe - w);
    double CN = d / sqrt(1 / sq(sinCPN) - 1);
    double p = w - CN - rig;
    return p >= x;
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int t; scanf("%d", &t);
    while(t--) {
        scanf("%d%d%d%d%d%lf", &w, &h, &x, &xe, &ye, &miu);
        double l = 0, r = h + 1;
        for(int i = 1; i <= 100; ++i) {
            double m = (l + r) / 2;
            if(check(m)) r = m;
            else l = m;
        }
        if(l <= h) printf("%.4f\n", l);
        else puts("Impossible");
    }
    return 0;
}
