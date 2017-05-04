//
//  Created by TaoSama on 2017-04-24
//  Copyright (c) 2017 TaoSama. All rights reserved.
//
#pragma comment(linker, "/STACK:102400000,102400000")
#include <bits/stdc++.h>

using namespace std;
#define pr(x) cerr << #x << " = " << x << "  "
#define prln(x) cerr << #x << " = " << x << endl
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n;
int x1, y1, x2, y2;
int x[N], y[N], vx[N], vy[N];

pair<double, double> get(int x, int v, int l, int r) {
    if(v == 0) {
        if(x > l && x < r) return {0.0, 1e9};
        else return{1e9, -1e9};
    }
    if(v < 0) return get(-x, -v, -r, -l);
    if(x <= r) return {max(0.0, 1. * (l - x) / v), 1. * (r - x) / v};
    return {1e9, -1e9};
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d", &n) == 1) {
        scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
        for(int i = 1; i <= n; ++i) scanf("%d%d%d%d", x + i, y + i, vx + i, vy + i);

        double l = -1e9, r = 1e9;
        for(int i = 1; i <= n; ++i) {
            double st, ed;
            tie(st, ed) = get(x[i], vx[i], x1, x2);
            l = max(l, st); r = min(r, ed);
            tie(st, ed) = get(y[i], vy[i], y1, y2);
            l = max(l, st); r = min(r, ed);
        }

        if(l < r) printf("%.20f\n", l);
        else puts("-1");
    }

    return 0;
}
