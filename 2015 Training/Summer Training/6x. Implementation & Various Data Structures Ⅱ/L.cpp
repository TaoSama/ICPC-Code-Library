//
//  Created by TaoSama on 2015-07-24
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

int d[][2] = { -2, -1, -1, -2, 1, 2, 2, 1, -1, 2, 2, -1, -2, 1, 1, -2};
int sx, sy, gx, gy, dp[8][8];
typedef pair<int, int> P;

int bfs() {
    queue<P> q;
    memset(dp, 0x3f, sizeof dp);
    dp[sx][sy] = 0; q.push({sx, sy});
    while(q.size()) {
        P cur = q.front(), nxt; q.pop();
        for(int i = 0; i < 8; ++i) {
            nxt.first = cur.first + d[i][0], nxt.second = cur.second + d[i][1];
            if(nxt.first < 0 || nxt.first >= 8 || nxt.second < 0
                    || nxt.second >= 8) continue;
            if(dp[nxt.first][nxt.second] == INF) {
                dp[nxt.first][nxt.second] = dp[cur.first][cur.second] + 1;
                q.push(nxt);
            }
        }
    }
    return dp[gx][gy];
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    char op[2][4];
    while(cin >> op[0] >> op[1]) {
        sx = op[0][0] - 'a', sy = op[0][1] - '1';
        gx = op[1][0] - 'a', gy = op[1][1] - '1';
        cout << "To get from " << op[0] << " to " << op[1] << " takes " <<
             bfs() << " knight moves.\n";
    }
    return 0;
}
