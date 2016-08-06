//
//  Created by TaoSama on 2016-07-28
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
#define pr(x) cout << #x << " = " << x << "  "
#define prln(x) cout << #x << " = " << x << endl
const int N = 15 * 15 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;
const double EPS = 1e-8;

int sgn(double x) {
    return x < -EPS ? -1 : x > EPS;
}

int n, m;
char s[N][N];
double a[N][N], ans[N];
bool isFreeX[N];

void getAns(int n, int m, int r) {
//    memset(ans, 0, sizeof ans);  //not necessary
    for(int i = r - 1; ~i; --i) {
        for(int j = 0; j < m; ++j) {
            if(!sgn(a[i][j])) continue;
            ans[j] = a[i][m];
            for(int k = j + 1; k < m; ++k)
                ans[j] -= a[i][k] * ans[k];
            ans[j] = ans[j] / a[i][j];
            break;
        }
    }
}

int gauss(int n, int m) {
    for(int i = 0; i < m; ++i) isFreeX[i] = false;
    int r = 0, c = 0;
    for(; r < n && c < m; ++r, ++c) {
        int maxR = r;       //row transform
        for(int i = r + 1; i < n; ++i)
            if(abs(a[i][c]) > abs(a[maxR][c])) maxR = i;
        if(maxR != r) swap(a[maxR], a[r]);

        if(!sgn(a[r][c])) { --r; isFreeX[c] = true; continue;}

        //eliminate coefficient
        for(int i = r + 1; i < n; ++i) {
            if(sgn(a[i][c])) {
                double delta = a[i][c] / a[r][c];
                for(int j = c; j <= m; ++j)
                    a[i][j] -= delta * a[r][j];
            }
        }
    }
    for(int i = r; i < n; i++) if(sgn(a[i][m])) return -1;

    getAns(n, m, r);

    //at last, r is rank, m - r is the number of freeX
    return r;
}

inline int ID(int x, int y) {
    return x * m + y;
}

bool can[N][N];
const int d[][2] = { -1, 0, 0, -1, 1, 0, 0, 1};
bool bfs(int sx, int sy) {
    memset(can, 0, sizeof can);
    queue<pair<int, int> > q;
    q.push({sx, sy});
    can[sx][sy] = true;

    bool ok = false;
    while(q.size()) {
        auto u = q.front(); q.pop();
        int x, y; tie(x, y) = u;
        if(s[x][y] == '$') ok = true;
        for(int i = 0; i < 4; ++i) {
            int nx = x + d[i][0], ny = y + d[i][1];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if(s[nx][ny] == '#' || can[nx][ny]) continue;
            can[nx][ny] = true;
            q.push({nx, ny});
        }
    }
    return ok;
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);
    clock_t _ = clock();

    while(scanf("%d%d", &n, &m) == 2) {
        int sx, sy; sx = sy = -1;
        for(int i = 0; i < n; ++i) {
            scanf("%s", s[i]);
            if(~sx) continue;
            for(int j = 0; j < m; ++j)
                if(s[i][j] == '@') sx = i, sy = j;
        }
        if(!bfs(sx, sy)) {puts("-1"); continue;}

        //E_i = sum(E_j)/cnt + 1 => sum(E_j) - cnt*E_i = -cnt
        memset(a, 0, sizeof a);
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                if(s[i][j] == '#') continue; //obstacle
                if(s[i][j] == '$') { //destination
                    a[ID(i, j)][ID(i, j)] = 1;
                    a[ID(i, j)][n * m] = 0; //E_exit = 0;
                    continue;
                }

                int cnt = 0;
                for(int k = 0; k < 4; ++k) {
                    int x = i + d[k][0], y = j + d[k][1];
                    if(x < 0 || x >= n || y < 0 || y >= m || !can[x][y]) continue;
                    ++cnt;
                    a[ID(i, j)][ID(x, y)] = 1;
                }
                a[ID(i, j)][ID(i, j)] = -cnt;
                a[ID(i, j)][n * m] = -cnt;
            }
        }

//        for(int i = 0; i < n * m; ++i)
//          for(int j = 0; j <= n * m; ++j)
//              printf("%.3f%c", a[i][j], " \n"[j == n * m]);

        gauss(n * m, n * m);
        double result = ans[ID(sx, sy)];
        printf("%.6f\n", result);
    }

#ifdef LOCAL
    printf("\nTime cost: %.2fs\n", 1.0 * (clock() - _) / CLOCKS_PER_SEC);
#endif
    return 0;
}
