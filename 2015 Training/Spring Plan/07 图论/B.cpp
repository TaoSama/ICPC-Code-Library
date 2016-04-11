//
//  Created by TaoSama on 2015-08-22
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

vector<int> G[1005];
bool vis[1005];

int n, wh[1005], c[1005];

bool cmp(int x, int y) {
    return c[x] > c[y];
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d", &n) == 1) {
        for(int i = 0; i < n; ++i) {
            scanf("%d", c + i);
            wh[i] = i;
        }
        sort(wh, wh + n, cmp);
        for(int i = 0; i < n; ++i) {
            G[i].clear();
            int k; scanf("%d", &k);
            for(int j = 1; j <= k; ++j) {
                int x; scanf("%d", &x);
                G[i].push_back(x);
            }
        }

        memset(vis, false, sizeof vis);
        long long ans = 0;
        for(int i = 0; i < n; ++i) {
            int u = wh[i];
//          printf("%d\n", u);
            for(int j = 0; j < G[u].size(); ++j) {
                int v = G[u][j];
                ans += vis[v] ? 0 : c[v];
//              printf("(%d, %d) ", v, ans);
            }
            vis[u] = true;
        }
        printf("%lld\n", ans);
    }
    return 0;
}
