//
//  Created by TaoSama on 2016-09-05
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
const int N = 10 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;
const int M = N * N;
const double EPS = 1e-8;

int n, m, T;
int u[M], v[M], c[M], d[M];
double dis[N][N];

double f(double t) {
#define rep(i, a, b) for(int i = a; i <= b; ++i)

    rep(i, 1, n) rep(j, 1, n) dis[i][j] = i == j ? 0 : 1e18;
    rep(i, 1, m) dis[u[i]][v[i]] = c[i] * t + d[i];
    rep(k, 1, n) rep(i, 1, n) rep(j, 1, n)
    dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);

    return dis[1][n];
}

double asr(double l, double r, double fL, double fR) {
    double m = (l + r) / 2;
    double fM = f(m);
    if(abs(fL + fR - 2 * fM) < EPS) return fM * (r - l);
    return asr(l, m, fL, fM) + asr(m, r, fM, fR);
}

double calc(double l, double r) {
    return asr(l, r, f(l), f(r));
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d%d%d", &n, &m, &T) == 3) {
        for(int i = 1; i <= m; ++i) scanf("%d%d%d%d", u + i, v + i, c + i, d + i);
        double ans = calc(0, T) / T;
        printf("%.8f\n", ans);
    }

    return 0;
}
