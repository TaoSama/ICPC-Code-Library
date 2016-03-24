//
//  Created by TaoSama on 2015-08-23
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

int n, t, a[55];
int dp[55][10005];

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int T; scanf("%d", &T);
    int kase = 0;
    while(T--) {
        scanf("%d%d", &n, &t);
        int sum = 0;
        for(int i = 1; i <= n; ++i) {
            scanf("%d", a + i);
            sum += a[i];
        }
        memset(dp, 0xc0, sizeof dp);
        dp[0][0] = 0;
        for(int i = 1; i <= n; ++i) {
            for(int j = 0; j <= t - 1; ++j) {
                if(j >= a[i]) dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - a[i]] + 1);
                else dp[i][j] = dp[i - 1][j];
            }
        }
        int ans = *max_element(dp[n], dp[n] + t);
        for(int j = sum; j >= 0; --j) {
            if(dp[n][j] == ans) {
                printf("Case %d: %d %d\n", ++kase, ans + 1, j + 678);
                break;
            }
        }
    }
    return 0;
}
