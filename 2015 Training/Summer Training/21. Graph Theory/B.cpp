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

int n, m;
struct Edge {
    int u, v, c;
    bool operator< (const Edge& rhs) const {
        return c < rhs.c;
    }
};
vector<Edge> G;

int p[105];
int find(int x) {
    return p[x] == x ? x : p[x] = find(p[x]);
}

int kruskal() {
    int ans = INF;
    sort(G.begin(), G.end());
    for(int L = 0; L < m; ++L) {
        for(int i = 1; i <= n; ++i) p[i] = i;
        int cnt = 0;
        for(int R = L; R < m; ++R) {
            Edge &e = G[R];
            int u = find(e.u), v = find(e.v);
            if(u != v) {
                p[u] = v;
                if(++cnt == n - 1) {
                    ans = min(ans, G[R].c - G[L].c);
                    break;
                }
            }
        }
    }
    return ans == INF ? -1 : ans;
}


int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d%d", &n, &m) == 2 && (n || m)) {
        G.clear();
        for(int i = 1; i <= m; ++i) {
            int u, v, c; scanf("%d%d%d", &u, &v, &c);
            G.push_back((Edge) {u, v, c});
        }
        int ans = kruskal();
        printf("%d\n", ans);
    }
    return 0;
}
