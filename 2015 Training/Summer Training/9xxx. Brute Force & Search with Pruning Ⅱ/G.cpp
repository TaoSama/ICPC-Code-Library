//
//  Created by TaoSama on 2015-07-28
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

int n, k, cnt, OFF = 250; //offset:= 250
bool vis[505][505], g[505][505];
int d[][2] = {1, 0, 0, 1, 0, -1, -1, 0};
const char* word = "ensw";

bool judge(int x, int y, int nx, int ny, int dep, int dir) {
    int left = (dep + 1 + n) * (n - dep) >> 1; //never arrive at destination
    if(abs(nx - OFF) + abs(ny - OFF) > left) return false;
    if(vis[nx][ny] || g[nx][ny]) return false;
    int tx = nx, ty = ny;
    while(tx != x) {
        tx -= d[dir][0];
        if(g[tx][ny]) return false;
    }
    while(ty != y) {
        ty -= d[dir][1];
        if(g[nx][ty]) return false;
    }
    return true;
}

int path[25];
void dfs(int x, int y, int dir, int dep) {
    if(dep == n + 1) {
        if(x == OFF && y == OFF) {
            ++cnt;
            for(int i = 1; i < dep; ++i) cout << word[path[i]];
            cout << '\n';
        }
        return;
    }

    for(int i = 0; i < 4; ++i) {
        if(i == dir || i + dir == 3) continue;
        int nx = x + dep * d[i][0], ny = y + dep * d[i][1];
        if(!judge(x, y, nx, ny, dep, i)) continue;
        vis[nx][ny] = true;
        path[dep] = i;
        dfs(nx, ny, i, dep + 1);
        vis[nx][ny] = false;
    }
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int t; cin >> t;
    while(t--) {
        cin >> n >> k;
        memset(vis, false, sizeof vis);
        memset(g, false, sizeof g);
        for(int i = 1; i <= k; ++i) {
            int x, y; cin >> x >> y;
            if(abs(x) > OFF || abs(y) > OFF) continue;
            g[x + OFF][y + OFF] = true;
        }

        cnt = 0;
        dfs(OFF, OFF, -1, 1);
        cout << "Found " << cnt << " golygon(s).\n\n";
    }
    return 0;
}
