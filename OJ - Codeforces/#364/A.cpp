//
//  Created by TaoSama on 2016-07-23
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

int n, l, v1, v2, k;

bool check(double x) {
    int times = (n + k - 1) / k;

    double t1 = (l - v2 * x) / (v1 - v2), t2 = x - t1;
    double before = v2 * t2, useT = t2;
//  pr(before); pr(useT); prln(leftT);
    for(int i = 2; i <= times; ++i) {
        double cur = v1 * useT;
        double diff = before - cur;
        double backT = diff / (v1 + v2);
//        pr(cur); pr(diff); prln(backT);

        useT += backT;
        cur += v1 * backT;
        before += v1 * backT;
//        pr(useT); pr(cur); prln(before);

        double toT = (before - cur) / (v2 - v1);
        useT += toT;
        before += v1 * toT;
        cur += v2 * toT;
//      pr(useT); pr(cur); prln(before);
    }
    return useT <= x;
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);
    clock_t _ = clock();

    while(cin >> n >> l >> v1 >> v2 >> k) {

        double l = 0, r = INF;
        for(int i = 1; i <= 100; ++i) {
            double m = (l + r) / 2;
            if(check(m)) r = m;
            else l = m;
        }

        printf("%.12f\n", l);
    }

#ifdef LOCAL
    printf("\nTime cost: %.2fs\n", 1.0 * (clock() - _) / CLOCKS_PER_SEC);
#endif
    return 0;
}
