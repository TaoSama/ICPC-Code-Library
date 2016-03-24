//
//  Created by TaoSama on 2015-08-14
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

int n, l, r;
long long dp[25][25][25];
//dp[i][j][k]:= 1~i see j from left, k from right

void gao() {
    dp[1][1][1] = 1;
    for(int i = 2; i <= 20; ++i) {
        for(int j = 1; j <= i; ++j) {
            for(int k = 1; k <= i; ++k) {
                //2~i settle down, insert 1 to (i - 2) position
                dp[i][j][k] = dp[i - 1][j][k] * (i - 2);
                if(j > 1) dp[i][j][k] += dp[i - 1][j - 1][k]; //insert leftmost
                if(k > 1) dp[i][j][k] += dp[i - 1][j][k - 1]; //insert rightmost
            }
        }
    }
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int t; cin >> t;
    gao();
    while(t--) {
        cin >> n >> l >> r;
        cout << dp[n][l][r] << '\n';
    }
    return 0;
}
