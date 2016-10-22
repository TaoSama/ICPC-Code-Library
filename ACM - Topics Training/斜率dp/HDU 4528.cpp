//
//  Created by TaoSama on 2016-05-12
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
#include <tuple>

using namespace std;
#define pr(x) cout << #x << " = " << x << "  "
#define prln(x) cout << #x << " = " << x << endl
const int N = 100 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, m, k;
char s[N][N];
int up[N][N], dw[N][N], l[N][N], r[N][N];
int f[N][N][4];
struct Sta {
    int x, y, s;
};

bool isLegal(char c) {
    return c && (c == '.' || c == 'S');
}

int bfs(int sx, int sy) {
    int sta = up[sx][sy] | dw[sx][sy] | l[sx][sy] | r[sx][sy];
    queue<Sta> q; q.push({sx, sy, sta});
    memset(f, -1, sizeof f);
    f[sx][sy][sta] = 0;
    while(q.size()) {
        Sta u = q.front(); q.pop();
        if(f[u.x][u.y][u.s] > k) continue;
        if(u.s == 3) return f[u.x][u.y][u.s];

        static int dir[][2] = { -1, 0, 0, -1, 1, 0, 0, 1};
        for(int i = 0; i < 4; ++i) {
            Sta v = u;
            v.x += dir[i][0]; v.y += dir[i][1];
            v.s |= up[v.x][v.y] | dw[v.x][v.y] | l[v.x][v.y] | r[v.x][v.y];
            if(!isLegal(s[v.x][v.y])) continue;

//            printf("(%d, %d) : %d, (%d, %d) : %d\n",
//              u.x, u.y, u.s, v.x, v.y, v.s);

            if(f[v.x][v.y][v.s] == -1) {
                f[v.x][v.y][v.s] = f[u.x][u.y][u.s] + 1;
                q.push(v);
            }
        }
    }
    return -1;
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);
    clock_t _ = clock();

    int t; scanf("%d", &t);
    while(t--) {
        scanf("%d%d%d", &n, &m, &k);
        memset(s, 0, sizeof s);
        int sx, sy; sx = sy = -1;
        for(int i = 1; i <= n; ++i) {
            scanf("%s", s[i] + 1);
            for(int j = 1; j <= m; ++j)
                if(s[i][j] == 'S') sx = i, sy = j;
        }
        for(int i = 1; i <= n; ++i) {
            for(int j = 1; j <= m; ++j) {
                if(s[i][j - 1] == 'D') l[i][j] = 1;
                else if(s[i][j - 1] == 'E') l[i][j] = 2;
                else if(s[i][j - 1] == 'X') l[i][j] = 0;
                else l[i][j] = l[i][j - 1];
            }
            r[i][m + 1] = 0;
            for(int j = m; j; --j) {
                if(s[i][j + 1] == 'D') r[i][j] = 1;
                else if(s[i][j + 1] == 'E') r[i][j] = 2;
                else if(s[i][j + 1] == 'X') r[i][j] = 0;
                else r[i][j] = r[i][j + 1];
            }
        }

        for(int j = 1; j <= m; ++j) {
            for(int i = 1; i <= n; ++i) {
                if(s[i - 1][j] == 'D') up[i][j] = 1;
                else if(s[i - 1][j] == 'E') up[i][j] = 2;
                else if(s[i - 1][j] == 'X') up[i][j] = 0;
                else up[i][j] = up[i - 1][j];
            }
            dw[n + 1][j] = 0;
            for(int i = n; i; --i) {
                if(s[i + 1][j] == 'D') dw[i][j] = 1;
                else if(s[i + 1][j] == 'E') dw[i][j] = 2;
                else if(s[i + 1][j] == 'X') dw[i][j] = 0;
                else dw[i][j] = dw[i + 1][j];
            }
        }

//        for(int i = 1; i <= n; ++i) {
//            for(int j = 1; j <= m; ++j) {
//                printf("(%d, %d): u: %d d: %d l: %d r: %d\n", i, j, up[i][j],
//                       dw[i][j], l[i][j], r[i][j]);
//            }
//        }

        static int kase = 0;
        printf("Case %d:\n", ++kase);
        printf("%d\n", bfs(sx, sy));
    }

#ifdef LOCAL
    printf("\nTime cost: %.2fs\n", 1.0 * (clock() - _) / CLOCKS_PER_SEC);
#endif
    return 0;
}
