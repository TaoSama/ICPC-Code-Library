//
//  Created by TaoSama on 2017-06-10
//  Copyright (c) 2017 TaoSama. All rights reserved.
//
#pragma comment(linker, "/STACK:102400000,102400000")
#include <bits/stdc++.h>

using namespace std;
#define pr(x) cerr << #x << " = " << x << "  "
#define prln(x) cerr << #x << " = " << x << endl
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, m, m1, m2;
vector<int> cities[N];
vector<pair<int, int> > G[N];
long long d[N];
bool in[N];

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    scanf("%d%d", &n, &m);
    for(int i = 1; i <= m; ++i) {
        int k; scanf("%d", &k);
        cities[i].resize(k);
        for(int& x : cities[i]) {
            scanf("%d", &x);
            G[n + i].push_back({x, 0});
            G[x].push_back({2 * n + i, 0});
        }
    }
    scanf("%d", &m1);
    for(int i = 1; i <= m1; ++i) {
        int u, v, c; scanf("%d%d%d", &u, &v, &c);
        G[u].push_back({v, c});
        G[v].push_back({u, c});
    }

    scanf("%d", &m2);
    for(int i = 1; i <= m2; ++i) {
        int u, v, c; scanf("%d%d%d", &u, &v, &c);
        G[2 * n + u].push_back({n + v, c});
        G[2 * n + v].push_back({n + u, c});
    }

    int s, t; scanf("%d%d", &s, &t);
    memset(d, 0x3f, sizeof d);
//  pr(s); prln(t);
//prln(d[t]);
    d[s] = 0; in[s] = 1;
    queue<int> q;
    q.push(s);
    while(q.size()) {
        int u = q.front(); q.pop();
        in[u] = 0;
        for(auto& e : G[u]) {
            int v, c; tie(v, c) = e;
            if(d[v] > d[u] + c) {
                d[v] = d[u] + c;
//              printf("%d + %d -> %d\n", u, c, v);
                if(!in[v]) {
                    in[v] = 1;
                    q.push(v);
                }
            }
        }
    }
//  for(int i = 1; i <= n; ++i)
//      pr(i), prln(d[i]);
    long long ans = d[t];
    if(ans > 1e12) ans = -1;
    printf("%lld\n", ans);

    return 0;
}
