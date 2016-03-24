//
//  Created by TaoSama on 2015-08-16
//  Copyright (c) 2015 TaoSama. All rights reserved.
//
//#pragma comment(linker, "/STACK:1024000000,1024000000")
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
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, q, x[1005], y[1005], c[10];

struct Edge {
    int u, v, c;
    bool operator< (const Edge& rhs) const {
        return c < rhs.c;
    }
};
vector<Edge> G;
vector<int> sub[10];

int p[1005];
int find(int x) {
    return p[x] == x ? x : p[x] = find(p[x]);
}

int kruskal(int cnt, vector<Edge>& need, bool get) {
    if(cnt == n - 1) return 0;

    int ret = 0;
    vector<Edge>& cur = get ? G : need;
    for(int i = 0; i < cur.size(); ++i) {
        Edge &e = cur[i];
        int u = find(e.u), v = find(e.v);
        if(u != v) {
            p[u] = v;
            ret += e.c;
            if(get) need.push_back(e);
            if(++cnt == n - 1) break;
        }
    }
    return ret;
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int t; scanf("%d", &t);
    while(t--) {
        scanf("%d%d", &n, &q);
        for(int i = 0; i < q; ++i) {
            sub[i].clear();
            int k; scanf("%d%d", &k, c + i);
            while(k--) {
                int x; scanf("%d", &x);
                sub[i].push_back(x);
            }
        }

        G.clear();
        for(int i = 1; i <= n; ++i) scanf("%d%d", x + i, y + i);
        for(int i = 1; i <= n; ++i) {
            for(int j = i + 1; j <= n; ++j) {
                int c = (x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]);
                G.push_back((Edge) {i, j, c});
            }
        }
        sort(G.begin(), G.end());

        vector<Edge> need;
        for(int i = 1; i <= n; ++i) p[i] = i;
        int ans = kruskal(0, need, true);

        for(int s = 0; s < 1 << q; ++s) {
            for(int i = 1; i <= n; ++i) p[i] = i;
            int cnt = 0, cost = 0;
            for(int i = 0; i < q; ++i) {
                if(s >> i & 1) {
                    cost += c[i];
                    for(int j = 1; j < sub[i].size(); ++j) {
                        int u = find(sub[i][0]), v = find(sub[i][j]);
                        if(u != v) {
                            p[v] = u;
                            ++cnt;
                        }
                    }
                }
            }
            ans = min(ans, cost + kruskal(cnt, need, false));
        }
        printf("%d\n", ans);
        if(t) puts("");
    }
    return 0;
}
