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

int n, dp[105][105];
char s[105];

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int t; scanf("%d", &t);
    int kase = 0;
    while(t--) {
        scanf("%s", s + 1);
        n = strlen(s + 1);
        memset(dp, 0, sizeof dp);
        for(int l = 1; l <= n; ++l) {
            for(int i = 1; i + l - 1 <= n; ++i) {
                int j = i + l - 1;
                if(s[i] == s[j]) dp[i][j] = dp[i + 1][j - 1];
                else dp[i][j] = min(dp[i + 1][j], dp[i][j - 1]) + 1;
            }
        }
        printf("Case %d: %d\n", ++kase, dp[1][n]);
    }
    return 0;
}
