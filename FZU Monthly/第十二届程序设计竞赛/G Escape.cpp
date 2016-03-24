//
//  Created by TaoSama on 2015-05-06
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

int n, m, destroyed[1005][1005], arrive[1005][1005];
int sx, sy, gx, gy, d[][2] = { -1, 0, 0, -1, 1, 0, 0, 1};
char a[1005][1005];
bool vis[1005][1005];

queue<pair<int, int> > q;

void process() {
    while(!q.empty()) {
        int x = q.front().first, y = q.front().second;
        q.pop();
        vis[x][y] = false;
        for(int i = 0; i < 4; ++i) {
            int nx = x + d[i][0], ny = y + d[i][1];
            if(nx < 1 || nx > n || ny < 1 || ny > m || a[nx][ny] == '#')
                continue;
            if(destroyed[nx][ny] > destroyed[x][y] + 1) {
                destroyed[nx][ny] = destroyed[x][y] + 1;
                if(!vis[nx][ny]) {
                    q.push(make_pair(nx, ny));
                    vis[nx][ny] = true;
                }
            }
        }
    }
}

bool bfs() {
    queue<pair<int, int> > q; q.push(make_pair(sx, sy));
    memset(vis, false, sizeof vis);
    memset(arrive, 0x3f, sizeof arrive);
    vis[sx][sy] = true; arrive[sx][sy] = 0;
    while(!q.empty()) {
        int x = q.front().first, y = q.front().second;
        q.pop();
        vis[x][y] = false;
        for(int i = 0; i < 4; ++i) {
            int nx = x + d[i][0], ny = y + d[i][1];
            if(nx < 1 || nx > n || ny < 1 || ny > m || a[nx][ny] == '#')
                continue;
            if(a[nx][ny] == 'E' && arrive[x][y]  + 1 <= destroyed[nx][ny])
                return true;
            if(arrive[nx][ny] > arrive[x][y] + 1 &&
                    arrive[x][y] + 1 < destroyed[nx][ny]) {
                arrive[nx][ny] = arrive[x][y] + 1;
                if(!vis[nx][ny]) {
                    q.push(make_pair(nx, ny));
                    vis[nx][ny] = true;
                }
            }
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

    int t; scanf("%d", &t);
    while(t--) {
        scanf("%d%d", &n, &m);
        while(!q.empty()) q.pop();

        memset(destroyed, 0x3f, sizeof destroyed);
        memset(vis, false, sizeof vis);
        for(int i = 1; i <= n; ++i) {
            scanf("%s", a[i] + 1);
            //memset(destroyed[i] + 1, 0x3f, m * sizeof(int));
            //memset(vis[i] + 1, false, m * sizeof(bool));
            for(int j = 1; j <= m; ++j) {
                if(a[i][j] == 'S') sx = i, sy = j;
                if(a[i][j] == 'E') gx = i, gy = j;
                if(a[i][j] == '!') {
                    destroyed[i][j] = 0;
                    q.push(make_pair(i, j));
                    vis[i][j] = true;
                }
            }
        }
        process();
        if(bfs()) puts("Yes");
        else puts("No");

        /*for(int i = 1; i <= n; ++i) {
            for(int j = 1; j <= m; ++j)
                if(destroyed[i][j] == INF)
                    cout << -1 << ' ';
                else cout << destroyed[i][j] << ' ';
            cout << endl;
        }
        cout << endl;
        for(int i = 1; i <= n; ++i) {
            for(int j = 1; j <= m; ++j)
                if(arrive[i][j] == INF) cout << -1 << ' ';
                else cout << arrive[i][j] << ' ';
            cout << endl;
        }*/
    }
    return 0;
}
