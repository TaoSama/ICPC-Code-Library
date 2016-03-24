//
//  Created by TaoSama on 2015-11-07
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

int n, m, a[105], b[105];
int g[105][105], match[105];

bool vis[105];
bool dfs(int u) {
    for(int v = 1; v <= m; ++v) {
        if(!g[u][v] || vis[v]) continue;
        vis[v] = true;
        if(!match[v] || dfs(match[v])) {
            match[v] = u;
            return true;
        }
    }
    return false;
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int t; scanf("%d", &t);
    int kase = 0;
    while(t--) {
        scanf("%d", &n);
        for(int i = 1; i <= n; ++i) scanf("%d", a + i);
        scanf("%d", &m);
        for(int i = 1; i <= m; ++i) scanf("%d", b + i);
        memset(g, 0, sizeof g);
        for(int i = 1; i <= n; ++i)
            for(int j = 1; j <= m; ++j)
                if(a[i] && b[j] % a[i] == 0) g[i][j] = 1;
                else if(!b[j]) g[i][j] = 1;

        memset(match, 0, sizeof match);
        int ans = 0;
        for(int i = 1; i <= n; ++i) {
            memset(vis, 0, sizeof vis);
            ans += dfs(i);
        }
        printf("Case %d: %d\n", ++kase, ans);
    }
    return 0;
}
