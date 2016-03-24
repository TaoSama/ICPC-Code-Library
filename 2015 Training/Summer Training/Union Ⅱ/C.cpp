//
//  Created by TaoSama on 2015-08-24
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

int n;
bool g[205][205];

bool vis[205];
int match[205];
bool dfs(int u) {
    for(int v = 1; v <= n; ++v) {
        if(!g[u][v] || vis[v]) continue;
        vis[v] = true;
        if(match[v] == -1 || dfs(match[v])) {
            match[v] = u;
            return true;
        }
    }
    return false;
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d", &n) == 1) {
        memset(g, false, sizeof g);
        for(int i = 1; i <= n; ++i) {
            char buf[205]; scanf("%s", buf + 1);
            for(int j = 1; j <= n; ++j)
                if(buf[j] == 'U') g[i][j] = true;
        }

        memset(match, -1, sizeof match);
        int cnt = 0;
        for(int i = 1; i <= n; ++i) {
            memset(vis, false, sizeof vis);
            cnt += dfs(i);
        }
        puts(cnt == n ? "YES" : "NO");
    }
    return 0;
}
