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

int a[3];
const double PI = acos(-1);


int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int t; scanf("%d", &t);
    while(t--) {
        for(int i = 0; i < 3; ++i) scanf("%d", a + i);

        double r1 = 0, r2 = 0, r3 = 0;
        for(int i = 0; i < 3; ++i) {
            double r1t = r1 ? 0 : min(a[0] - r2, a[2] - r3);
            double r2t = r2 ? 0 : min(a[0] - r1, a[1] - r3);
            double r3t = r3 ? 0 : min(a[1] - r2, a[2] - r1);
            double maxr = max(r1t, max(r2t, r3t));
//            pr(r1t); pr(r2t); prln(r3t);

//            pr(i); prln(maxr);
            if(r1t == maxr) r1 = r1t;
            else if(r2t == maxr) r2 = r2t;
            else  r3 = r3t;
        }
//        pr(r1); pr(r2); prln(r3);

        double ans = PI * (r1 * r1 + r2 * r2 + r3 * r3);
        printf("%.12f\n", ans);
//        printf("r1 = %f s = %f\n", 0.0, check(0));
//        double l = 0, r = min(a, c);
//        for(int i = 1; i <= 100; ++i) {
//            double ll = (2 * l + r) / 3;
//            double rr = (l + 2 * r) / 3;
//            if(check(ll) < check(rr)) l = ll;
//            else r = rr;
//        }
//        printf("%.12f\n", check(l));
    }

    return 0;
}
