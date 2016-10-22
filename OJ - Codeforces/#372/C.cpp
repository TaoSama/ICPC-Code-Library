//
//  Created by TaoSama on 2016-10-01
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

struct Edge {
    int v, nxt, c;
} edge[N << 1];
int head[N], cnt;

void addEdge(int u, int v, int c) {
    edge[cnt] = (Edge) {v, head[u], c};
    head[u] = cnt++;
}

bool vis[N];
int sz[N], mx[N], centroid;

int getAll(int u, int f) {
    int ret = 1;
    for(int i = head[u]; ~i; i = edge[i].nxt) {
        int v = edge[i].v;
        if(v == f || vis[v]) continue;
        ret += getAll(v, u);
    }
    return ret;
}

void getCentroid(int u, int f, int all) {
    sz[u] = 1; mx[u] = 0;
    for(int i = head[u]; ~i; i = edge[i].nxt) {
        int v = edge[i].v;
        if(v == f || vis[v]) continue;
        getCentroid(v, u, all);
        sz[u] += sz[v];
        mx[u] = max(mx[u], sz[v]);
    }
    mx[u] = max(mx[u], all - sz[u]);
    if(!centroid || mx[u] < mx[centroid]) centroid = u;
}

typedef long long LL;
typedef pair<LL, LL> P; //down, up
map<LL, int> mp;
LL pow10[N], inv10[N];

int n, M;
LL ans;

LL exgcd(LL a, LL b, LL& x, LL& y) {
    LL d = a;
    if(!b) x = 1, y = 0;
    else {
        d = exgcd(b, a % b, y, x);
        y -= (a / b) * x;
    }
    return d;
}

LL inv(LL a, LL m) {
    LL x, y; exgcd(a, m, x, y);
    return (x % m + m) % m;
}

void getDs(int u, int f, int dis, LL dw, LL up,
           vector<pair<P, int> >& ds) {
//    pr(dw); pr(up); prln(dis);
    ds.push_back({{dw, up}, dis});
    for(int i = head[u]; ~i; i = edge[i].nxt) {
        int v = edge[i].v;
        if(v == f || vis[v]) continue;
        getDs(v, u, dis + 1, (dw * 10 + edge[i].c) % M,
              (up + edge[i].c * pow10[dis]) % M, ds);
    }
}


LL calc(vector<pair<P, int> >& ds, bool zero) {
    LL ret = 0;
    mp.clear();
    for(auto& p : ds) {
        LL up = p.first.second;
        ++mp[up];
    }
    if(zero) ret += mp[0];
    for(auto& p : ds) {
        LL up, dw; int d = p.second; tie(dw, up) = p.first;
        if(zero && dw == 0) ++ret;
        LL need = (M - dw) * inv10[d] % M;
        ret += mp[need];
        if(up == need) --ret;
    }
    return ret;
}

void solve(int u) {
    centroid = 0;
    getCentroid(u, -1, getAll(u, -1));

    int s = centroid;
    vis[s] = true;

    for(int i = head[s]; ~i; i = edge[i].nxt) {
        int v = edge[i].v;
        if(vis[v]) continue;
        solve(v);
    }

    vector<pair<P, int> > ds;
    for(int i = head[s]; ~i; i = edge[i].nxt) {
        int v = edge[i].v;
        if(vis[v]) continue;

        vector<pair<P, int> > tds;
        getDs(v, s, 1, edge[i].c % M, edge[i].c % M, tds);

        ans -= calc(tds, false);
        ds.insert(ds.end(), tds.begin(), tds.end());
    }

    ans += calc(ds, true);
    vis[s] = false;
}


int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
//    ios_base::sync_with_stdio(0);


    while(scanf("%d%d", &n, &M) == 2) {
        cnt = 0; memset(head, -1, sizeof head);
        for(int i = 1; i < n; ++i) {
            int u, v, c; scanf("%d%d%d", &u, &v, &c);
            ++u; ++v;
            addEdge(u, v, c);
            addEdge(v, u, c);
        }

        LL invTen = inv(10, M);
        pow10[0] = inv10[0] = 1;
        for(int i = 1; i <= n; ++i) {
            pow10[i] = pow10[i - 1] * 10 % M;
            inv10[i] = inv10[i - 1] * invTen % M;
        }

        ans = 0;
        solve(1);
        printf("%I64d\n", ans);
    }

    return 0;
}
