//
//
//
//  Created by TaoSama on 2015-02-06
//  Copyright (c) 2014 TaoSama. All rights reserved.
//
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
#define CLR(x) memset(x, 0, sizeof(x))

using namespace std;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int N = 1e5 + 10;

int n, m, q, dp[305][305], a[305][305];
bool can[305];

int main() {
#ifdef LOCAL
    freopen("ACM_in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int kase = 0;
    while(~scanf("%d%d%d", &n, &m, &q) && (n + m + q)) {
        printf("Case %d:\n", ++kase);
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n; ++j)
                dp[i][j] = i == j ? 0 : INF;
        }

        memset(a, 0, sizeof a);
        memset(can, false, sizeof can);
        for(int i = 1; i <= m; ++i) {
            int x, y, v; scanf("%d%d%d", &x, &y, &v);
            dp[x][y] = min(dp[x][y], v);
        }
        while(q--) {
            int op; scanf("%d", &op);
            if(op == 0) {
                int x; scanf("%d", &x);
                if(can[x])
                    printf("City %d is already recaptured.\n", x);
                else {
                    can[x] = true;
                    for(int i = 0; i < n; ++i)
                        for(int j = 0; j < n; ++j)
                            dp[i][j] = min(dp[i][j],
                                           dp[i][x] + dp[x][j]);
                }
            } else {
                int x, y; scanf("%d%d", &x, &y);
                if(can[x] && can[y]) {
                    if(dp[x][y] != INF) printf("%d\n", dp[x][y]);
                    else printf("No such path.\n");
                } else
                    printf("City %d or %d is not available.\n", x, y);
            }
        }
        puts("");
    }
    return 0;
}
