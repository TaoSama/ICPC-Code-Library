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

int n, T, a[55];
int dp[10000];

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int t; cin >> t;
    int kase = 0;
    while(t--) {
        cin >> n >> T;
        for(int i = 1; i <= n; ++i) cin >> a[i];
        memset(dp, 0xc0, sizeof dp);
        dp[0] = 0;
        for(int i = 1; i <= n; ++i) {
            for(int j = T - 1; j >= a[i]; --j) {
                dp[j] = max(dp[j], dp[j - a[i]] + 1);
            }
        }

        int ans = *max_element(dp, dp + T);
        cout << "Case " << ++ kase << ": ";
        for(int i = T - 1; i >= 0; --i) {
            if(dp[i] == ans) {
                cout << ans + 1 << ' ' << i + 678 << '\n';
                break;
            }
        }
    }
    return 0;
}
