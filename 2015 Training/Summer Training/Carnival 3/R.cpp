//
//  Created by TaoSama on 2015-08-09
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

char s[N];
int n, dp[N][26];
bool mp[26][26];

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(cin >> (s + 1)) {
        int k; cin >> k;
        memset(mp, false, sizeof mp);
        for(int i = 1; i <= k; ++i) {
            char buf[5]; cin >> buf;
            int u = buf[0] - 'a', v = buf[1] - 'a';
            mp[u][v] = mp[v][u] = true;
        }

        memset(dp, 0x3f, sizeof dp);
        for(int i = 0; i < 26; ++i) {
            if(s[1] - 'a' == i) dp[1][i] = 0;
            else dp[1][i] = 1;
        }
        n = strlen(s + 1);
        for(int i = 2; i <= n; ++i) {
            for(int j = 0; j < 26; ++j) {
                dp[i][j] = min(dp[i][j], dp[i - 1][j] + 1); //delete s[i]
                int k = s[i] - 'a';
                //not conflict, recover s[i]
                if(!mp[k][j]) dp[i][k] = min(dp[i][k], dp[i - 1][j]);
            }
        }
        int ans = *min_element(dp[n], dp[n] + 26);
        cout << ans << '\n';
    }
    return 0;
}
