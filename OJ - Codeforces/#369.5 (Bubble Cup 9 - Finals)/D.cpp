//
//  Created by TaoSama on 2016-09-11
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

int n, x;
double p[200];

void fwtXor(double* a, int len) {
    if(len == 1) return;
    int h = len >> 1;
    fwtXor(a, h);
    fwtXor(a + h, h);
    for(int i = 0; i < h; ++i) {
        double x1 = a[i];
        double x2 = a[i + h];
        a[i] = (x1 + x2);
        a[i + h] = (x1 - x2);
    }
}

void ifwtXor(double* a, int len) {
    if(len == 1) return;
    int h = len >> 1;
    for(int i = 0; i < h; ++i) {
        // y1=x1+x2
        // y2=x1-x2
        double y1 = a[i];
        double y2 = a[i + h];
        a[i] = (y1 + y2) / 2;
        a[i + h] = (y1 - y2) / 2;
    }
    ifwtXor(a, h);
    ifwtXor(a + h, h);
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
//    ios_base::sync_with_stdio(0);

    cin >> n >> x;
    for(int i = 0; i <= x; ++i) cin >> p[i];

    fwtXor(p, 1 << 7);
    for(int i = 0; i < 1 << 7; ++i) p[i] = pow(p[i], n);
    ifwtXor(p, 1 << 7);

    double ans = 1 - p[0];
    printf("%.12f\n", ans);

    return 0;
}
