//
//  Created by TaoSama on 2015-09-11
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
const int N = 1e6 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, m, a[N];
bool dp[2][1005];

bool judge() {
    if(n > m) return true;
    memset(dp, 0, sizeof dp);
    dp[0][0] = 1;
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            if(!dp[i & 1][j]) continue;
            dp[(i + 1) & 1][(j + a[i + 1]) % m] = dp[(i + 1) & 1][j] = 1;
            if((j + a[i + 1]) % m == 0) return true;
        }
    }
    return false;
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d%d", &n, &m) == 2) {
        for(int i = 1; i <= n; ++i) scanf("%d", a + i);
        puts(judge() ? "YES" : "NO");
    }
    return 0;
}
