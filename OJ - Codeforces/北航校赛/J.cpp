//
//  Created by TaoSama on 2016-12-18
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
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

struct FastIO {
    static const int S = 8 << 20; //MB
    int wpos; char wbuf[S];
    FastIO() : wpos(0) {}
    inline int xchar() {
        static char buf[S];
        static int len = 0, pos = 0;
        if(pos == len)
            pos = 0, len = fread(buf, 1, S, stdin);
        if(pos == len) return -1;
        return buf[pos ++];
    }
    inline int xuint() {
        int c = xchar(), x = 0;
        while(c <= 32) c = xchar();
        for(; '0' <= c && c <= '9'; c = xchar()) x = x * 10 + c - '0';
        return x;
    }
    inline int xint() {
        int s = 1, c = xchar(), x = 0;
        while(c <= 32) c = xchar();
        if(c == '-') s = -1, c = xchar();
        for(; '0' <= c && c <= '9'; c = xchar()) x = x * 10 + c - '0';
        return x * s;
    }
    inline void xstring(char* s) {
        int c = xchar();
        while(c <= 32) c = xchar();
        for(; c > 32; c = xchar()) * s++ = c;
        *s = 0;
    }
    inline void wchar(int x) {
        if(wpos == S) fwrite(wbuf, 1, S, stdout), wpos = 0;
        wbuf[wpos ++] = x;
    }
    inline void wint(int x) {
        if(x < 0) wchar('-'), x = -x;

        char s[24];
        int n = 0;
        while(x || !n) s[n ++] = '0' + x % 10, x /= 10;
        while(n--) wchar(s[n]);
    }
    inline void wstring(const char* s) {
        while(*s) wchar(*s++);
    }
    ~FastIO() {
        if(wpos) fwrite(wbuf, 1, wpos, stdout), wpos = 0;
    }
} io;


int n, m, q;
int d[][2] = { -1, 0, 0, -1, 1, 0, 0, 1};
char str[N * 10];
pair<int, int> Q[N * 10];

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int t; scanf("%d", &t);
    while(t--) {
        scanf("%d%d%d", &n, &m, &q);
        vector<string> a(n);
        for(auto& s : a) {
            scanf("%s", str);
            s = str;
        }

        int cc = 0;
        vector<int> sz(n * m + 5, 0);
        vector<vector<int> > id(n, vector<int>(m, 0));
        auto check = [&n, &m](int x, int y) {
            return x >= 0 && x < n && y >= 0 && y < m;
        };
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                if(id[i][j]) continue;
                ++cc;
                auto bfs = [&]() {
                    int sum = 0;
                    int f, g; f = g = 0;
                    Q[g++] = {i, j};
                    id[i][j] = cc;
                    while(f < g) {
                        auto u = Q[f++];
                        ++sum;
                        for(int k = 0; k < 4; ++k) {
                            auto v = u;
                            v.first += d[k][0];
                            v.second += d[k][1];
                            if(!check(v.first, v.second)) continue;
                            if(!id[v.first][v.second] && a[v.first][v.second] == a[u.first][u.second]) {
                                id[v.first][v.second] = cc;
                                Q[g++] = v;
                            }
                        }
                    }
                    return sum;
                };
                sz[cc] = bfs();
            }
        }

        while(q--) {
            int x, y; scanf("%d%d", &x, &y);
            --x; --y;
            int ans = 1;
            for(int i = 0; i < 4; ++i) {
                int nx = x + d[i][0];
                int ny = y + d[i][1];
                if(!check(nx, ny)) continue;
                int cur = 1;
                cur += sz[id[nx][ny]] - (a[x][y] == a[nx][ny]);
                int use[4] = {}, p = 0; use[p++] = id[nx][ny];
                for(int j = 0; j < 4; ++j) {
                    if(i == j) continue;
                    int tx = x + d[j][0];
                    int ty = y + d[j][1];
                    if(!check(tx, ty) || a[tx][ty] != a[nx][ny]) continue;
                    bool ok = true;
                    for(int k = 0; k < p && ok; ++k)
                        if(id[tx][ty] == use[k]) ok = false;
                    if(ok) {
                        cur += sz[id[tx][ty]] - (a[x][y] == a[tx][ty]);
                        use[p++] = id[tx][ty];
                    }
                }
                ans = max(ans, cur);
            }
            printf("%d\n", ans);
        }
    }

    return 0;
}
