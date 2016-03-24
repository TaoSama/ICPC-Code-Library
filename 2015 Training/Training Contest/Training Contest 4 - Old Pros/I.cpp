//
//
//
//  Created by TaoSama on 2015-03-29
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
const double pi = acos(-1);

int n, f;
double p[10005];

bool check(double x) {
    int sum = 0;
    for(int i = 1; i <= n; ++i)
        sum += (int)(p[i] / x);
    return sum >= f + 1;
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//	freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int t; cin >> t;
    while(t--) {
        cin >> n >> f;
        for(int i = 1; i <= n; ++i) {
            cin >> p[i];
            p[i] = pi * p[i] * p[i];
        }

        double l = 0, r = 1e18;
        for(int i = 1; i <= 100; ++i) {
            double mid = (l + r) / 2;
            if(check(mid)) l = mid;
            else r = mid;
        }
        printf("%.4f\n", l);
    }
    return 0;
}
