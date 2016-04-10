//
//  Created by TaoSama on 2016-04-09
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

double y;
double f(double x) {
    return pow(x, 7) + 8 * pow(x, 6) + 3 * pow(x, 2) - y * x;
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%lf", &y) == 1) {
        double l = 0, r = 100;
        for(int i = 1; i <= 100; ++i) {
            double ll = (2 * l + r) / 3;
            double rr = (l + 2 * r) / 3;
            if(f(ll) < f(rr)) r = rr;
            else l = ll;
        }
        printf("%.4f\n", f(l));
    }
    return 0;
}
