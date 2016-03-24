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
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

char s[1005];
int n, dp[1005][1005];

void print(int l, int r) {
    if(l > r) return;
    if(l == r) {putchar(s[l]); return;}
    //fuck! forgot a condition that judge equal character first
    if(s[l] == s[r] && dp[l][r] == dp[l + 1][r - 1]) {
        putchar(s[l]);
        print(l + 1, r - 1);
        putchar(s[l]);
    } else if(dp[l][r] == dp[l + 1][r] + 1) {
        putchar(s[l]);
        print(l + 1, r);
        putchar(s[l]);
    } else {
        putchar(s[r]);
        print(l, r - 1);
        putchar(s[r]);
    }
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%s", s + 1) == 1) {
        n = strlen(s + 1);

        memset(dp, 0, sizeof dp);
        for(int i = n; i >= 1; --i) {
            for(int j = i + 1; j <= n; ++j) {
                if(s[i] == s[j]) dp[i][j] = dp[i + 1][j - 1];
                else dp[i][j] = min(dp[i + 1][j], dp[i][j - 1]) + 1;
            }
        }
        printf("%d ", dp[1][n]);
        print(1, n); puts("");
    }
    return 0;
}
