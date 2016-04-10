//
//  Created by TaoSama on 2015-11-20
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

int n;
bool dp[55][4][6];
char s[55];

bool isVowel(char c) {
    return c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
}

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
        memset(dp, false, sizeof dp);
        dp[0][0][0] = true;
        for(int i = 1; i <= n; ++i) {
            for(int j = 0; j < 3; ++j) {
                if(s[i] == '?' || isVowel(s[i]))
                    dp[i][j + 1][0] |= dp[i - 1][j][0];
                if(s[i] == '?' || !isVowel(s[i]))
                    dp[i][0][1] |= dp[i - 1][j][0];
            }
            for(int j = 0; j < 5; ++j) {
                if(s[i] == '?' || !isVowel(s[i]))
                    dp[i][0][j + 1] |= dp[i - 1][0][j];
                if(s[i] == '?' || isVowel(s[i]))
                    dp[i][1][0] |= dp[i - 1][0][j];
            }
        }
        bool good = false, bad = false;
        for(int i = 1; i < 3; ++i) if(dp[n][i][0]) good = true;
        for(int i = 1; i < 5; ++i) if(dp[n][0][i]) good = true;
        for(int i = 1; i <= n; ++i) {
            if(dp[i][3][0]) bad = true;
            if(dp[i][0][5]) bad = true;
        }
        printf("Case %d: ", ++kase);
        if(good && bad) puts("MIXED");
        else if(good) puts("GOOD");
        else puts("BAD");
    }
    return 0;
}
