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

int n, m, sx, sy, cnt, ans;
//左右上下
int d[4][2] = { 0, -1, 0, 1, -1, 0, 1, 0};
char a[1005][1005];
int vis[1005][1005];

int calc(int x, char c) {
    if(c == '/') {
        return 3 - x;
    } else {
        if(x == 0) return 2;
        if(x == 1) return 3;
        if(x == 2) return 0;
        if(x == 3) return 1;
    }
}

bool dfs(int x, int y, int p) {
    int i = 0;
    while(++i) {
        int nx = x + i * d[p][0], ny = y + i * d[p][1];
        if(nx < 1 || nx > n || ny < 1 || ny > m || a[nx][ny] == '*')
            return false;
        if(vis[sx][sy] > 4) return false;
        if(a[nx][ny] == 'E') {
			if(!vis[nx][ny]) ++cnt;
			vis[nx][ny] ++;
        }
        //cout << nx << ' ' << ny << ' ' << a[nx][ny] << ' ' << cnt << endl;
        if(a[nx][ny] == '/' || a[nx][ny] == '\\')
            if(!dfs(nx, ny, calc(p, a[nx][ny])))
                return false;
    }
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    scanf("%d%d", &n, &m);
    bool ok = false;
    for(int i = 1; i <= n; ++i) {
        scanf("%s", a[i] + 1);
        if(!ok) for(int j = 1; j <= m; ++j) {
                if(a[i][j] == 'T') {
                    sx = i, sy = j;
                    ok = true;
                    break;
                }
            }
    }

    ans = 0;
    for(int i = 0; i < 4; ++i) {
		memset(vis, 0, sizeof vis);
        cnt = 0;
        dfs(sx, sy, i);
        if(cnt > ans) ans = cnt;
    }
    printf("%d\n", ans);
    return 0;
}
