//
//  Created by TaoSama on 2015-11-13
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

int n, a[25][3], dp[25][3];

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int t; scanf("%d", &t);
    int kase = 0;
    while(t--) {
        scanf("%d", &n);
        for(int i = 1; i <= n; ++i)
            for(int j = 0; j < 3; ++j)
                scanf("%d", &a[i][j]);

        memset(dp, 0x3f, sizeof dp);
        int ans = INF;
        for(int i = 0; i < 3; ++i) dp[1][i] = a[1][i];
        for(int i = 2; i <= n; ++i) {
            for(int j = 0; j < 3; ++j) {
                for(int k = 0; k < 3; ++k) {
                    if(j == k) continue;
                    dp[i][j] = min(dp[i][j], dp[i - 1][k] + a[i][j]);
                }
                if(i == n) ans = min(ans, dp[i][j]);
            }
        }
        printf("Case %d: %d\n", ++kase, ans);
    }
    return 0;
}
