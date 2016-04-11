//
//  Created by TaoSama on 2015-06-10
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
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int N = 1e5 + 10;

int a, n, dp[40005];
string s;

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(cin >> a >> s) {
        n = s.size();
        for(int i = 0; i < n; ++i) {
            int sum  = 0;
            for(int j = i; j < n; ++j) {
                sum += s[j] - '0';
                dp[sum]++;
            }
        }
        long long ans = 0;
        for(int i = 0; i < n; ++i) {
            int sum = 0;
            for(int j = i; j < n; ++j) {
                sum += s[j] - '0';
                if(sum && a % sum == 0 && a / sum <= 36000)
                    ans += dp[a / sum];
                else if(!sum && !a) ans += n * (n + 1) >> 1;
            }
        }
        cout << ans << endl;
        memset(dp, 0, sizeof dp);
    }
    return 0;
}
