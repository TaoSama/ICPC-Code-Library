//
//  Created by TaoSama on 2017-04-02
//  Copyright (c) 2016 TaoSama. All rights reserved.
//
#pragma comment(linker, "/STACK:102400000,102400000")
#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <set>
#include <vector>

using namespace std;
#define pr(x) cerr << #x << " = " << x << "  "
#define prln(x) cerr << #x << " = " << x << endl
const int N = 1e2 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

char s[N][N];
int n, m, a[N][N][5], vis[N][N][5];

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    scanf("%d%d", &n, &m); gets(s[0]);
    for(int i = 1; i <= n; ++i) {
        gets(s[i] + 1);
        for(int j = 1; j <= m; ++j) {
            if(s[i][j] == '/') a[i][j][0] = a[i][j][1] = 1;
            else if(s[i][j] == '\\') a[i][j][2] = a[i][j][3] = 1;
            else a[i][j][4] = 1;
        }
    }

    int ans = 0;
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= m; ++j) {
            for(int k = 0; k < 5; ++k) {
                if(!a[i][j][k] || vis[i][j][k]) continue;
                ++ans;
                queue<pair<pair<int, int>, int>> q;
                q.push({{i, j}, k});
                vis[i][j][k] = 1;
//                pr(1); pr(i); pr(j); prln(k);
                while(q.size()) {
                    int x, y, s = q.front().second;
                    tie(x, y) = q.front().first;
                    q.pop();
                    static int d[][2] = { -1, 0, 0, 1, 1, 0, 0, -1}; //上右下左
                    //不能走的方向
                    static pair<int, int> g[] = {{1, 2}, {0, 3}, {0, 1}, {2, 3}};
                    //每个方向可以接受的状态
                    static pair<int, int> can[] = {{1, 2}, {0, 2}, {0, 3}, {1, 3}};
                    auto go = [&](int dir) {
                        int nx = x + d[dir][0], ny = y + d[dir][1];
                        if(nx < 1 || nx > n || ny < 1 || ny > m) return;
                        int s1, s2; tie(s1, s2) = can[dir];
                        if(a[nx][ny][s1] && !vis[nx][ny][s1]) {
                            vis[nx][ny][s1] = 1;
//                            printf("%d %d %d->%d %d %d\n", x, y, s, nx, ny, s1);
                            q.push({{nx, ny}, s1});
                        }
                        if(a[nx][ny][s2] && !vis[nx][ny][s2]) {
                            vis[nx][ny][s2] = 1;
//                            printf("%d %d %d->%d %d %d\n", x, y, s, nx, ny, s2);
                            q.push({{nx, ny}, s2});
                        }
                        if(a[nx][ny][4] && !vis[nx][ny][4]) {
                            vis[nx][ny][4] = 1;
//                            printf("%d %d %d->%d %d %d\n", x, y, s, nx, ny, 4);
                            q.push({{nx, ny}, 4});
                        }
                    };
                    if(s == 4) {
                        for(int i = 0; i < 4; ++i) go(i);
                    } else {
                        int d1, d2; tie(d1, d2) = g[s ^ 1];  //能走的方向
                        go(d1);
                        go(d2);
                    }
                }
            }
        }
    }
    printf("%d\n", ans);

    return 0;
}
