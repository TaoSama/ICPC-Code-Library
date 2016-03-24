//
//  Created by TaoSama on 2015-08-16
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

int n, m;
char from[105][25], to[105][25];
int cost[105], dp[1 << 20];
bool in[1 << 20];

int spfa() {
    queue<int> q;
    memset(in, false, sizeof in);
    memset(dp, 0x3f, sizeof dp);
    int s = (1 << n) - 1;
    dp[s] = 0; in[s] = true;
    q.push(s);
    while(q.size()) {
        int u = q.front(); q.pop();
        in[u] = false;
        for(int i = 1; i <= m; ++i) {
            bool ok = true;
            for(int j = 0; j < n; ++j) {
                if(from[i][j] == '0') continue;
                if(from[i][j] == '+' && (u >> j & 1)) continue;
                if(from[i][j] == '-' && !(u >> j & 1)) continue;
                ok = false; break;
            }
            if(ok) {
                int v = u;
                for(int j = 0; j < n; ++j) {
                    if(to[i][j] == '0') continue;
                    else if(to[i][j] == '+') v |= 1 << j;
                    else v &= ~(1 << j);
                }
                if(dp[v] > dp[u] + cost[i]) {
                    dp[v] = dp[u] + cost[i];
                    if(!in[v]) {
                        q.push(v);
                        in[v] = true;
                    }
                }
            }
        }
    }
    return dp[0];
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int kase = 0;
    while(scanf("%d%d", &n, &m) == 2 && (n || m)) {
        for(int i = 1; i <= m; ++i)  scanf("%d%s%s", cost + i, from + i, to + i);

        int ans = spfa();
        printf("Product %d\n", ++kase);
        if(ans == INF) puts("Bugs cannot be fixed.");
        else printf("Fastest sequence takes %d seconds.\n", ans);
        puts("");
    }
    return 0;
}
