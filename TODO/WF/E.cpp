//
//  Created by TaoSama on 2017-05-24
//  Copyright (c) 2017 TaoSama. All rights reserved.
//
#pragma comment(linker, "/STACK:102400000,102400000")
#include <bits/stdc++.h>

using namespace std;
#define pr(x) cerr << #x << " = " << x << "  "
#define prln(x) cerr << #x << " = " << x << endl
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, t;
int d[N], s[N];

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d%d", &n, &t) == 2) {
        double l = 1e9, r = 1e9;
        for(int i = 1; i <= n; ++i) {
            scanf("%d%d", d + i, s + i);
            l = min(l, 1.* s[i]);
        }
        l = -l + 1e-8;
        for(int i = 1; i <= 100; ++i) {
            double m = (l + r) / 2;
            double ret = 0;
            for(int j = 1; j <= n; ++j) ret += 1. * d[j] / (s[j] + m);
            if(ret < t) r = m;
            else l = m;
        }
        printf("%.12f\n", l);
    }

    return 0;
}
