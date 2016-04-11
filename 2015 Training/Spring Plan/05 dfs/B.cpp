//
//  Created by TaoSama on 2015-05-30
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

int n, m, d[][2] = { -1, 0, 0, -1, 1, 0, 0, 1};
char a[8][8];

bool dfs(int x, int y) {
    for(int i = 0; i < 4; ++i) {
        int nx = x + d[i][0], ny = y + d[i][1];
        if(nx < 1 || nx > n || ny < 1 || ny > m || a[nx][ny] == '*') continue;
        a[x][y] = '*';
        bool sub = dfs(nx, ny);
        a[x][y] = '.';
        if(sub) return false;  //子局面有赢的就输了
    }
    return true; //子局面都输说明赢了
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d%d", &n, &m) == 2) {
        for(int i = 1; i <= n; ++i) scanf("%s", a[i] + 1);
        bool win = false;
        for(int i = 1; i <= n; ++i) {
            for(int j = 1; j <= m; ++j) {
                if(a[i][j] == '.' && dfs(i, j)) {
                    win = true;
                    break;
                }
            }
            if(win) break;
        }
        puts(win ? "Alice" : "Bob");
    }
    return 0;
}
