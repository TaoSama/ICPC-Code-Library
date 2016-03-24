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

int n, dp[1005];
char s[1005];
bool isPalindrome[1005][1005];

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int t; cin >> t;
    while(t--) {
        cin >> (s + 1);
        n = strlen(s + 1);

        memset(isPalindrome, false, sizeof isPalindrome);
        for(int i = 1; i <= n; ++i) isPalindrome[i][i] = true;
        for(int i = n; i >= 1; --i) {
            for(int j = i + 1; j <= n; ++j) {
                if(s[i] == s[j] && (i + 1 > j - 1 || isPalindrome[i + 1][j - 1]))
                    isPalindrome[i][j] = true;
            }
        }
//      for(int i = 1; i <= n; ++i){
//          for(int j = 1; j < i; ++j)
//          cout << "  ";
//          for(int j = i; j <= n; ++j)
//              cout << isPalindrome[i][j] << ' ';
//          cout << endl;
//      }

        memset(dp, 0x3f, sizeof dp);
        dp[0] = 0;
        for(int i = 1; i <= n; ++i) {
            for(int j = 0; j < i; ++j) {
                if(isPalindrome[j + 1][i])
                    dp[i] = min(dp[i], dp[j] + 1);
            }
        }
        cout << dp[n] << '\n';
    }
    return 0;
}

/*
for(int d = 1; d < n; d++)
    for(int l = 1; l + d <= n; l++)
        int r = l + d;
*/
