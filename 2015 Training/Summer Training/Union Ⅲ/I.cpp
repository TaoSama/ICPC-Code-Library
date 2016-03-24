//
//  Created by TaoSama on 2015-08-28
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
const int N = 2e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

typedef long long LL;
int n, q, w[405], v[405], path[N][55];
LL dp[N]; //all the state can reach

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int t; scanf("%d", &t);
    while(t--) {
        scanf("%d%d", &n, &q);
        LL S = (1LL << 51) - 1;
        memset(dp, 0, sizeof dp);
        dp[0] = 1;
        for(int i = 1; i <= n; ++i) {
            scanf("%d%d", v + i, w + i);
            for(int j = 2e5; j >= w[i]; --j) {
                LL last = dp[j];
                dp[j] |= (dp[j - w[i]] << v[i]) & S; //so beautiful
                //enumerate the new bit to save the path
                for(LL k = dp[j] ^ last; k; k -= k & -k) {
                    LL cur = k & -k;
                    int wh = __builtin_ctzll(cur);
                    path[j][wh] = i;
                }
            }
        }
        while(q--) {
            int m, s; scanf("%d%d", &m, &s);
            if(!(dp[s] & (1LL << m))) {puts("No solution!"); continue;}
            bool first = true;
            while(s) {
                if(!first) putchar(' ');
                else first = false;
                int id = path[s][m];
                printf("%d", id);
                s -= w[id];
                m -= v[id];
            }
            puts("");
        }
    }
    return 0;
}
