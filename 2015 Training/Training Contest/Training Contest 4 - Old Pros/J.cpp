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

using namespace std;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int N = 1e5 + 10;

int n, dp[15][16][16];
int dx[] = {-1, 0, 1, 0, -1, 1};
int dy[] = {0, -1, 0, 1, 1, -1};
int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//	freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    memset(dp, 0, sizeof dp);
    dp[0][8][8] = 1;
    for(int k = 1; k < 15; ++k)
        for(int i = 1; i <= 15; ++i)
            for(int j = 1; j <= 15; ++j)
                for(int x = 0; x < 6; ++x)
                    dp[k][i][j] += dp[k - 1][i + dx[x]][j + dy[x]];

	int t; cin >> t;
    while(t--) {
        cin >> n;
        cout << dp[n][8][8] << endl;
    }
    return 0;
}
/*
0
6
12
90
360
2040
10080
54810
290640
1588356
8676360
47977776
266378112
1488801600
*/
