//
//  Created by TaoSama on 2016-03-31
//  Copyright (c) 2016 TaoSama. All rights reserved.
//
#pragma comment(linker, "/STACK:102400000,102400000")
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
const int N = 1e3 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, m;
int a[N][N], b[N][N];
typedef long long LL;
LL k;

struct DSU {
    int n, p[N * N], sz[N * N];
    void init(int _n) {
        n = _n;
        for(int i = 1; i <= n; ++i) p[i] = i, sz[i] = 1;
    }
    int find(int x) {return p[x] = p[x] == x ? x : find(p[x]);}
    void unite(int x, int y) {
        x = find(x), y = find(y);
        if(x == y) return;
        if(sz[x] > sz[y]) swap(x, y);
        p[x] = y;
        sz[y] += sz[x]; sz[x] = 0;
    }
    int size(int x) {
        x = find(x);
        return sz[x];
    }
} dsu;

int get(int i, int j) {
    return (i - 1) * m + j;
}

int vis[N][N];
int d[][2] = { -1, 0, 0, -1, 1, 0, 0, 1};
typedef pair<int, int> P;

void extend(int i, int j) {
    LL val = a[i][j], cur = get(i, j);

    queue<P> q; q.push({i, j});
    vis[i][j] = true;
    while(q.size()) {
        P u = q.front(); q.pop();
        for(int i = 0; i < 4; ++i) {
            P v = u;
            v.first += d[i][0];
            v.second += d[i][1];
            if(a[v.first][v.second] >= val) dsu.unite(cur, get(v.first, v.second));

            if(vis[v.first][v.second] || a[v.first][v.second] < val) continue;
            vis[v.first][v.second] = true;

            q.push(v);
        }
    }
}

bool solve(int i, int j) {
    LL val = a[i][j], need = k / val;
    if(dsu.size(get(i, j)) < need) return false;

    memset(vis, 0, sizeof vis);
    queue<P> q; q.push({i, j});
    vis[i][j] = true;

    LL cnt = 0;
    while(q.size()) {
        P u = q.front(); q.pop();
        a[u.first][u.second] = -1;
        if(++cnt == need) break;

        for(int i = 0; i < 4; ++i) {
            P v = u;
            v.first += d[i][0];
            v.second += d[i][1];

            if(vis[v.first][v.second] || a[v.first][v.second] < val) continue;
            vis[v.first][v.second] = true;

            q.push(v);
        }
    }
    return true;
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    scanf("%d%d%I64d", &n, &m, &k);
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j)
            scanf("%d", a[i] + j);

    vector<pair<int, P> > divisors;
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j)
            if(k % a[i][j] == 0)
                divisors.push_back({ -a[i][j], {i, j}});
    sort(divisors.begin(), divisors.end());

    dsu.init(n * m);
    int ans = -1;
    for(auto p : divisors) {
        int i = p.second.first, j = p.second.second;
        extend(i, j);
        if(solve(i, j)) ans = -p.first;
        if(~ans) break;
    }

    if(~ans) {
        puts("YES");
        for(int i = 1; i <= n; ++i) {
            for(int j = 1; j <= m; ++j) {
                if(a[i][j] == -1) printf("%d%c", ans, " \n"[j == m]);
                else printf("%d%c", 0, " \n"[j == m]);
            }
        }
    } else puts("NO");

    return 0;
}
