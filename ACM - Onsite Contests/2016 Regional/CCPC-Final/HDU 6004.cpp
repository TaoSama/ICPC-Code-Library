//
//  Created by TaoSama on 2016-12-04
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
const int N = 200 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

typedef long long LL;

LL exgcd(LL a, LL b, LL& x, LL& y) {
    LL d = a;
    if(!b) x = 1, y = 0;
    else {
        d = exgcd(b, a % b, y, x);
        y -= (a / b) * x;
    }
    return d;
}

// O(1)
LL mul(LL x, LL y, LL mod) {
    return (x * y - (LL)(x / (long double) mod * y + 1e-3) * mod + mod) % mod;
}

pair<LL, LL> excrt(initializer_list<pair<LL, LL> > v) {
    LL B = 0, M = 1;
    for(auto& key : v) {
        LL b = key.first, m = key.second;
        if(b == -1) return { -1, -1};
        LL A = (M * 1) % m, c = (b - B * 1) % m;
        LL x, y, g = exgcd(A, m, x, y);
        if(c % g) return { -1, -1};
        x = mul(c / g, x, (m / g));
        B += x * M;
        M *= m / g;
        B %= M;
    }
    B = (B + M) % M;
    return {B, M};
}

struct SparseTable2D {
    static const int LOG = 10;
    int n, m, LOG2[N];
    pair<LL, LL> f[LOG][LOG][N][N];
    void init(int _n, int _m, pair<LL, LL> (*a)[N]) {
        n = _n, m = _m;
        LOG2[1] = 0;
        for(int i = 2; i < N; ++i) LOG2[i] = LOG2[i >> 1] + 1;
        for(int x = 0; x < LOG; ++x) {
            for(int y = 0; y < LOG; ++y) {
                for(int i = 1; i + (1 << x) - 1 <= n; ++i) {
                    for(int j = 1; j + (1 << y) - 1 <= m; ++j) {
                        if(x + y == 0) f[x][y][i][j] = a[i][j];
                        else if(x == 0)
                            f[x][y][i][j] = excrt({f[x][y - 1][i][j], f[x][y - 1][i][j + (1 << y -  1)]});
                        else if(y == 0)
                            f[x][y][i][j] = excrt({f[x - 1][y][i][j], f[x - 1][y][i + (1 << x - 1)][j]});
                        else
                            f[x][y][i][j] = excrt({f[x - 1][y - 1][i + (1 << x - 1)][j],
                                                   f[x - 1][y - 1][i][j + (1 << y - 1)],
                                                   f[x - 1][y - 1][i][j],
                                                   f[x - 1][y - 1][i + (1 << x - 1)][j + (1 << y - 1)]
                                                  });
                    }
                }
            }
        }
    }
    pair<LL, LL> RMQ(int x1, int y1, int x2, int y2) {
        int k1 = LOG2[x2 - x1 + 1], k2 = LOG2[y2 - y1 + 1];
        return excrt({f[k1][k2][x1][y1],
                      f[k1][k2][x2 - (1 << k1) + 1][y2 - (1 << k2) + 1],
                      f[k1][k2][x1][y2 - (1 << k2) + 1],
                      f[k1][k2][x2 - (1 << k1) + 1][y1]
                     });
    }
} st;

int n, m;
pair<LL, LL> a[N][N];

struct FastIO {
    static const int S = 4 << 20; //MB
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
    inline void wint(LL x) {
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

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);


    int t = io.xint();
    while(t--) {
        n = io.xint(); m = io.xint();
        for(int i = 1; i <= n; ++i)
            for(int j = 1; j <= m; ++j)
                a[i][j].first = io.xint();
        for(int i = 1; i <= n; ++i)
            for(int j = 1; j <= m; ++j)
                a[i][j].second = io.xint();

        st.init(n, m, a);

        static int kase = 0;
        io.wstring("Case #"); io.wint(++kase);
        io.wstring(":\n");

        int q = io.xint();
        while(q--) {
            int x1 = io.xint(), y1 = io.xint(), x2 = io.xint(), y2 = io.xint();
            io.wint(st.RMQ(x1, y1, x2, y2).first);
            io.wchar('\n');
        }
    }
    return 0;
}
