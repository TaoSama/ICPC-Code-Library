//
//  Created by TaoSama on 2015-07-17
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

int a[5][5], dp[5][5];
int d[][2] = {1, 0, 0, 1, -1, 0, 0, -1};
typedef pair<int, int> P;
P pre[5][5];

void bfs() {
    queue<P> q; q.push(P(0, 0));
    dp[0][0] = a[0][0] = 1;
    while(q.size()) {
        int x = q.front().first, y = q.front().second; q.pop();
        if(x == 4 && y == 4) return;
        for(int i = 0; i < 4; ++i) {
            int nx = x + d[i][0], ny = y + d[i][1];
            if(nx < 0 || nx >= 5 || ny < 0 || ny >= 5 || a[nx][ny]) continue;
//          pr(nx); prln(ny);
            a[nx][ny] = 1;
            dp[nx][ny] = dp[x][y] + 1;
            pre[nx][ny] = P(x, y);
            q.push(P(nx, ny));
        }
    }
}

void print(int x, int y) {
    if(x == 0 && y == 0) {
        cout << "(0, 0)\n";
        return;
    }
    P& nxt = pre[x][y];
    print(nxt.first, nxt.second);
    cout << "(" << x << ", " << y << ")\n";
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    for(int i = 0; i < 5; ++i) for(int j = 0; j < 5; ++j) cin >> a[i][j];

    bfs();
    print(4, 4);

    return 0;
}
