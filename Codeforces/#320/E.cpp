//
//  Created by TaoSama on 2015-09-17
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
const int N = 2e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;
const double eps = 1e-8;

int n;
double a[N], b[N];

double check(double x) {
    for(int i = 1; i <= n; ++i) b[i] = a[i] - x;
    double sum = 0, ans1 = 0, ans2 = 0;
    for(int i = 1; i <= n; ++i) {
        sum += b[i];
        if(sum > ans1) ans1 = sum;
        if(sum < 1e-10) sum = 0;
    }
    sum = 0;
    for(int i = 1; i <= n; ++i) {
        sum += b[i];
        if(sum < ans2) ans2 = sum;
        if(sum > 1e-10) sum = 0;
    }
    return max(ans1, -ans2);
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d", &n) == 1) {
        for(int i = 1; i <= n; ++i) scanf("%lf", a + i);

        double l = -1e10, r = 1e10;
        for(int i = 1; i <= 300; ++i) {
            double ll = (l + r) / 2, rr = (ll + r) / 2;
            if(check(ll) < check(rr)) r = rr;
            else l = ll;
        }
//        printf("%.10f\n", l);
        printf("%.10f\n", check(l));
    }
    return 0;
}
