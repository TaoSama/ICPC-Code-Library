//
//  Created by TaoSama on 2015-08-02
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
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, a, d;

double calc(int v) {
    double t = 1.0 * v / a, s = t * t * a / 2;
    return d > s ? t + (d - s) / v : sqrt(2.0 * d / a);
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d%d%d", &n, &a, &d) == 3) {
        double ans = 0, maxT = 0;
        for(int i = 1; i <= n; ++i) {
            int t, v; scanf("%d%d", &t, &v);
            ans = t + calc(v);
            if(ans < maxT) ans = maxT;
            else maxT = ans;
            printf("%.10f\n", ans);
        }
    }
    return 0;
}
