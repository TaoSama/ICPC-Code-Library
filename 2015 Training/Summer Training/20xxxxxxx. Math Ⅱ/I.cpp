//
//  Created by TaoSama on 2015-08-15
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

int dp[10][10];

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int t; scanf("%d", &t);
    while(t--) {
        for(int i = 1; i < 10; i += 2)
            for(int j = 1; j <= i; j += 2)
                scanf("%d", &dp[i][j]);

        //calculate odd row's even column
        for(int i = 3; i < 10; i += 2)
            for(int j = 2; j <= i; j += 2)
                dp[i][j] = dp[i - 2][j - 1] - dp[i][j - 1] - dp[i][j + 1] >> 1;

        //calculate even row
        for(int i = 2; i < 10; i += 2)
            for(int j = 1; j <= i; j ++)
                dp[i][j] = dp[i + 1][j] + dp[i + 1][j + 1];

        //print
        for(int i = 1; i < 10; ++i) {
            for(int j = 1; j <= i; ++j) {
                if(j == 1) printf("%d", dp[i][j]);
                else printf(" %d", dp[i][j]);
                if(j == i) puts("");
            }
        }
    }
    return 0;
}
