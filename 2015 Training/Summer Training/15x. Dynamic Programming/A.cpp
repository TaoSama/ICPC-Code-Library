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

int n, T, m, a[55];
int dp[205][55];
bool hasTrain[205][55][2]; // 0->rig 1->lef

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int kase = 0;
    while(cin >> n >> T) {
        memset(hasTrain, false, sizeof hasTrain);
        for(int i = 1; i < n; ++i) cin >> a[i];
        cin >> m;
        for(int i = 1; i <= m; ++i) {
            int x; cin >> x;
            for(int j = 1; j <= n; ++j) {
//              cout << x << endl;
                if(x > T) break;
                hasTrain[x][j][0] = true;
                x += a[j];
            }
        }
        cin >> m;
        a[n] = 0;
        for(int i = 1; i <= m; ++i) {
            int x; cin >> x;
            for(int j = n; j; --j) {
//              cout << x << endl;
                if(x > T) break;
                hasTrain[x][j][1] = true;
                x += a[j - 1];
            }
        }

        memset(dp, 0x3f, sizeof dp);
        dp[T][n] = 0;
        for(int i = T - 1; i >= 0; --i) {
            for(int j = 1; j <= n; ++j) {
                dp[i][j] = dp[i + 1][j] + 1; //wait for 1 time
                if(j < n && hasTrain[i][j][0] && i + a[j] <= T)
                    dp[i][j] = min(dp[i][j], dp[i + a[j]][j + 1]);
                if(j > 1 && hasTrain[i][j][1] && i + a[j - 1] <= T)
                    dp[i][j] = min(dp[i][j], dp[i + a[j - 1]][j - 1]);
            }
        }

        cout << "Case Number " << ++kase << ": ";
        if(dp[0][1] >= INF) cout << "impossible\n";
        else cout << dp[0][1] << '\n';
    }
    return 0;
}
