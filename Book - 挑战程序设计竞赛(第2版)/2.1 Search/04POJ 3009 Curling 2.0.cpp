//
//  POJ 3009 Curling 2.0
//
//  Created by TaoSama on 2015-02-19
//  Copyright (c) 2014 TaoSama. All rights reserved.
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
#define CLR(x,y) memset(x, y, sizeof(x))

using namespace std;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int N = 1e5 + 10;

int n, m, d[4][2] = { -1, 0, 1, 0, 0, 1, 0, -1};;
char a[105][105];
int sx, sy, ans;
void dfs(int x, int y, int seg) {
    if(seg > 10 || seg >= ans) return;
    for(int i = 0; i < 4; ++i) {
        for(int j = 1;; ++j) {
            int nx = x + j * d[i][0], ny = y + j * d[i][1];
            if(nx < 1 || nx > n || ny < 1 || ny > m) break;
            if(a[nx][ny] == '3') {
                ans = min(ans, seg + 1);
//              cout << "seg: " << seg + 1 << endl;
                return;
            }
            if(a[nx][ny] == '1') {
                if(j == 1) break;
                a[nx][ny] = '0';
                nx -= d[i][0], ny -= d[i][1];
                dfs(nx, ny, seg + 1);
                nx += d[i][0], ny += d[i][1];
                a[nx][ny] = '1';
                break;
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

    while(cin >> m >> n && n != 0 && m != 0) {
        for(int i = 1; i <= n; ++i) {
            for(int j = 1; j <= m; ++j) {
                cin >> a[i][j];
                if(a[i][j] == '2')
                    sx = i, sy = j;
            }
        }
        ans = INF;
        dfs(sx, sy, 0);
        if(ans > 10) ans = -1;
        cout << ans << endl;
    }
    return 0;
}
