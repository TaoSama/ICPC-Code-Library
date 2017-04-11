//
//  Created by TaoSama on 2017-01-15
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
const int N = 1e2 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;
const int K = 5e3 + 10;

int n, m, k, S[K], D[K];
vector<pair<int, int> > G[N];
int f[N][K][4], in[N][K][4]; //0 cur, 1 nxt

struct Sta {
    int d, p, x, s;
    bool operator<(const Sta& s) const {
        return d > s.d;
    }
};

pair<pair<int, int>, int> pre[N][K][4];

void spfa() {
    priority_queue<Sta> q; q.push({0, 0, 0, 0});
    memset(f, 0x3f, sizeof f);
    memset(in, 0, sizeof in);
    f[0][0][0] = 0;
    pre[0][0][0] = {{ -1, -1}, -1};

    while(q.size()) {
        auto p = q.top(); q.pop();
        int d = p.d, u = p.p, x = p.x, s = p.s;
        if(in[u][x][s]) continue;
        in[u][x][s] = true;

        for(auto& e : G[u]) {
            int v, c; tie(v, c) = e;
            int nx = x, ns = s;

            //arrive at destination
            for(int i = 0; i < 2; ++i) {
                if(nx + 1 <= k && (ns >> 0 & 1) && v == D[nx + 1]) {
                    ++nx;
                    ns >>= 1;
                }
            }

            //get cur
            if(nx + 1 <= k && v == S[nx + 1]) ns |= 1 << 0;
            //get nxt
            if((ns >> 0 & 1) && nx + 2 <= k && v == S[nx + 2]) ns |= 1 << 1;

            //update
            if(!in[v][nx][ns] && f[v][nx][ns] > f[u][x][s] + c) {
                f[v][nx][ns] = f[u][x][s] + c;
                pre[v][nx][ns] = {{u, x}, s};
                q.push({f[v][nx][ns], v, nx, ns});
            }
        }
    }
}
void dfs(int u, int x, int s) {
    if(u == -1) return;
    int v, nx; tie(v, nx) = pre[u][x][s].first;
    int ns = pre[u][x][s].second;
    dfs(v, nx, ns);
//  printf("%d,", u);
//  printf("f[%d][%d][%d] = %d\n", u, x, s, f[u][x][s]);
}

int main() {
#ifdef LOCAL
    freopen("manic_moving.txt", "r", stdin);
    freopen("manic_moving_out.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);

//  int path[] = {0,1,4,3,7,5,2,1,2,5,7,3,4,1,4,3,7,5,2,1,4,2,5,7,5,2,1};
//  int g[N][N] = {};
//  memset(g, 0x3f, sizeof g);

    int t; scanf("%d", &t);
    while(t--) {
        scanf("%d%d%d", &n, &m, &k);
        for(int i = 0; i <= n; ++i) G[i].clear();
        G[0].push_back({1, 0});
        for(int i = 1; i <= m; ++i) {
            int u, v, c; scanf("%d%d%d", &u, &v, &c);
            G[u].push_back({v, c});
            G[v].push_back({u, c});
//            g[u][v] = min(g[u][v], c);
//            g[v][u] = min(g[v][u], c);
        }
        for(int i = 1; i <= k; ++i) scanf("%d%d", S + i, D + i);

//        int sum = 0;
//        g[0][1] = 0;
//        for(int i = 1; i < sizeof(path) / 4; ++i) {
//          printf("path[%d][%d] = %d\n", path[i-1], path[i], g[path[i-1]][path[i]]);
//          sum += g[path[i-1]][path[i]];
//        }
//        prln(sum);

//		prln(1);
        spfa();
//        prln(2);

//        dfs(D[k], k, 0);
//        prln(f[2][0][1]);
//        prln(f[3][0][3]);
//        prln(f[1][1][0]);
//        prln(f[2][1][0]);
//        prln(f[3][1][3]);
//        prln(f[2][2][1]);
//        prln(f[1][3][0]);

        static int kase = 0;
        int ans = f[D[k]][k][0];
        if(ans == INF) ans = -1;
        printf("Case #%d: %d\n", ++kase, ans);
//        return 0;
    }

    return 0;
}
