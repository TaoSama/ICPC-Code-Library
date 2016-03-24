//
//  Created by TaoSama on 2015-08-14
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
#include <cassert>
#include <vector>

using namespace std;
#define pr(x) cout << #x << " = " << x << "  "
#define prln(x) cout << #x << " = " << x << endl
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, r;
double p[25], sum[25];

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int kase = 0;
    while(scanf("%d%d", &n, &r) == 2 && (n || r)) {
        for(int i = 0; i < n; ++i) scanf("%lf", p + i);

        printf("Case %d:\n", ++kase);
        if(r == 0) {
            for(int i = 0; i < n; ++i) printf("%.6f\n", 0.0);
            continue;
        }

        memset(sum, 0, sizeof sum);

        int k = (1 << r) - 1;
        while(k < 1 << n) {
//          cout << k << endl;
            double cur = 1;
            for(int i = 0; i < n; ++i)  //calculate P(E)
                cur *= (k >> i & 1) ? p[i] : 1 - p[i];
            sum[n] += cur;

            for(int i = 0; i < n; ++i)  //calculate P(E_i)
                if(k >> i & 1) sum[i] += cur;

            int x = k & -k, y = k + x;  //next k-size set
            k = ((k & ~y) / x >> 1) | y;
        }

//        assert(sum[n] > 1e-10);
        for(int i = 0; i < n; ++i) printf("%.6f\n", sum[i] / sum[n]);
    }
    return 0;
}
