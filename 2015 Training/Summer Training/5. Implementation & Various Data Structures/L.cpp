//
//  Created by TaoSama on 2015-07-23
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

int n, m;
char a[105][105];

void dfs(int x, int y) {
    a[x][y] = '*';
    for(int i = -1; i <= 1; ++i) {
        for(int j = -1; j <= 1; ++j) {
            if(i == 0 && j == 0) continue;
            int nx = x + i, ny = y + j;
            if(nx < 1 || nx > n || ny < 1 || ny > m || a[nx][ny] == '*') continue;
            dfs(nx, ny);
        }
    }
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(cin >> n >> m && (n || m)) {
        for(int i = 1; i <= n; ++i) cin >> a[i] + 1;

        int ans = 0;
        for(int i = 1; i <= n; ++i) {
            for(int j = 1; j <= m; ++j) {
                if(a[i][j] == '@') {
                    ++ans;
                    dfs(i, j);
                }
            }
        }
        cout << ans << '\n';
    }
    return 0;
}
