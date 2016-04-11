//
//	POJ 3421 X-factor Chains
//
//  Created by TaoSama on 2015-03-31
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

int n, len[1500], dp[1500];

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//	freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(cin >> n) {
        vector<int> factor;
        for(int i = 1; i * i <= n; ++i) {
            if(n % i == 0) {
                factor.push_back(i);
                if(i != n / i)  factor.push_back(n / i);
            }
        }
        sort(factor.begin(), factor.end());
        int sz = factor.size();
        for(int i = 0; i < sz; ++i) {
            len[i] = dp[i] = 1;
            for(int j = 0; j < i; ++j) {
                if(factor[i] % factor[j] == 0) {
                    if(len[i] < len[j] + 1) {
                        len[i] = len[j] + 1;
                        dp[i] = dp[j];
                    } else if(len[i] == len[j] + 1)
                        dp[i] += dp[j];
                }
            }
        }
        cout << len[sz - 1] - 1 << ' ' << dp[sz - 1] << endl;
    }
    return 0;
}
