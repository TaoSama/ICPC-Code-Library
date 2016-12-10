//
//  Created by TaoSama on 2016-08-16
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
    int v, nxt, cap, flow;
} edge[N];
int head[N], cnt;
void add_edge(int u, int v, int c1) {
    edge[cnt] = {v, head[u], c1, 0};
    head[u] = cnt++;
    edge[cnt] = {u, head[v], 0, 0};
    head[v] = cnt++;
}
int lev[N], cur[N];
bool bfs(int s, int t) {
    queue<int>q;
    memset(lev, 0, sizeof(lev));
    q.push(s); lev[s] = 1;
    while(q.size() && !lev[t]) {
        int u = q.front(); q.pop();
        for(int i = head[u]; ~i; i = edge[i].nxt) {
            int v = edge[i].v;
            if(edge[i].cap > edge[i].flow && !lev[v]) {
                lev[v] = lev[u] + 1;
                q.push(v);
            }
        }
    }
    return lev[t];
}
int dfs(int u, int t, int delta) {
    if(u == t || !delta) return delta;
    int ret = 0;
    for(int i = cur[u]; ~i; i = edge[i].nxt) {
        int v = edge[i].v;
        if(edge[i].cap > edge[i].flow && lev[v] == lev[u] + 1) {
            int d = dfs(v, t, min(delta, edge[i].cap - edge[i].flow));
            cur[u] = i;
            ret += d; delta -= d;
            edge[i].flow += d;
            edge[i ^ 1].flow -= d;
            if(delta == 0) return ret;
        }
    }
    lev[u] = 0;
    return ret;
}
int dinic(int s, int t) {
    int ret = 0;
    while(bfs(s, t)) {
        for(int i = s; i <= t; i++) cur[i] = head[i];
        ret += dfs(s, t, INF);
    }
    return ret;
}
int n, m, L;
struct node {
    int pay, t;
} A[N];
int proi[N];
vector<int>shop[N];
pair<int, int> check(int mid) {
    memset(head, -1, sizeof(head));
    cnt = 0;
    int s = 0, t = n + m + 1;
    int sum = 0;
    for(int j = 1; j <= m; j++) {
        int ok = 1;
        for(int p : shop[j]) {
            if(A[p].t > mid) {
                ok = 0;
                break;
            }
        }
        if(ok) {
            add_edge(s, j, proi[j]);
            sum += proi[j];
            for(int p : shop[j]) {
                add_edge(j, p + m, INF);
            }
        }
    }
    for(int j = 1; j <= n; j++) {
        if(A[j].t <= mid) {
            add_edge(j + m, t, A[j].pay);
        }
    }
    int res = sum - dinic(s, t);
    if(res >= L) return {mid, res};
    else return { -1, -1};
}
int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);
    int T, cas = 1;
    scanf("%d", &T);
    while(T--) {
        scanf("%d%d%d", &n, &m, &L);
        for(int j = 1; j <= n; j++) scanf("%d%d", &A[j].pay, &A[j].t);
        for(int j = 1; j <= m; j++) {
            scanf("%d", &proi[j]);
            shop[j].clear();
            int k;
            scanf("%d", &k);
            while(k--) {
                int a;
                scanf("%d", &a);
                shop[j].push_back(a);
            }
        }
        int l = 0, r = INF;
        pair<int, int> res = { -1, -1};
        while(l <= r) {
            int mid = (l + r) >> 1;
            auto t = check(mid);
            if(t != make_pair(-1, -1)) {
                res = t;
                r = mid - 1;
            } else l = mid + 1;
        }
        printf("Case #%d: ", cas++);
        if(res == make_pair(-1, -1)) printf("impossible\n");
        else printf("%d %d\n", res.first, res.second);
    }


    return 0;
}
