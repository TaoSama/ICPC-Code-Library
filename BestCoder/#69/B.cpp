//
//  Created by TaoSama on 2016-01-23
//  Copyright (c) 2015 TaoSama. All rights reserved.
//
#pragma comment(linker, "/STACK:1024000000,1024000000")
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

typedef long long LL;
int n, m;
char s[35][35];
bool vis[35][35];
LL sum;

int dir[][2] = { -1, 0, 0, -1, 1, 0, 0, 1};

void dfs(int x, int y, LL up, LL down) {
    vis[x][y] = true;
    if(up % down == 0 && up / down == sum) throw 1;
    for(int i = 0; i < 4; ++i) {
        int tx = x + dir[i][0], ty = y + dir[i][1];
        int nx = tx + dir[i][0], ny = ty + dir[i][1];
        if(nx < 1 || nx > n || ny < 1 || ny > m || vis[nx][ny]) continue;
        char op = s[tx][ty]; int d = s[nx][ny] - '0';
        if(op == '+') dfs(nx, ny, up + d * down, down);
        if(op == '-') dfs(nx, ny, up - d * down, down);
        if(op == '*') dfs(nx, ny, up * d, down);
        if(op == '/' && d) dfs(nx, ny, up, down * d);
    }
    vis[x][y] = false;
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int t; scanf("%d", &t);
    while(t--) {
        scanf("%d%d%I64d", &n, &m, &sum);
        for(int i = 1; i <= n; ++i) scanf("%s", s[i] + 1);
        try {
            for(int i = 1; i <= n; i += 2) {
                for(int j = 1; j <= m; j += 2) {
                    memset(vis, false, sizeof vis);
                    dfs(i, j, s[i][j] - '0', 1);
                }
            }
        } catch(int) {
            puts("Possible");
            continue;
        }
        puts("Impossible");
    }
    return 0;
}
