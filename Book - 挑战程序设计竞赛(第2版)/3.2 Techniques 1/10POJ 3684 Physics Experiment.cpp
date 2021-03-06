//
//  Created by TaoSama on 2016-07-29
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

int n, H, R, T;

double calc(int T) {
    if(T < 0) return H;
    double cycle = sqrt(2.0 * H / 10);
    int times = T / cycle;
    if(times & 1) {
        double t = (times + 1) * cycle - T;
        return H - 10 * t * t / 2;
    } else {
        double t = T - times * cycle;
        return H - 10 * t * t / 2;
    }
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);
    clock_t _ = clock();

    int t; scanf("%d", &t);
    while(t--) {
        scanf("%d%d%d%d", &n, &H, &R, &T);

        vector<double> v(n);
        for(int i = 0; i < n; ++i)
            v[i] = calc(T - i);
        sort(v.begin(), v.end());

        for(int i = 0; i < n; ++i)
            printf("%.2f%c", v[i] + 2.0 * R * i / 100, " \n"[i == n - 1]);
    }

#ifdef LOCAL
    printf("\nTime cost: %.2fs\n", 1.0 * (clock() - _) / CLOCKS_PER_SEC);
#endif
    return 0;
}
