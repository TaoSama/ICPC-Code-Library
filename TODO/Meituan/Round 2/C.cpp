//
//  Created by TaoSama on 2017-06-18
//  Copyright (c) 2017 TaoSama. All rights reserved.
//
#pragma comment(linker, "/STACK:102400000,102400000")
#include <bits/stdc++.h>

using namespace std;
#define pr(x) cerr << #x << " = " << x << "  "
#define prln(x) cerr << #x << " = " << x << endl
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, T, C;
int t[N], c[N];

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
//    ios_base::sync_with_stdio(0);

    cin >> n >> T >> C;
    double minv = 1e5, maxv = 0;
    int eq = 0;
    for(int i = 1; i <= n; ++i) {
        cin >> t[i] >> c[i];
        minv = min(1. * t[i], minv);
        maxv = max(1. * t[i], maxv);
        eq += t[i] == T;
    }
    if(eq > 0) {
        if(eq == n) printf("Possible\n%.4f\n", 1.0 * T);
        else puts("Impossible");
    } else {
        if(minv < T && maxv > T) puts("Impossible");
        else {
            if(minv >= T) {
                double to = minv, tot = 0;
                for(int j = 1; j <= n; ++j)
                    tot += 1. * (to - t[j]) * c[j] / (T - to);
                if(tot > C) puts("Impossible");
                else printf("Possible\n%.4f\n", to);
            } else if(maxv <= T) {
                double l = maxv, r = T;
                bool ok = false;
                for(int i = 1; i <= 100; ++i) {
                    double m = (l + r) / 2;
                    double tot = 0;
                    for(int j = 1; j <= n; ++j)
                        tot += 1. * (m - t[j]) * c[j] / (T - m);
                    if(tot > C) r = m;
                    else l = m, ok = true;
                }
                if(ok)printf("Possible\n%.4f\n", l);
                else puts("Impossible");
            } else {
                assert(false);
            }
        }
    }

    return 0;
}
