//
//  Created by TaoSama on 2015-05-23
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

int ds[8][2] = { -2, -1, -2, 1, -1, 2, 1, 2, 2, 1, 2, -1, 1, -2, -1, -2};
int n, m, k;
int sx, sy, kx, ky;
typedef pair<int, int> P;
int dp[1005][1005];

void bfs() {
    memset(dp, 0x3f, sizeof dp);
    queue<P> q; q.push(P(sx, sy));
    dp[sx][sy] = 0;
    while(q.size()) {
        int x = q.front().first, y = q.front().second;
        q.pop();
        for(int i = 0; i < 8; ++i) {
            int nx = x + ds[i][0], ny = y + ds[i][1];
            if(nx < 1 || nx > n || ny < 1 || ny > m) continue;
            if(dp[nx][ny] == INF) {
                dp[nx][ny] = dp[x][y] + 1;
                q.push(P(nx, ny));
            }
        }
    }
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int t; scanf("%d", &t);
    int kase = 0;
    while(t--) {
        printf("Case #%d:\n", ++kase);
        scanf("%d%d%d", &n, &m, &k);
        scanf("%d%d%d%d", &kx, &ky, &sx, &sy);
        int ans = INF;
        bfs();
        for(int i = 1; i <= n; ++i) {
            for(int j = 1; j <= m; ++j) {
                int d = max(abs(i - kx), abs(j - ky));
                if(abs(dp[i][j] - d) % 2 == 0)
                    ans = min(ans, max(dp[i][j], d));
            }
        }
        if(ans > k) printf("OH,NO!\n");
        else printf("%d\n", ans);
    }
    return 0;
}
