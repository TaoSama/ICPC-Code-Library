//
//  Created by TaoSama on 2015-08-08
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

int n, m, dp[105][105];
char s[105], t[105];

string ans;

void print(int i, int j) {
    if(i == 0 && j == 0) return;
    if(i == 0) {
        for(int k = 1; k <= j; ++k) putchar(t[k]);
        return;
    }
    if(j == 0) {
        for(int k = 1; k <= i; ++k) putchar(s[k]);
        return;
    }
    if(s[i] == t[j]) {
        print(i - 1, j - 1);
        putchar(s[i]);
    } else if(dp[i][j - 1] >= dp[i - 1][j]) {
        print(i, j - 1);
        putchar(t[j]);
    } else {
        print(i - 1, j);
        putchar(s[i]);
    }
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%s%s", s + 1, t + 1) == 2) {
        n = strlen(s + 1);
        m = strlen(t + 1);

        memset(dp, 0, sizeof dp);
        for(int i = 1; i <= n; ++i) {
            for(int j = 1; j <= m; ++j) {
                if(s[i] == t[j]) dp[i][j] = dp[i - 1][j - 1] + 1;
                else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        ans = "";
        print(n, m);
//        for(auto &c : ans) if(isalpha(c)) putchar(c);
        puts("");
    }
    return 0;
}
