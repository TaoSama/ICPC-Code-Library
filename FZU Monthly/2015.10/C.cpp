//
//  Created by TaoSama on 2015-10-06
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

int n, k, dp[2][2][1005][1005][2][2];

#define rep(i, a, b) for(int i = a; i <= b; ++i)

inline void add(int& x, int& y) {
    x += y;
    if(x >= MOD) x -= MOD;
}

void gao() {
    rep(i, 0, 1) rep(j, 0, 1) dp[i][j][0][0][i][j] = 1;

    rep(a, 0, 1) rep(b, 0, 1)
    rep(i, 0, 1000) rep(j, 0, i)
    rep(x, 0, 1) rep(y, 0, 1) {
        add(dp[a][b][i + 1][j][y][0], dp[a][b][i][j][x][y]);
        if(!x) add(dp[a][b][i + 1][j + 1][y][1], dp[a][b][i][j][x][y]);
    }
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int t; scanf("%d", &t);
    gao();
    while(t--) {
        scanf("%d%d", &n, &k);
        int ans = 0;
        if(n < 4) {
            for(int s = 0; s < 1 << n; ++s) {
                if(__builtin_popcount(s) != k) continue;
                bool ok = true;
                for(int i = 0; i < n; ++i) {
                    if((s >> i & 1) && (s >> (i + 2) % n & 1)) {
                        ok = false;
                        break;
                    }
                }
                ans += ok;
            }
            printf("%d\n", ans);
            continue;
        }

        rep(a, 0, 1) rep(b, 0, 1) {
            int cur = a + b;
            if(cur > k) continue;
            rep(x, 0, 1) rep(y, 0, 1) {
                if(a && x || b && y) continue;
                add(ans, dp[a][b][n - 2][k - cur][x][y]);
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
