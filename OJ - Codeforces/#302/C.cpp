//
//  Created by TaoSama on 2015-05-08
//  Copyright (c) 2015 TaoSama. All rights reserved.
//
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
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int N = 1e5 + 10;

int dp[505][505], a[505];
int n, m, b, M;

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(cin >> n >> m >> b >> M) {
        for(int i = 1; i <= n; ++i) cin >> a[i];

        memset(dp, 0, sizeof dp);
        dp[0][0] = 1;
        for(int i = 1; i <= n; ++i) {
            for(int j = 1; j <= m; ++j) {
                for(int k = a[i]; k <= b; ++k) {
                    dp[j][k] = (dp[j][k] + dp[j - 1][k - a[i]]) % M;
                }
            }
        }
        int sum = 0;
        for(int i = 0; i <= b; ++i)
			sum = (sum + dp[m][i]) % M;
		cout<<sum << '\n';
    }
    return 0;
}
