//
//  Created by TaoSama on 2015-08-14
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

int n;
double t, dp[35];

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d%lf", &n, &t) == 2 && n) {
        dp[n] = 1 << n;
        for(int i = n - 1; i >= 0; --i) {
            double p0 = max(t, 1.0 * (1 << i) / dp[i + 1]);
            double p1 = (p0 - t) / (1 - t); //no answer p0 > p
            dp[i] = 1.0 * (1 << i) * p1 + (1 + p0) / 2 * (1 - p1) * dp[i + 1];
        }
        printf("%.3f\n", dp[0]);
    }
    return 0;
}
