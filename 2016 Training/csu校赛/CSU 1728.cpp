//
//  Created by TaoSama on 2016-04-28
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
const int N = 2e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n;
double a[N];

//minimize the maximum substring sum
double check(double x) {
    double minv, maxv, sum1, sum2;
    minv = maxv = sum1 = sum2 = 0;
    for(int i = 1; i <= n; ++i) {
        sum1 += a[i] - x;
        sum2 += a[i] - x;
        minv = min(minv, sum1);
        maxv = max(maxv, sum2);
        if(sum1 > 0) sum1 = 0;
        if(sum2 < 0) sum2 = 0;
    }
    return max(maxv, -minv);
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int t; scanf("%d", &t);
    while(t--) {
        scanf("%d", &n);
        for(int i = 1; i <= n; ++i) scanf("%lf", a + i);
        double l = 0, r = 1e4;
        for(int i = 1; i <= 100; ++i) {
            double ll = (2 * l + r) / 3;
            double rr = (l + 2 * r) / 3;
            if(check(ll) < check(rr)) r = rr;
            else l = ll;
        }
        printf("%.12f\n", l);
    }
    return 0;
}
