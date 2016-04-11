//
//
//
//  Created by TaoSama on 2015-04-16
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

int n, m, cnt;
char a[25][25];

void dfs(int x, int y) {
    a[x][y] = '0';
    ++cnt;
    for(int i = -1; i <= 1; ++i) {
        for(int j = -1; j <= 1; ++j) {
            int nx = x + i, ny = y + j;
            if(nx < 1 || nx > n || ny < 1 || ny > m) continue;
            if(a[nx][ny] == '1') dfs(nx, ny);
        }
    }
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int t; cin >> t;
    while(t--) {
        cin >> n >> m;
        for(int i = 1; i <= n; ++i)
            for(int j = 1; j <= m; ++j)
                cin >> a[i][j];

        int ans = 0;
        for(int i = 1; i <= n; ++i) {
            for(int j = 1; j <= m; ++j) {
                cnt = 0;
                if(a[i][j] == '1') dfs(i, j);
                if(cnt > ans) ans = cnt;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
