//
//  Created by TaoSama on 2015-08-14
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

int n;

int dp[35]; //dp[i]:= i-th "L" as the end's safe ways

void gao() {
    dp[1] = 2; dp[2] = 4; dp[3] = 7;
    for(int i = 4; i <= 30; ++i)
        dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    gao();
    while(cin >> n && n) {
        int ans = (1 << n) - dp[n];
        cout << ans << '\n';
    }
    return 0;
}
