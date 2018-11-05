
//  Created by TaoSama.
//  Copyright (c) 2017 TaoSama. All rights reserved.
//
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

typedef long long LL;
struct BIT {
    int n;
    LL b[N];

    void init(int _n) {
        n = _n;
        memset(b, 0, sizeof b);
    }
    void add(int i, int v) {
        for(; i <= n; i += i & -i) b[i] += v;
    }
    LL sum(int i) {
        LL ret = 0;
        for(; i; i -= i & -i) ret += b[i];
        return ret;
    }
    LL query(int l, int r) {
        return sum(r) - sum(l - 1);
    }
} bit;
struct Edge {
    int to, nxt;
};

struct HLD {
    int head[N], cnt, tid;
    int sz[N], son[N], fa[N], dep[N], top[N], dfn[N];
    Edge edge[N << 1];

    void init() {
        cnt = tid = 0;
        memset(head, -1, sizeof head);
        memset(son, 0, sizeof son);
    }

    void add_edge(int u, int v) {
        edge[cnt] = (Edge) {v, head[u]};
        head[u] = cnt++;
        edge[cnt] = (Edge) {u, head[v]};
        head[v] = cnt++;
    }
    //find heavy edge
    void dfs1(int u, int f, int d) {
        sz[u] = 1, fa[u] = f, dep[u] = d;
        for(int i = head[u]; ~i; i = edge[i].nxt) {
            int v = edge[i].to;
            if(v == f) continue;
            dfs1(v, u, d + 1);
            if(!son[u] || sz[v] > sz[son[u]]) son[u] = v;
            sz[u] += sz[v];
        }
    }
    //connect heavy edge
    void dfs2(int u, int tp) {
        dfn[u] = ++tid;
        // printf("%d %d\n", u, dfn[u]);
        top[u] = tp;
        if(son[u]) dfs2(son[u], tp);
        for(int i = head[u]; ~i; i = edge[i].nxt) {
            int v = edge[i].to;
            if(v == fa[u] || v == son[u]) continue;
            dfs2(v, v);
        }
    }

    LL query(int u, int v) {
        LL ret = 0;
        int fu = top[u], fv = top[v];
        while(fu != fv) {
            if(dep[fu] < dep[fv]) {
                swap(u, v);
                swap(fu, fv);
            }
            ret = ret + bit.query(dfn[fu], dfn[u]);
            u = fa[fu], fu = top[u];
        }
        if(dep[u] > dep[v]) swap(u, v);
        ret += bit.query(dfn[u], dfn[v]);
        return ret;
    }
    void update(int u, int c) {
        // printf("bit add %d %d\n", u, dfn[u]);
        bit.add(dfn[u], c);
    }

    void build() {
        dfs1(1, -1, 0);
        dfs2(1, 1);
    }
} hld;

int n, m;
int c[N];
vector<int> G[N];
struct Query {
    int u, v;
    int s[2];
    LL ans[2];
    void read() {
        scanf("%d%d%d%d", &u, &v, s, s + 1);
    }
} qs[N];

int main(){
#ifdef LOCAL
    freopen("/Users/didi/ACM/in.txt", "r", stdin);
//  freopen("/Users/didi/ACM/out.txt", "w", stdout);
#endif
    ios::sync_with_stdio(0); cin.tie(0);
    
    while(scanf("%d%d", &n, &m) == 2) {
        vector<pair<int, int>> toAdd; toAdd.reserve(n);
        vector<pair<int, pair<int,int>>> toQuery; toQuery.reserve(2 * n);

        bit.init(n);
        hld.init();
        for(int i = 1; i <= n; ++i) {
            scanf("%d", c + i);
            toAdd.push_back({c[i], i}); 
        }
        for(int i = 1; i < n; ++i) {
            int u, v; scanf("%d%d", &u, &v);
            hld.add_edge(u, v);
        }
        hld.build();
        // for(int i = 1; i <= n; ++i) printf("dfn[%d] = %d\n", i, hld.dfn[i]);
        // puts("built");
         
        for(int i = 1; i <= m; ++i) {
            qs[i].read();
            toQuery.push_back({qs[i].s[0] - 1, {i, 0}});
            toQuery.push_back({qs[i].s[1], {i, 1}});
        }

        sort(toAdd.begin(), toAdd.end());
        sort(toQuery.begin(), toQuery.end());

        size_t idx = 0;
        for(const auto& q : toQuery) {
            int c = q.first, a, b;
            tie(a, b) = q.second;
            while(idx < toAdd.size() && toAdd[idx].first <= c) {
                // printf("add %d %d\n", toAdd[idx].second, toAdd[idx].first);
                hld.update(toAdd[idx].second, toAdd[idx].first);
                idx++;
            }
            qs[a].ans[b] = hld.query(qs[a].u, qs[a].v);
            // printf("%d %d q: %d %lld\n", a, b, qs[a].s[b], qs[a].ans[b]);
        }
        // printf("%lld\n", hld.query(3, 3));
        // printf("%lld\n", hld.query(1, 1));
        

        for(int i = 1; i <= m; ++i) printf("%lld%c", qs[i].ans[1] - qs[i].ans[0], " \n"[i == m]);
    } 
    return 0;
}
