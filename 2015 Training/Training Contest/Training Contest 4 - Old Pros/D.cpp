//
//
//
//  Created by TaoSama on 2015-03-29
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

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//	freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(cin >> n) {
        for(int i = 1; i <= n; ++i) cin >> a[i], b[i] = a[i];
        sort(b + 1, b + 1 + n);

        int p = 0;
        for(int i = 1; i <= n; ++i) dp[p][i] = abs(a[1] - b[i]);

        for(int i = 2; i <= n; ++i) {
            long long preMin = dp[p][1];
            for(int j = 1; j <= n; ++j) {
                preMin = min(preMin, dp[p][j]);
                dp[1 - p][j] = preMin + abs(a[i] - b[j]);
            }
            p = 1 - p;
        }
        cout << *min_element(dp[p] + 1, dp[p] + 1 + n) << endl;
    }
    return 0;
}
