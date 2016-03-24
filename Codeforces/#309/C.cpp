By TaoSama, contest: Codeforces Round #309 (Div. 2), problem: (C) Kyoya and Colored Balls, Accepted, #
 //
//  Created by TaoSama on 2015-06-25
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

long long n, a[1005], c[1005][1005];

void InitC() {
    for(int i = 0; i <= 1000; ++i) {
        for(int j = 0; j <= i; ++j)
            if(i == j || j == 0) c[i][j] = 1;
            else c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % MOD;
    }
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);


    InitC();
    while(cin >> n) {
        int sum = 0;
        for(int i = 1; i <= n; ++i) {
            cin >> a[i];
            sum += a[i];
        }

        long long ans = 1;
        for(int i = n; i >= 1; --i) {
            ans = ans * c[sum - 1][a[i] - 1] % MOD;
            sum -= a[i];
        }
        cout << ans << '\n';
    }
    return 0;
}
