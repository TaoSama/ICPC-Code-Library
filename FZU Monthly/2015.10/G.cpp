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

int n, dp[100005][7][2]; //0->white 1->black

inline void add(int& x, int& y) {
    x += y;
    while(x >= 2015) x -= 2015;
}

void gao() {
    dp[1][1][0] = 1;
    for(int i = 1; i < 1e5; ++i) {
        for(int j = 1; j <= i && j < 7; ++j) {
            for(int k = 0; k < 2; ++k) {
                add(dp[i + 1][1][k ^ 1], dp[i][j][k]);
                if(j + 1 < 7) add(dp[i + 1][j + 1][k], dp[i][j][k]);
            }
        }
    }
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int t; scanf("%d", &t);
    int kase = 0;
    gao();
    while(t--) {
        scanf("%d", &n);
        printf("Case #%d: ", ++kase);
        if(n <= 6) {
            printf("%d\n", 1 << n);
            continue;
        }

        int ans = 0;
        for(int i = 1; i <= 6; ++i) {
            for(int j = 1; j <= n - i && j < 7; ++j) {
                for(int k = 0; k < 2; ++k) {
                    if(i + (k == 1) * j >= 7) continue;
                    add(ans, dp[n - i][j][k]);
                }
            }
        }
        add(ans, ans);
        printf("%d\n", ans);
    }
    return 0;
}
