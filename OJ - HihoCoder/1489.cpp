//
//  Created by TaoSama on 2017-03-31
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
#define pr(x) cerr << #x << " = " << x << "  "
#define prln(x) cerr << #x << " = " << x << endl
const int N = 1e6 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, p, q;
double f[105][2];

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    scanf("%d%d%d", &p, &q, &n);
    double ans = 0;
    for(int i = 1; i <= n; ++i) {
        f[0][0] = f[0][1] = 1;
        int np = p, ok = 0;
        for(int j = 1; j <= 100; ++j) {
            if(np >= 100) {np = 100; ok = 1;}
            f[j][1] = f[j - 1][0] * np / 100;
            f[j][0] = f[j - 1][0] * (100 - np) / 100;
            np += q;
            ans += j * f[j][1];
            if(ok) break;
        }
        p >>= 1;
    }
    printf("%.2f\n", ans);
    return 0;
}
