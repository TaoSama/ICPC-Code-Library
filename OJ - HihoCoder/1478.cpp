//
//  Created by TaoSama on 2017-03-12
//  Copyright (c) 2016 TaoSama. All rights reserved.
//
#pragma comment(linker, "/STACK:102400000,102400000")
#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <set>
#include <vector>

using namespace std;
#define pr(x) cerr << #x << " = " << x << "  "
#define prln(x) cerr << #x << " = " << x << endl
const int N = 1e3 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, m;
char s[N][N];
int f[N][N];

void bfs() {
    queue<pair<int, int>> q;
    memset(f, -1, sizeof f);
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= m; ++j) {
            if(s[i][j] == '1') continue;
            f[i][j] = 0;
            q.push({i, j});
        }
    }
    int d[][2] = { -1, 0, 0, -1, 1, 0, 0, 1};
    while(q.size()) {
        auto u = q.front(); q.pop();
        for(int i = 0; i < 4; ++i) {
            auto v = u;
            v.first += d[i][0];
            v.second += d[i][1];
            if(v.first < 1 || v.first > n || v.second < 1 || v.second > m) continue;
            if(f[v.first][v.second] == -1) {
                f[v.first][v.second] = f[u.first][u.second] + 1;
                q.push(v);
            }
        }
    }
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; ++i) scanf("%s", s[i] + 1);
    bfs();

    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j)
            printf("%d%c", f[i][j], " \n"[j == m]);




    return 0;
}
