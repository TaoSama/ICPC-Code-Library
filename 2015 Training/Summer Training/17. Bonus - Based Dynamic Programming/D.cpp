//
//  Created by TaoSama on 2015-08-08
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
const int N = 1e4 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, m, v[N];
double p[N], dp[N];

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d%d", &n, &m) == 2 && (n || m)) {
        for(int i = 1; i <= m; ++i) scanf("%d%lf", v + i, p + i);
        for(int i = 0; i <= n; ++i) dp[i] = 1.0;

        for(int i = 1; i <= m; ++i) {
            for(int j = n; j >= v[i]; --j) {
                dp[j] = min(dp[j], dp[j - v[i]] * (1 - p[i]));
            }
        }
        printf("%.1f%%\n", (1 - dp[n]) * 100);
    }
    return 0;
}
