//
//  Created by TaoSama on 2015-09-11
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

int k;
double a, b;
double power(double x, int k) {
    double ret = 1;
    for(int i = 1; i <= k; ++i)
        ret *= x;
    return ret;
}

const double EPS = 1e-8;

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int kase = 0;
    int t; scanf("%d", &t);
    while(t--) {
        scanf("%d%lf%lf", &k, &a, &b);
        double ans = 0;
        if(abs(a - b) < EPS) ans = power(a, k);
        else {
            ans = 1.0 / (k + 1) * (power(b, k + 1) - power(a, k + 1));
            ans /= b - a;
        }
        printf("Case %d: %.12f\n", ++kase, ans);
    }
    return 0;
}
