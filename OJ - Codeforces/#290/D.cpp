//
//  Created by TaoSama on 2015-05-18
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

int n, l[305], c[305];
map<int, int> dp; //dp[i][j] 公约数first 的最小花费second

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(cin >> n) {
        for(int i = 1; i <= n; ++i) cin >> l[i];
        for(int i = 1; i <= n; ++i) cin >> c[i];

        dp.clear(); dp[0] = 0;
        for(int i = 1; i <= n; ++i) {
            for(auto it = dp.begin(); it != dp.end(); ++it) {
                int t = __gcd(l[i], it->first);
                if(dp.count(t)) dp[t] = min(dp[t], it->second + c[i]);
                else dp[t] = it->second + c[i];
            }
        }
        if(dp.count(1)) cout << dp[1] << '\n';
        else cout << "-1\n";
    }
    return 0;
}
