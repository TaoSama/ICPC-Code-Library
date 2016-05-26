//
//  Created by TaoSama on 2016-05-25
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
const int N = 1e3 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, m;
int sx, sy, gx, gy;
char s[N][N];
int f[N][N][4];

char* single = "^>v<";
int first(char c) {
    char* p = strchr(single, c);
    if(!p) return -1;
    return p - single;
}
char* dbl = "|-";
int second(char c) {
    char* p = strchr(dbl, c);
    if(!p) return -1;
    return p - dbl;
}
char* triple = "URDL";
char third(char c) {
    char* p = strchr(triple, c);
    if(!p) return -1;
    return p - triple;
}

bool check(char c, int d, int r) {
    int f = first(c);
    int s = second(c);
    int t = third(c);
//    printf("-- (%d) %d %d %d (%d) --\n", d, f, s, t, r);
    if(~f) {
        f = (f + d) % 4;
        return f == r;
    } else if(~s) {
        s = (s + d) % 2;
        return s == r || s + 2 == r;
    } else {
        t = (t + d) % 4;
        return t != r;
    }
}

struct Sta {
    int x, y, t;
    void see() {
        printf("%d %d %d = %d\n", x, y, t, f[x][y][t]);
    }
};

int d[][2] = { -1, 0, 0, 1, 1, 0, 0, -1}; //URDL
bool in[N][N][4];
int bfs() {
    queue<Sta> q; q.push({sx, sy, 0});
    memset(f, -1, sizeof f);
    f[sx][sy][0] = 0;
    while(q.size()) {
        auto u = q.front(); q.pop();
        if(u.x == gx && u.y == gy) return f[u.x][u.y][u.t];

        //button
        Sta v = u;
        v.t = (v.t + 1) % 4;
        if(f[v.x][v.y][v.t] == -1) {
            f[v.x][v.y][v.t] = f[u.x][u.y][u.t] + 1;
            q.push(v);
        }

        //go
        for(int i = 0; i < 4; ++i) {
            Sta v = u;
            v.x += d[i][0]; v.y += d[i][1];
            if(!s[v.x][v.y] || s[v.x][v.y] == '*') continue;

            if(f[v.x][v.y][v.t] == -1) {
                if(s[u.x][u.y] != '+' && !check(s[u.x][u.y], v.t, i)) continue;
                if(s[v.x][v.y] != '+' && !check(s[v.x][v.y], v.t, (i + 2) % 4)) continue;
                f[v.x][v.y][v.t] = f[u.x][u.y][u.t] + 1;
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

    while(scanf("%d%d", &n, &m) == 2) {
        memset(s, 0, sizeof s);
        for(int i = 1; i <= n; ++i) scanf("%s", s[i] + 1);
        scanf("%d%d%d%d", &sx, &sy, &gx, &gy);
        printf("%d\n", bfs());
    }

#ifdef LOCAL
    printf("\nTime cost: %.2fs\n", 1.0 * (clock() - _) / CLOCKS_PER_SEC);
#endif
    return 0;
}
