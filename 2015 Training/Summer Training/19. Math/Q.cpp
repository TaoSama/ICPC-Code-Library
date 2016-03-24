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
#include <vector>

using namespace std;
#define pr(x) cout << #x << " = " << x << "  "
#define prln(x) cout << #x << " = " << x << endl
const int N = 2e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

//fuck ya! long double
long double logF[N];
void gao() {
    logF[0] = 0;
    for(int i = 1; i < N; ++i)
        logF[i] = logF[i - 1] + log(i);
}

//C(n, m) = n!/m!/(n-m)!
long double logC(int n, int m) {
    return logF[n] - logF[m] - logF[n - m];
}

int n;
long double p;

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int kase = 0;
    gao();
//  printf("%d\n", sizeof (long double));
    while(scanf("%d%Lf", &n, &p) == 2) {
        if(p == 0 || p == 1) {
            printf("Case %d: %.6Lf\n", ++kase, 1.0 * n);
            continue;
        }
        long double ans = 0, a = log(p), b = log(1 - p);
        for(int i = 0; i <= n; ++i) {
            long double C = logC(2 * n - i, n);
            long double v1 = C + (n + 1) * a + (n - i) * b;
            long double v2 = C + (n + 1) * b + (n - i) * a;
            ans += i * (exp(v1) + exp(v2));
        }
        printf("Case %d: %.6Lf\n", ++kase, ans);
    }
    return 0;
}
