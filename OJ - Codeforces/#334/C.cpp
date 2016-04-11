//
//  Created by TaoSama on 2015-12-01
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

int n, dp[N][2][2], b[N][2][2], wh[N][2][2];
char s[N];

void getMax(int &x, int y) {
    x = max(x, y);
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d", &n) == 1) {
        scanf("%s", s + 1);
        memset(dp, 0, sizeof dp);
        memset(b, 0, sizeof b);
        memset(wh, 0, sizeof wh);
        for(int i = 1; i <= n; ++i) {
            int p = s[i] - '0';
            //得到之前的状态
            b[i][p ^ 1][0] = b[i - 1][p ^ 1][0];
            b[i][p][0] = b[i - 1][p][0];
            b[i][p][1] = b[i - 1][p][1];
            b[i][p ^ 1][1] = b[i - 1][p ^ 1][1];
            wh[i][p ^ 1][0] = wh[i - 1][p ^ 1][0];
            wh[i][p][0] = wh[i - 1][p][0];
            wh[i][p][1] = wh[i - 1][p][1];
            wh[i][p ^ 1][1] = wh[i - 1][p ^ 1][1];

            getMax(dp[i][p][0], b[i][p ^ 1][0] + 1);
            getMax(dp[i][p][1], b[i][p ^ 1][1] + 1);

            if(wh[i][p][1] == i - 1)
                getMax(dp[i][p ^ 1][1], b[i][p][1] + 1);
            getMax(dp[i][p ^ 1][1], b[i][p][0] + 1);

            //更新前缀max
            if(dp[i][p][0] > b[i][p][0]) {
                b[i][p][0] = dp[i][p][0];
            }
            if(dp[i][p][1] > b[i][p][1]) {
                b[i][p][1] = dp[i][p][1];
            }
            if(dp[i][p ^ 1][1] > b[i][p ^ 1][1]) {
                b[i][p ^ 1][1] = dp[i][p ^ 1][1];
                wh[i][p ^ 1][1] = i;
            }

//          printf("dp[%d][%d][%d] = %d\n", i, 0, 0, dp[i][0][0]);
//          printf("dp[%d][%d][%d] = %d\n", i, 0, 1, dp[i][0][1]);
//          printf("dp[%d][%d][%d] = %d\n", i, 1, 0, dp[i][1][0]);
//          printf("dp[%d][%d][%d] = %d\n", i, 1, 1, dp[i][1][1]);
        }

        int ans = 0;
        for(int i = 1; i <= n; ++i) {
            getMax(ans, max(dp[i][0][0], dp[i][0][1]));
            getMax(ans, max(dp[i][1][0], dp[i][1][1]));
        }
        printf("%d\n", ans);
    }
    return 0;
}
