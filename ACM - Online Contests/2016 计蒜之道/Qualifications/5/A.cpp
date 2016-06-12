//
//  Created by TaoSama on 2016-06-11
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

int n, k;
double l;
double getTan(double l, double alpha) {
    return sqrt(2 * l * l - 2 * l * l * cos(alpha));
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);
    clock_t _ = clock();

    while(scanf("%d%d%lf", &n, &k, &l) == 3) {
        double alpha = acos(-1) * (n - 2) / n;
        double ans = (n - 1) * l;
        if(k > 0) {
            ans += 0.5 * l;
            for(int i = 1; i <= k; ++i) {
                l = getTan(l / 2, alpha);
                ans += (n - 1) * l;
                if(i != k) ans += 0.5 * l;
            }
        }
        printf("%.12f\n", ans);
    }

#ifdef LOCAL
    printf("\nTime cost: %.2fs\n", 1.0 * (clock() - _) / CLOCKS_PER_SEC);
#endif
    return 0;
}
