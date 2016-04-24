//
//  Created by TaoSama on 2016-04-24
//  Copyright (c) 2016 TaoSama. All rights reserved.
//
#pragma comment(linker, "/STACK:102400000,102400000")
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
char s[105][105];
int f[105][105];
int sx, sy, tx, ty;
int d[][2] = {{1, 2}, {1, -2}, { -1, 2}, { -1, -2}, {2, 1}, {2, -1}, { -2, 1}, { -2, -1}};
int no[][2] = {0, 1, 0, -1, 0, 1, 0, -1, 1, 0, 1, 0, -1, 0, -1, 0};

int bfs() {
    queue<int> q; q.push(sx * m + sy);
    memset(f, -1, sizeof f);
    f[sx][sy] = 0;
    while(q.size()) {
        int u = q.front(); q.pop();
        int x = u / m, y = u % m;
        for(int i = 0; i < 8; ++i) {
            int nx = x + d[i][0], ny = y + d[i][1];
            int kx = x + no[i][0], ky = y + no[i][1];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if(kx < 0 || kx >= n || ky < 0 || ky >= m) continue;
            if(s[nx][ny] == '#' || s[kx][ky] == '#') continue;
            if(f[nx][ny] == -1) {
                f[nx][ny] = f[x][y] + 1;
                q.push(nx * m + ny);
            }
        }
    }
    return f[tx][ty];
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d%d", &n, &m) == 2) {
        for(int i = 0; i < n; ++i) {
            scanf("%s", s[i]);
            for(int j = 0; j < m; ++j) {
                if(s[i][j] == 's') sx = i, sy = j;
                if(s[i][j] == 'e') tx = i, ty = j;
            }
        }
        printf("%d\n", bfs());
    }
    return 0;
}
