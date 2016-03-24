//
//  Created by TaoSama on 2015-08-24
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

int n, m;
int w[1005], a[1005], b[1005];
int dp[2005];

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int t; scanf("%d", &t);
    while(t--) {
        scanf("%d%d", &m, &n);
        for(int i = 1; i <= n; ++i) scanf("%d%d%d", w + i, a + i, b + i);
        memset(dp, 0, sizeof dp);
        for(int i = 1; i <= n; ++i) {
            for(int j = m; j >= w[i]; --j)
                dp[j] = max(dp[j], dp[j - w[i]] + a[i] + b[i]);
            for(int j = w[i]; j <= m; ++j)
                dp[j] = max(dp[j], dp[j - w[i]] + a[i]);
        }
        printf("%d\n", dp[m]);
    }
    return 0;
}
