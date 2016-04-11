//
//  Created by TaoSama on 2015-12-10
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

typedef pair<int, int> Point;

int vis[3][20]; //column, main, vice diagonal
Point goal[8], s[8];

int ans, g[8][8], f[10][1 << 8];

int get(int i, int j) {
    if(s[i].first == goal[j].first && s[i].second == goal[j].second) return 0;
    if(s[i].first == goal[j].first || s[i].second == goal[j].second) return 1;
    if(s[i].first - s[i].second == goal[j].first - goal[j].second) return 1;
    if(s[i].first + s[i].second == goal[j].first + goal[j].second) return 1;
    return 2;
}

void gao() {
    for(int i = 0; i < 8; ++i)
        for(int j = 0; j < 8; ++j)
            g[i][j] = get(i, j);

    memset(f, 0x3f, sizeof f);
    f[0][0] = 0;
    for(int i = 0; i < 8; ++i) {
        for(int j = 0; j < 1 << 8; ++j) {
            if(f[i][j] == INF) continue;
            for(int k = 0; k < 8; ++k) {
                if(j >> k & 1) continue;
                f[i + 1][j | 1 << k] = min(f[i + 1][j | 1 << k], f[i][j] + g[i][k]);
            }
        }
    }
    ans = min(ans, f[8][(1 << 8) - 1]);
}

void dfs(int row) {
    if(row == 8) {
        gao();
        return;
    }
    for(int i = 0; i < 8; ++i) {
        if(vis[0][i] || vis[1][row - i + 8] || vis[2][row + i]) continue;
        goal[row] = Point(row, i);
        vis[0][i] = vis[1][row - i + 8] = vis[2][row + i] = 1;
        dfs(row + 1);
        vis[0][i] = vis[1][row - i + 8] = vis[2][row + i] = 0;
    }
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
        int idx = 0;
        for(int i = 0; i < 8; ++i) {
            char buf[10]; scanf("%s", buf);
            for(int j = 0; j < 8; ++j)
                if(buf[j] == 'q') s[idx++] = Point(i, j);
        }

        ans = INF;
        dfs(0);
        printf("Case %d: %d\n", ++kase, ans);
    }
    return 0;
}
