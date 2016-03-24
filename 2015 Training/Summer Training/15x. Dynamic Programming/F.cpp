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

int n, sum[1005], dp[1005];
struct Lamp {
    int v, k, c, l;
    bool operator< (const Lamp& rhs) const {
        return v < rhs.v;
    }
} a[1005];

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(cin >> n && n) {
        for(int i = 1; i <= n; ++i)
            cin >> a[i].v >> a[i].k >> a[i].c >> a[i].l;
        sort(a + 1, a + 1 + n);
        for(int i = 1; i <= n; ++i) sum[i] = sum[i - 1] + a[i].l;

        memset(dp, 0x3f, sizeof dp);
        dp[0] = 0;
        //dp[i]:= 1~i category minimum cost
        for(int i = 1; i <= n; ++i) {
            for(int j = 0; j < i; ++j) {
                dp[i] = min(dp[i], dp[j] + (sum[i] - sum[j]) * a[i].c + a[i].k);
            }
        }
        cout << dp[n] << '\n';
    }
    return 0;
}
