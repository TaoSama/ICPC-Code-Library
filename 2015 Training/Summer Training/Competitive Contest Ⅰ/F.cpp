//
//  Created by TaoSama on 2015-08-25
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
int dp[15][15], len[1505];
char s[1505][15];

int gao(char *s, char *t, int sl, int tl) {
    for(int i = 1; i <= sl; ++i) dp[i][0] = i;
    for(int i = 1; i <= tl; ++i) dp[0][i] = i;

    for(int i = 1; i <= sl; ++i)
        for(int j = 1; j <= tl; ++j)
            if(s[i] == t[j]) dp[i][j] = dp[i - 1][j - 1];
            else dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + 1;
    return dp[sl][tl];
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int T; scanf("%d", &T);
    int kase = 0;
    while(T--) {
        scanf("%d%d", &n, &m);
        for(int i = 1; i <= n; ++i) {
            scanf("%s", s[i] + 1);
            len[i] = strlen(s[i] + 1);
        }
        printf("Case #%d:\n", ++kase);
        while(m--) {
            char buf[15]; int limit;
            scanf("%s%d", buf + 1, &limit);
            int tl = strlen(buf + 1), ans = 0;
            for(int i = 1; i <= n; ++i) {
                int sl = len[i];
                if(abs(sl - tl) > limit) continue;
                if(gao(s[i], buf, sl, tl) <= limit) ++ans;
            }
            printf("%d\n", ans);
        }
    }
    return 0;
}
