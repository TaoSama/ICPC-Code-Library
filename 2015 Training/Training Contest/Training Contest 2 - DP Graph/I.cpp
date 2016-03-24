//
//
//
//  Created by TaoSama on 2015-03-15
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
const int N = 2e5 + 10;

int r, g, dp[N];

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//	freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(cin >> r >> g) {
        int s = r + g, h = 1;
        while(h * (h + 1) / 2 <= s) h++;
        h--;
        memset(dp, 0, sizeof dp);
        dp[0] = 1;
        for(int i = 1; i <= h; ++i) {
            for(int j = r; j >= i; --j) {
                dp[j] = (dp[j] + dp[j - i]) % MOD;
            }
        }
        s = h * (h + 1) >> 1;
        int ans = 0;
        for(int i = r; i >= 0; --i) {
            if(s - i <= g) ans = (ans + dp[i]) % MOD;
        }
        cout << ans << endl;
    }
    return 0;
}
