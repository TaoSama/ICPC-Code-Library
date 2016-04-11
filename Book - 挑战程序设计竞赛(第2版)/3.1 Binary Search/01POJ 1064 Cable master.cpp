//
//  POJ 1064  Cable master
//
//  Created by TaoSama on 2015-04-18
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

int n, k;
double a[10005];

bool check(double x) {
    int sum = 0;
    for(int i = 1; i <= n; ++i)
        sum += (int)(a[i] / x);
    return sum >= k;
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d%d", &n, &k) == 2) {
        for(int i = 1; i <= n; ++i) {
            scanf("%lf", a + i);
        }
        double l = 0, r = 1e5 + 5;
        for(int i = 1; i <= 100; ++i) {
            double mid = (l + r) / 2;
            if(check(mid)) l = mid;
            else r = mid;
        }
        printf("%.2f\n", floor(l * 100) / 100);
    }
    return 0;
}
