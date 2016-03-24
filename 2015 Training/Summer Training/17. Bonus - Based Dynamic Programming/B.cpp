//
//  Created by TaoSama on 2015-08-08
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

int a[10];
bool dp[120005];

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int kase = 0;
    while(true) {
        int sum = 0;
        for(int i = 1; i <= 6; ++i) {
            cin >> a[i];
            sum += i * a[i];
        }
        if(!sum) break;
        cout << "Collection #" << ++kase << ":\n";
        if(sum & 1) {
            cout << "Can't be divided.\n\n";
            continue;
        }

        sum >>= 1;
        memset(dp, false, sizeof dp);
        dp[0] = true;
        for(int i = 1; i <= 6; ++i) {
            for(int k = 1; a[i] > 0; a[i] -= k, k <<= 1) {
                int c = min(k, a[i]);
                for(int j = sum; j >= c * i; --j)
                    dp[j] |= dp[j - c * i];
            }
        }
        cout << (dp[sum] ? "Can" : "Can't") << " be divided.\n\n";
    }
    return 0;
}
