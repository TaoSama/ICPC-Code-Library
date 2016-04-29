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

typedef long long LL;

int n, m, dp[35][35];
char s[35], t[35];
LL cnt[35][35];

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int T; scanf("%d", &T);
    int kase = 0;
    while(T--) {
        scanf("%s%s", s + 1, t + 1);
        n = strlen(s + 1), m = strlen(t + 1);
        memset(dp, 0, sizeof dp);
        memset(cnt, 0, sizeof cnt);
        for(int i = 0; i <= n; ++i) cnt[i][0] = 1;
        for(int i = 0; i <= m; ++i) cnt[0][i] = 1;
        for(int i = 1; i <= n; ++i)
            for(int j = 1; j <= m; ++j)
                if(s[i] == t[j]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                    cnt[i][j] = cnt[i - 1][j - 1];
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                    if(dp[i][j] == dp[i - 1][j]) cnt[i][j] += cnt[i - 1][j];
                    if(dp[i][j] == dp[i][j - 1]) cnt[i][j] += cnt[i][j - 1];
                }


        printf("Case %d: %d %lld\n", ++kase, n + m - dp[n][m], cnt[n][m]);
    }
    return 0;
}