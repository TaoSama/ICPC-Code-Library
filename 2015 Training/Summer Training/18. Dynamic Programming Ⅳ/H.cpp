//
//  Created by TaoSama on 2015-08-13
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
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e8;

int n, m, mp[15];
int dp[15][1 << 12];

bool isLegal(int i, int s) {
//  pr(i); pr(mp[i]); prln(s);
    if((mp[i] | s) > mp[i]) return false; //check valid
    if(s & (s << 1)) return false; //check adjacent
    return true;
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
//    ios_base::sync_with_stdio(0);

    while(scanf("%d%d", &n, &m) == 2) {
        memset(mp, 0, sizeof mp);
        for(int i = 1; i <= n; ++i) {
            for(int j = 0; j < m; ++j) {
                int x; scanf("%d", &x);
                if(x) mp[i] |= 1 << j;
            }
        }

        memset(dp, 0, sizeof dp);
        dp[0][0] = 1;
        for(int i = 1; i <= n; ++i) {
            for(int j = 0; j < 1 << m; ++j) {
                if(isLegal(i, j)) {
                    //no conflict with current j
                    int last = ((1 << m) - 1) ^ j;
//                  printf("cur = %d last = %d\n", j, last);
                    dp[i][j] = (dp[i][j] + dp[i - 1][0]) % MOD; //empty
                    for(int k = last; k; k = (k - 1) & last)
                        if(isLegal(i - 1, k))
                            dp[i][j] = (dp[i][j] + dp[i - 1][k]) % MOD;
                }
            }
        }
        int ans = 0;
        for(int i = 0; i < 1 << m; ++i)
            ans = (ans + dp[n][i]) % MOD;
        printf("%d\n", ans);
    }
    return 0;
}
