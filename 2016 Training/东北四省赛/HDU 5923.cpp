//
//  Created by TaoSama on 2016-10-06
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
const int N = 500 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;
const int M = 1e4 + 10;

struct FastIO {
    static const int S = 10 << 20; //MB
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

int n, m;
int p[M][N], cur[N];
vector<int> G[M];
pair<int, int> e[M];

int find(int* p, int x) {
    return p[x] == x ? x : find(p, p[x]);
}

bool unite(int* p, int x, int y) {
    x = find(p, x), y = find(p, y);
    if(x == y) return false;
    p[x] = y;
    return true;
}

void dfs(int u, int f) {
    memcpy(p[u], p[f], n + 1 << 2);
    unite(p[u], e[u].first, e[u].second);
    for(int v : G[u]) dfs(v, u);
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int t; t = io.xuint();
    while(t--) {
        n = io.xuint(); m = io.xuint();
        for(int i = 1; i <= m; ++i) G[i].clear();
        for(int i = 2; i <= m; ++i) {
            int f; f = io.xuint();
            G[f].push_back(i);
        }
        for(int i = 1; i <= m; ++i) {
            e[i].first = io.xuint();
            e[i].second = io.xuint();
        }

        for(int i = 1; i <= n; ++i) p[0][i] = i;
        dfs(1, 0);

        static int kase = 0;
        io.wstring("Case #"); io.wint(++kase); io.wstring(":\n");
        int q; q = io.xuint();
        while(q--) {
            int k; k = io.xuint();
            for(int i = 1; i <= n; ++i) cur[i] = i;
            int ans = n;
            for(int i = 1; i <= k; ++i) {
                int x; x = io.xuint();
                int* par = p[x];
                for(int j = 1; j <= n; ++j)
                    ans -= unite(cur, j, par[j]);
            }
            io.wint(ans); io.wchar('\n');
        }
    }

    return 0;
}
