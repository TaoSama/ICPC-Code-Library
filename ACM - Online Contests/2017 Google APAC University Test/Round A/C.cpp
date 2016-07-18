//
//  Created by TaoSama on 2016-07-10
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

int n;
typedef long double LD;
const LD EPS = 1e-12;
int sgn(LD x) {
    return x < -EPS ? -1 : x > EPS;
}
LD coff[N];

LD calc(LD x) {
    LD ret = 0;
    x += 1;
    for(int i = n; ~i; --i) {
        ret += coff[i] * pow(x, i);
    }
    return ret;
}

int main() {
#ifdef LOCAL
    freopen("C-large.in", "r", stdin);
//    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
    freopen("C-large.out", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    clock_t _ = clock();

//  for(double i = 0; i <= 2; i += 0.1){
//      double x = -3000*i*i*i*i*i+100*i*i*i*i+100*i*i*i+100*i*i+100*i+100;
//      printf("%.2f %.10f\n", i, x);
//  }

    int t; scanf("%d", &t);
    while(t--) {
        scanf("%d", &n);
        for(int i = n; ~i; --i) {
            int x; scanf("%d", &x);
            if(i == n) x = -x;
            coff[i] = x;
        }

        LD x0;
        if(n == 1) {
            x0 = (-coff[0] - coff[1]) / coff[1];
        } else {

//        for(double i = 0; i <= 2; i += 0.1) {
//            double x = -3000 * i * i * i * i * i +
//            100 * i * i * i * i + 100 * i * i * i +
//                       100 * i * i + 100 * i + 100;
//            printf("%.2f %.10f\n", i, x);
//            printf("%.2f %.10f\n", i, (double) calc(i - 1));
//            puts("");
//        }
            LD l = -1, r = 1;
            for(int i = 1; i <= 1000; ++i) {
                LD ll = (2 * l + r) / 3;
                LD rr = (l + 2 * r) / 3;
                if(calc(ll) < calc(rr)) l = ll;
                else r = rr;
            }
            LD m = l;
//            printf("m = %.12f\n", (double)m);

            {
                LD l = -1, r = m;
                for(int i = 1; i <= 1000; ++i) {
                    LD m = (l + r) / 2;
                    if(calc(m) <= 0) x0 = m, l = m;
                    else r = m;
                }
                if(sgn(calc(l)) == 0) x0 = l;
            }
            {
                LD l = m, r = 1;
                for(int i = 1; i <= 1000; ++i) {
                    LD m = (l + r) / 2;
                    if(calc(m) <= 0) x0 = m, r = m;
                    else l = m;
                }
                if(sgn(calc(l)) == 0) x0 = l;
            }
//            printf("m = %.12f\n", (double)calc(1));
        }

        static int kase = 0;
        if(sgn(x0) == 0) x0 = 0;
        printf("Case #%d: %.12f\n", ++kase, (double)x0);
    }

#ifdef LOCAL
//    printf("\nTime cost: %.2fs\n", 1.0 * (clock() - _) / CLOCKS_PER_SEC);
#endif
    return 0;
}
