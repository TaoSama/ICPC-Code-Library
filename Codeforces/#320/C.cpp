//
//  Created by TaoSama on 2015-09-16
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
const double EPS = 1e-10;

int x, y;

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d%d", &x, &y) == 2) {
        if(x < y) puts("-1");
        else if(x == y) printf("%.12f\n", 1.0 * x);
        else {
            double k1 = x - y, k2 = x + y;
            int c1 = k1 / 2 / y, c2 = k2 / 2 / y;
            double ans = min(k1 / 2 / c1, k2 / 2 / c2);
            printf("%.12f\n", ans);
        }
    }
    return 0;
}
