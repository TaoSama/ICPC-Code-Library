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

int n, m, a[15][105], nxt[15][105];
long long dp[15][105];

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(cin >> n >> m) {
        memset(dp, 0x3f, sizeof dp);
        for(int i = 1; i <= n; ++i) {
            for(int j = 1; j <= m; ++j) {
                cin >> a[i][j];
                if(j == m) dp[i][j] = a[i][j];
            }
        }

        for(int j = m - 1; j; --j) {
            for(int i = 1; i <= n; ++i) {
                int row[3] = {i, i + 1, i - 1};
                if(i == 1) row[2] = n; //handle the bound
                if(i == n) row[1] = 1;
                sort(row, row + 3);

                for(int k = 0; k < 3; ++k) {
                    int v = dp[row[k]][j + 1] + a[i][j]; //former column
                    if(v < dp[i][j]) {
                        dp[i][j] = v;
                        nxt[i][j] = row[k];
                    }
                }
            }
        }

        int ans = INF, first;
        for(int i = 1; i <= n; ++i) {
            if(ans > dp[i][1]) {
                ans = dp[i][1];
                first = i;
            }
        }
        cout << first;
        for(int i = nxt[first][1], j = 2; j <= m; i = nxt[i][j], j++)
            cout << ' ' << i;
        cout << '\n' << ans << '\n';
    }
    return 0;
}
