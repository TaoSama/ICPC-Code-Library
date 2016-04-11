//
//  Created by TaoSama on 2015-04-25
//  Copyright (c) 2015 TaoSama. All rights reserved.
//
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
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int N = 1e5 + 10;

int n, m, p, t;
int a[55][55][55][55], key[55][55];
bool vis[55][55][1050];
int d[][2] = { -1, 0, 1, 0, 0, 1, 0, -1};

struct P {
    int x, y, step, key;
    P(int x = 0, int y = 0, int step = 0, int key = 0):
        x(x), y(y), step(step), key(key) {}
};

int bfs() {
    queue<P> q; q.push(P(1, 1, 0, key[1][1]));
    memset(vis, false, sizeof vis); vis[1][1][key[1][1]] = true;
    while(!q.empty()) {
        P cur = q.front(); q.pop();
        int x = cur.x, y = cur.y, step = cur.step, k = cur.key;
        for(int i = 0; i < 4; ++i) {
            int nx = x + d[i][0], ny = y + d[i][1], nkey = k | key[nx][ny];
            if(nx < 1 || nx > n || ny < 1 || ny > m || vis[nx][ny][nkey]) continue;
            if(a[x][y][nx][ny] == -1 || (1 << a[x][y][nx][ny]) & k) {
                if(nx == n && ny == m) return step + 1;
                vis[nx][ny][nkey] = true;
                q.push(P(nx, ny, step + 1, nkey));
            }
        }
    }
    return -1;
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d%d%d", &n, &m, &p) == 3) {
        scanf("%d", &t);
        memset(a, -1, sizeof a);
        memset(key, 0, sizeof key);
        while(t--) {
            int _x1, _y1, _x2, _y2, g;
            scanf("%d%d%d%d%d", &_x1, &_y1, &_x2, &_y2, &g);
            a[_x1][_y1][_x2][_y2] = a[_x2][_y2][_x1][_y1] = g;
        }
        scanf("%d", &t);
        while(t--) {
            int x, y, k; scanf("%d%d%d", &x, &y, &k);
            key[x][y] |= (1 << k);
        }
        printf("%d\n", bfs());
    }
    return 0;
}
