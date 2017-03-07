//
//  Created by TaoSama on 2017-03-05
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
const int N = 500 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, m;
char s[N][N];
vector<pair<int, int> > block[N * N];
int minx[N * N], maxx[N * N], miny[N * N], maxy[N * N];

int d[][2] = { -1, 0, 0, -1, 1, 0, 0, 1};

int cc, r[N * N];
int vis[N][N];
void dfs(int x, int y, int k) {
    vis[x][y] = k;
    minx[k] = min(minx[k], x);
    miny[k] = min(miny[k], y);
    maxx[k] = max(maxx[k], x);
    maxy[k] = max(maxy[k], y);
    block[k].push_back({x, y});
    for(int i = 0; i < 4; ++i) {
        int nx = x + d[i][0], ny = y + d[i][1];
        if(nx < 1 || nx > n || ny < 1 || ny > m || vis[nx][ny] || s[nx][ny] == '0') continue;
        dfs(nx, ny, k);
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
    for(int j = 1; j <= m; ++j) {
        for(int i = 1; i <= n; ++i) {
            if(s[i][j] == '0' || vis[i][j]) continue;
            ++cc;
            minx[cc] = maxx[cc] = i;
            miny[cc] = maxy[cc] = j;
            dfs(i, j, cc);
        }
    }

//  prln(cc);

    for(int i = 1; i <= cc; ++i) r[i] = i;
//    sort(r + 1, r + 1 + cc, [](int x, int y) {
//        return make_pair(miny[x], minx[x]) < make_pair(miny[y], minx[y]);
//    });

    for(int i = 1; i <= cc; ++i) {
        int j = i;
        int w = maxx[j] - minx[j] + 1;
        int h = maxy[j] - miny[j] + 1;
        vector<string> t(w, string(h, '0'));
        printf("%d %d\n", w, h);
        for(auto& p : block[j]) {
            t[p.first - minx[j]][p.second - miny[j]] = '1';
        }
        for(auto& s : t) puts(s.c_str());
    }

    return 0;
}
