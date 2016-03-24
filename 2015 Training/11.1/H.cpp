//
//  Created by TaoSama on 2015-11-04
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
    int v, nxt;
    double c;
};
vector<Edge> edge;

int head[N];
void add_edge(int u, int v, double c) {
    edge.push_back((Edge) {v, head[u], c});
    head[u] = edge.size() - 1;
}

double dp[N];
int in[N], cnt[N];
bool spfa() {
    queue<int> q;
    for(int i = 1; i <= n; ++i) {
        dp[i] = 0;
        in[i] = cnt[i] = 1;
        q.push(i);
    }
    while(q.size()) {
        int u = q.front(); q.pop();
        in[u] = false;
        for(int i = head[u]; ~i; i = edge[i].nxt) {
            int v = edge[i].v;
            if(dp[v] > dp[u] + edge[i].c) {
                dp[v] = dp[u] + edge[i].c;
                if(!in[v]) {
                    in[v] = true;
                    q.push(v);
                    if(++cnt[v] > n) return true;
                }
            }
        }
    }
    return false;
}

bool check(double x) {
    for(auto &e : edge) e.c -= x;
    bool ret = spfa();
    for(auto &e : edge) e.c += x;
    return ret;
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int t; scanf("%d", &t);
    int kase = 0;
    while(t--) {
        scanf("%d%d", &n, &m);
        edge.clear(); memset(head, -1, sizeof head);
        double l = 1e18, r = -1e18;
        for(int i = 1; i <= m; ++i) {
            int u, v; double c; scanf("%d%d%lf", &u, &v, &c);
            add_edge(u, v, c);
            l = min(l, c);
            r = max(r, c);
        }
        double maxv = (r += 5);
        for(int i = 1; i <= 100; ++i) {
            double mid = (l + r) / 2;
            if(check(mid)) r = mid;
            else l = mid;
        }
        if(l == maxv) printf("Case #%d: No cycle found.\n", ++kase);
        else printf("Case #%d: %.2f\n", ++kase, l);
    }
    return 0;
}
