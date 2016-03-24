//
//  Created by TaoSama on 2015-11-04
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

char s[20];
LL n, dp[20][20];

int get(char c) {
    if(isdigit(c)) return c - '0';
    else return c - 'A' + 10;
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%s", s + 1) == 1) {
        n = strlen(s + 1);
        memset(dp, 0, sizeof dp);
        if(s[1] == '?') for(int i = 1; i <= n; ++i) dp[1][i] = 1;
        else dp[1][get(s[1])] = 1;
        for(int i = 2; i <= n; ++i) {
            if(s[i] == '?') {
                for(int j = 1; j <= n; ++j) {
                    for(int k = 1; k <= n; ++k)
                        if(k != j && k != j - 1 && k != j + 1)
                            dp[i][j] += dp[i - 1][k];
                }
            } else {
                int j = get(s[i]);
                for(int k = 1; k <= n; ++k)
                    if(k != j && k != j - 1 && k != j + 1)
                        dp[i][j] += dp[i - 1][k];
            }
        }
        LL ans = 0;
        for(int i = 1; i <= n; ++i) ans += dp[n][i];
        printf("%lld\n", ans);
    }
    return 0;
}
