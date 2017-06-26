//
//  Created by TaoSama on 2017-04-22
//  Copyright (c) 2017 TaoSama. All rights reserved.
//
#pragma comment(linker, "/STACK:102400000,102400000")
#include <bits/stdc++.h>

using namespace std;
#define pr(x) cerr << #x << " = " << x << "  "
#define prln(x) cerr << #x << " = " << x << endl
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int d, n;

int main() {
#ifdef LOCAL
    freopen("A-large.in", "r", stdin);
    freopen("A-large.out", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);

    int t; scanf("%d", &t);
    while(t--) {
        double x = 0;
        scanf("%d%d", &d, &n);
        for(int i = 1; i <= n; ++i) {
            int k, s; scanf("%d%d", &k, &s);
            x = max(x, 1.0 * (d - k) / s);
        }
        static int kase = 0;
        printf("Case #%d: %.12f\n", ++kase, d / x);
    }

    return 0;
}
