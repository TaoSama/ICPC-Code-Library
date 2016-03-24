//
//
//
//  Created by TaoSama on 2015-03-22
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
#define CLR(x,y) memset(x, y, sizeof(x))

using namespace std;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int N = 1e5 + 10;

int n, a[5005], b[5005];
long long dp[2][5005];
//dp[i][j]: 将第i个数变成不小于排序后第j位置数的最小step

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//	freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(cin >> n) {
        memset(dp, 0, sizeof dp);
        for(int i = 1; i <= n; ++i) cin >> a[i], b[i] = a[i];

        sort(b + 1, b + 1 + n);
        memset(dp, 0x3f, sizeof dp);
        dp[1][1] = abs(a[1] - b[1]);
        for(int i = 2; i <= n; ++i)
            dp[1][i] = min(dp[1][i - 1], (long long)abs(a[1] - b[i]));
        for(int i = 2; i <= n; ++i) {
            memset(dp[i & 1], 0x3f, sizeof dp[i & 1]);
            for(int j = 1; j <= n; ++j)
                dp[i & 1][j] = min(dp[i & 1][j - 1], dp[(i - 1) & 1][j] +
                                   abs(a[i] - b[j]));
        }
        cout << *min_element(dp[n & 1] + 1, dp[n & 1] + 1 + n) << endl;
    }
    return 0;
}
