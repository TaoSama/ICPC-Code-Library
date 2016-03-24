//
//  Created by TaoSama on 2015-07-30
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

char a[15][15];
int n, m, maxd;
int vis[5][25]; //row col main(n-i+j) vice(i+j-1)

bool dfs(int x, int y, int dep) {
    if(dep == maxd) {
        for(int i = 1; i <= n; ++i)
            for(int j = 1; j <= m; ++j)
                if(a[i][j] == 'X' && !vis[1][i] && !vis[2][j]
                        && !vis[3][n - i + j] && !vis[4][i + j - 1])
                    return false;
        return true;
    }

    if(y == m + 1) x++, y = 1;
    if(x == n + 1) return false;
    vis[1][x]++, vis[2][y]++, vis[3][n - x + y]++, vis[4][x + y - 1]++;
    if(dfs(x, y + 1, dep + 1)) return true;
    vis[1][x]--, vis[2][y]--, vis[3][n - x + y]--, vis[4][x + y - 1]--;
    if(dfs(x, y + 1, dep)) return true;
    return false;
}

int main() {
#ifdef LOCAL
    freopen("in2.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int kase = 0;
    while(cin >> n && n) {
        cin >> m;
        for(int i = 1; i <= n; ++i) cin >> (a[i] + 1);

        bool ok = false;
        for(maxd = 0; maxd <= 4; maxd++) {
            memset(vis, 0, sizeof vis);
            if(dfs(1, 1, 0)) {
                ok = true;
                break;
            }
        }
        if(!ok) maxd = 5;
        cout << "Case " << ++kase << ": " << maxd << '\n';
    }
    return 0;
}
