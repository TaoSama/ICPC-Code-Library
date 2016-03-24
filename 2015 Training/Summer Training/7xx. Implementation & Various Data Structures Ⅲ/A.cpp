//
//  Created by TaoSama on 2015-07-25
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

int n, m, k, a[25][25], dp[25][25][25];
int d[][2] = { -1, 0, 0, -1, 1, 0, 0, 1};

struct Sta {
    int x, y, k;
    Sta() {}
    Sta(int x, int y, int k): x(x), y(y), k(k) {}
};

int bfs() {
    queue<Sta> q;
    memset(dp, 0x3f, sizeof dp);
    q.push(Sta(1, 1, 0)); dp[1][1][0] = 0;
    while(q.size()) {
        Sta cur = q.front(), nxt; q.pop();
        for(int i = 0; i < 4; ++i) {
            nxt = cur;
            nxt.x += d[i][0], nxt.y += d[i][1];
            if(nxt.x < 1 || nxt.x > n || nxt.y < 1 || nxt.y > m) continue;
            if(a[nxt.x][nxt.y] == 1) nxt.k ++;
            else nxt.k = 0;
            if(nxt.k > k) continue;
            if(dp[nxt.x][nxt.y][nxt.k] == INF) {
                dp[nxt.x][nxt.y][nxt.k] = dp[cur.x][cur.y][cur.k] + 1;
                q.push(nxt);
            }
        }
    }
    return *min_element(dp[n][m], dp[n][m] + k + 2);
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int t; cin >> t;
    while(t--) {
        cin >> n >> m >> k;
        for(int i = 1; i <= n; ++i)
            for(int j = 1; j <= m; ++j)
                cin >> a[i][j];

        int ans = bfs();
        if(ans == INF) ans = -1;
        cout << ans << '\n';
    }
    return 0;
}
