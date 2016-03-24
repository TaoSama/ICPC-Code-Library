//
//  Created by TaoSama on 2015-08-31
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

int n, dp[505], mp[505][505];

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d", &n) == 1) {
        memset(mp, 0, sizeof mp);
        memset(dp, 0, sizeof dp);
        for(int i = 1; i <= n; ++i) {
            int a, b; scanf("%d%d", &a, &b);
            if(a + b >= n) continue;
            mp[a + 1][n - b] = min(mp[a + 1][n - b] + 1, n - a - b);
        }
        for(int i = 1; i <= n; ++i)
            for(int j = 1; j <= i; ++j)
                dp[i] = max(dp[i], dp[j - 1] + mp[j][i]);
        printf("%d\n", dp[n]);
    }
    return 0;
}
