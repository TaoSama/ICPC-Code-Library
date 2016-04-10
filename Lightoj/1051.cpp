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

int n, dp[55][4][6]; //0Illegal 1GOOD 2BAD 3MIXED
char s[55];

bool isVowel(char c) {
    return c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
}

void get(int&x, int y) {
    if(x && x != y) x = 3;
    else x = y;
}

//1GOOD 2BAD 3MIXED
int gao() {
    bool good = false, bad = false;
    for(int i = 1; i <= 3; ++i) {
        if(!dp[n][i][0]) continue;
        if(dp[n][i][0] == 1) good = true;
        else if(dp[n][i][0] == 2) bad = true;
        else return 3;
    }
    for(int i = 1; i <= 5; ++i) {
        if(!dp[n][0][i]) continue;
        if(dp[n][0][i] == 1) good = true;
        else if(dp[n][0][i] == 2) bad = true;
        else return 3;
    }
    if(good && bad) return 3;
    else if(good) return 1;
    else return 2;
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
        memset(dp, 0, sizeof dp);
        if(s[1] == '?' || isVowel(s[1])) dp[1][1][0] = 1;
        if(s[1] == '?' || !isVowel(s[1])) dp[1][0][1] = 1;
        for(int i = 1; i < n; ++i) {
            for(int j = 1; j <= 3; ++j) {
                if(!dp[i][j][0]) continue;
                if(s[i + 1] == '?' || isVowel(s[i + 1])) {
                    if(j >= 2) dp[i + 1][3][0] = 2;
                    else get(dp[i + 1][j + 1][0], dp[i][j][0]);
                }
                if(s[i + 1] == '?' || !isVowel(s[i + 1]))
                    get(dp[i + 1][0][1], dp[i][j][0]);
            }
            for(int j = 1; j <= 5; ++j) {
                if(!dp[i][0][j]) continue;
                if(s[i + 1] == '?' || !isVowel(s[i + 1])) {
                    if(j >= 4) dp[i + 1][0][5] = 2;
                    else get(dp[i + 1][0][j + 1], dp[i][0][j]);
                }
                if(s[i + 1] == '?' || isVowel(s[i + 1]))
                    get(dp[i + 1][1][0], dp[i][0][j]);
            }
        }
        int ans = gao();
        string x = ans == 1 ? "GOOD" : ans == 2 ? "BAD" : "MIXED";
        printf("Case %d: %s\n", ++kase, x.c_str());
    }
    return 0;
}
