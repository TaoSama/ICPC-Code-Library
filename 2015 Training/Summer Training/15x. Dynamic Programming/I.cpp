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

int l, n, a[55];
int dp[55][55];

int dfs(int i, int j) {
    if(i >= j - 1) return 0;
    if(dp[i][j] != INF) return dp[i][j];

    int ret = INF;
    for(int k = i + 1; k < j; ++k) {
        int v = dfs(i, k) + dfs(k, j) + a[j] - a[i];
        ret = min(ret, v);
    }
    return dp[i][j] = ret;
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(cin >> l && l) {
        cin >> n;
        for(int i = 1; i <= n; ++i) cin >> a[i];
        a[0] = 0; a[n + 1] = l;

        memset(dp, 0x3f, sizeof dp);
        cout << "The minimum cutting is " << dfs(0, n + 1) << ".\n";
    }
    return 0;
}
