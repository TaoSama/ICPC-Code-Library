//
//  Created by TaoSama on 2017-04-16
//  Copyright (c) 2017 TaoSama. All rights reserved.
//
#pragma comment(linker, "/STACK:102400000,102400000")
#include <bits/stdc++.h>

using namespace std;
#define pr(x) cerr << #x << " = " << x << "  "
#define prln(x) cerr << #x << " = " << x << endl
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, m;
int a[25][25];

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int t; scanf("%d", &t);
    while(t--) {
        scanf("%d%d", &n, &m);
        int c = n * m;
        memset(a, 0, sizeof a);
        queue<pair<int, int>> q;
        q.push({1, 1});
        a[1][1] = -1;
        while(q.size()) {
            int x, y; tie(x, y) = q.front(); q.pop();
            a[x][y] = c--;
            static const int d[][2] = { -1, 0, 0, -1, 1, 0, 0, 1};
            for(int i = 0; i < 4; ++i) {
                int nx = x + d[i][0], ny = y + d[i][1];
                if(nx < 1 || nx > n || ny < 1 || ny > m) continue;
                if(a[nx][ny]) continue;
                a[nx][ny] = -1;
                q.push({nx, ny});
            }
        }
        for(int i = 1; i <= n; ++i)
            for(int j = 1; j <= m; ++j)
                printf("%d%c", a[i][j], " \n"[j == m]);
    }

    return 0;
}
