#include <bits/stdc++.h>
using namespace std;
#define pr(x)   cout << #x << " = " << x << " "
#define prln(x) cout << #x << " = " << x << endl
const int N = 2e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, m, q;
struct Edge {
    int u, v, c;
    void read() {
        scanf("%d%d%d", &u, &v, &c);
    }
    bool operator<(const Edge& e) const {
        return c < e.c;
    }
} edges[N];

vector<Edge> G[N];

int par[N];
int find(int x) {
    return par[x] = par[x] == x ? x : find(par[x]);
}

void kruskal() {
    sort(edges + 1, edges + 1 + m);
    for(int i = 1; i <= n; ++i) par[i] = i;
    int cnt = 0;
    for(int i = 1; i <= m; ++i) {
        int u = edges[i].u, v = edges[i].v;
        u = find(u); v = find(v);
        if(u != v) {
            par[u] = v;
            G[edges[i].u].push_back({edges[i].u, edges[i].v, edges[i].c});
            G[edges[i].v].push_back({edges[i].v, edges[i].u, edges[i].c});
//            pr(edges[i].u); prln(edges[i].v);
            if(++cnt == n - 1) break;
        }
    }
}

const int LOG = 18;
int dep[N], p[LOG][N], maxv[LOG][N];
void dfs(int u, int fa, int c) {
    p[0][u] = fa;
    maxv[0][u] = c;
    dep[u] = dep[fa] + 1;
//    pr(u); prln(c);
    for(int i = 1; i < LOG; ++i) {
        p[i][u] = p[i - 1][p[i - 1][u]];
        maxv[i][u] = max(maxv[i - 1][u], maxv[i - 1][p[i - 1][u]]);
    }
    for(Edge& e : G[u]) {
        int v = e.v, c = e.c;
        if(v == fa) continue;
        dfs(v, u, c);
    }
}

int solve(int u, int v) {
    if(dep[u] > dep[v]) swap(u, v);
    int ans = -INF;
//    pr(u); prln(v);
//    prln(dep[v] - dep[u]);
//    prln(maxv[0][5]);
//    prln(p[0][5]);
//    prln(maxv[0][3]);
//    prln(maxv[1][5]);
    for(int i = 0; i < LOG; ++i)
        if(dep[v] - dep[u] >> i & 1)
            ans = max(ans, maxv[i][v]), v = p[i][v];
//    pr(u); prln(v);
//    prln(ans);
    if(u == v) return ans;
//    prln(ans);
    for(int i = LOG - 1; ~i; --i) {
        if(p[i][u] != p[i][v]) {
            u = p[i][u], v = p[i][v];
            ans = max(ans, maxv[i][u]);
            ans = max(ans, maxv[i][v]);
        }
    }
    ans = max(ans, maxv[0][u]);
    return ans;
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\luwt\\Desktop\\in.txt", "r", stdin);
#endif // LOCAL
    ios_base::sync_with_stdio(false);


    int t; scanf("%d", &t);
    while(t--) {
        scanf("%d%d%d", &n, &m, &q);
        for(int i = 1; i <= n; ++i) G[i].clear();
        for(int i = 1; i <= m; ++i) edges[i].read();

        kruskal();
        dfs(1, 0, -INF);
        while(q--) {
            int u, v; scanf("%d%d", &u, &v);
            printf("%d\n", solve(u, v));
        }
    }
    return 0;
}
