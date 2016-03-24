//
//  Created by TaoSama on 2015-08-02
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

int n, m, g[105][105], a[105];

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(cin >> n >> m) {
        for(int i = 1; i <= n; ++i) cin >> a[i];
        memset(g, 0, sizeof g);
        for(int i = 1; i <= m; ++i) {
            int u, v; cin >> u >> v;
            g[u][v] = g[v][u] = true;
        }

        int ans = INF;
        for(int i = 1; i <= n; ++i) {
            for(int j = i + 1; j <= n; ++j) {
                for(int k = j + 1; k <= n; ++k) {
                    if(g[i][j] && g[i][k] && g[j][k]) {
                        ans = min(ans, a[i] + a[j] + a[k]);
                    }
                }
            }
        }
        if(ans == INF) ans = -1;
        cout << ans << '\n';
    }
    return 0;
}
