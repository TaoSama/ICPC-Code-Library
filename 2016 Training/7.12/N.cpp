//
//  Created by TaoSama on 2016-07-12
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
char s[N][N];
vector<int> G[N * N];
const char* dima = "DIMA";
int d[][2] = { -1, 0, 0, -1, 1, 0, 0, 1};

int ID(int x, int y) {
    return (x - 1) * m + y;
}

int get(int id, int& x, int& y) {
    x = (id - 1) / m + 1;
    y = (id - 1) % m + 1;
}

int f[N * N];

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
        vector<int> in(N * N, 0);
        for(int i = 1; i <= n * m; ++i) G[i].clear();
        for(int i = 1; i <= n; ++i) {
            for(int j = 1; j <= m; ++j) {
                int c = s[i][j], a = strchr(dima, c) - dima;
                for(int k = 0; k < 4; ++k) {
                    int x = i + d[k][0], y = j + d[k][1];
                    if(!s[x][y]) continue;

                    int nc = s[x][y], b = strchr(dima, nc) - dima;
                    if((a + 1) % 4 != b) continue;
//                    printf("(%d, %d) -> (%d, %d)\n", i, j, x, y);
                    G[ID(i, j)].push_back(ID(x, y));
                    ++in[ID(x, y)];
                }
            }
        }

        queue<int> q;
        for(int i = 1; i <= n * m; ++i) if(!in[i]) q.push(i);
        vector<int> topo;
        while(q.size()) {
            int u = q.front(); q.pop();
            topo.push_back(u);
            for(int i = 0; i < G[u].size(); ++i) {
                int v = G[u][i];
                if(--in[v] == 0) q.push(v);
            }
        }

        if(topo.size() != n * m) {
            puts("Poor Inna!");
            continue;
        }

        int ans = 0;
        memset(f, -1, sizeof f);
        for(int i = 0; i < topo.size(); ++i) {
            int u = topo[i];
            if(f[u] == -1) {
                int x, y; get(u, x, y);
                if(s[x][y] == 'D') f[u] = 0;
                else continue;
            }
            for(int i = 0; i < G[u].size(); ++i) {
                int v = G[u][i];
                f[v] = f[u];
                int x, y; get(v, x, y);
                if(s[x][y] == 'A') ++f[v];
            }
            ans = max(ans, f[u]);
        }
        if(!ans) puts("Poor Dima!");
        else printf("%d\n", ans);
    }

#ifdef LOCAL
    printf("\nTime cost: %.2fs\n", 1.0 * (clock() - _) / CLOCKS_PER_SEC);
#endif
    return 0;
}
