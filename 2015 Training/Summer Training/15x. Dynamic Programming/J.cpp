//
//  Created by TaoSama on 2015-08-06
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

bool match(char l, char r) {
    return l == '(' && r == ')' || l == '[' && r == ']';
}

void print(int i, int j) {
    if(i > j) return;
    if(i == j) {
        if(s[i] == '(' || s[i] == ')') printf("()");
        else printf("[]");
        return;
    }

    int ans = dp[i][j];
    if(match(s[i], s[j]) && ans == dp[i + 1][j - 1]) {
        putchar(s[i]); print(i + 1, j - 1); putchar(s[j]);
        return;
    }

    for(int k = i; k < j; ++k) {
        if(ans == dp[i][k] + dp[k + 1][j]) {
            print(i, k); print(k + 1, j);
            return;
        }
    }
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int t; scanf("%d ", &t);
    while(t--) {
        gets(s + 1); getchar();
        n = strlen(s + 1);

        memset(dp, 0x3f, sizeof dp);
        for(int i = 1; i <= n; ++i) {
            dp[i + 1][i] = 0;
            dp[i][i] = 1;
        }
        for(int i = n - 1; i >= 1; --i) {
            for(int j = i + 1; j <= n; ++j) {
                //(S') [S'] -> S'
                if(match(s[i], s[j]))
                    dp[i][j] = min(dp[i][j], dp[i + 1][j - 1]);
                //(S',[S', )S',]S' -> ] & S'
                for(int k = i; k < j; ++k)
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j]);
            }
        }
        print(1, n);
        puts("");
        if(t) puts("");
    }
    return 0;
}
