//
//  Created by TaoSama on 2015-11-05
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

int n, a[16], cover[1 << 16], dp[1 << 16];

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int kase = 0;
    while(scanf("%d", &n) == 1 && n) {
        for(int i = 0; i < n; ++i) {
            a[i] = 1 << i;
            int m; scanf("%d", &m);
            while(m--) {
                int x; scanf("%d", &x);
                a[i] |= 1 << x;
            }
        }
        for(int s = 1; s < 1 << n; ++s) {
            cover[s] = 0;
            for(int i = 0; i < n; ++i)
                if(s >> i & 1) cover[s] |= a[i];
        }

        memset(dp, 0, sizeof dp);
        for(int s = 1; s < 1 << n; ++s)
            for(int s0 = s; s0; s0 = (s0 - 1) & s)
                if(cover[s0] == (1 << n) - 1)
                    dp[s] = max(dp[s], dp[s ^ s0] + 1);
        printf("Case %d: %d\n", ++kase, dp[(1 << n) - 1]);
    }
    return 0;
}
