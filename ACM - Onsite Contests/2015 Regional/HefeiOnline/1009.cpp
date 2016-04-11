//
//  Created by TaoSama on 2015-09-27
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
int a[35][35], dp[35][35][2000];

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int t; scanf("%d", &t);
    int kase = 0;
    while(t--) {
        scanf("%d%d", &n, &m);
        for(int i = 1; i <= n; ++i)
            for(int j = 1; j <= m; ++j)
                scanf("%d", &a[i][j]);

        memset(dp, 0x3f, sizeof dp);
        dp[1][1][a[1][1]] = a[1][1] * a[1][1];
        int ans = INF;
        for(int i = 1; i <= n; ++i) {
            for(int j = 1; j <= m; ++j) {
                for(int k = a[1][1]; k <= 1800; ++k) {
                    int &cur = dp[i][j][k];
                    if(i + 1 <= n) {
                        int &val = a[i + 1][j], &nxt = dp[i + 1][j][k + val];
                        nxt = min(nxt, cur + val * val);
                    }
                    if(j + 1 <= m) {
                        int &val = a[i][j + 1], &nxt = dp[i][j + 1][k + val];
                        nxt = min(nxt, cur + val * val);
                    }
                    if(i == n && j == m && cur != INF)
                        ans = min(ans, (n + m - 1) * cur - k * k);
                }
            }
        }

        printf("Case #%d: %d\n", ++kase, ans);
    }
    return 0;
}
