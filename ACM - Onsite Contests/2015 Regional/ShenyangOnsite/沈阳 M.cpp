//
//  Created by TaoSama on 2015-10-31
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
const int M = 1e6 + 10;

typedef long long LL;

int n, m;

int head[M + N], cnt;
struct Edge {
    int v, nxt, c;
} edges[(M + N) << 1];

bool add_edge(int u, int v, int c) {
    edges[cnt] = (Edge) {v, head[u], c};
    head[u] = cnt++;
}

LL dp[2][M + N];
bool done[M + N];

typedef pair<LL, int> P;
void dijkstra(int s, int k) {
    priority_queue<P, vector<P>, greater<P> > q;
    memset(dp[k], 0x3f, sizeof dp[k]);
    memset(done, false, sizeof done);
    dp[k][s] = 0; q.push(P(0, s));
    while(q.size()) {
        int u = q.top().second; q.pop();
        done[u] = true;
        for(int i = head[u]; ~i; i = edges[i].nxt) {
            int v = edges[i].v, c = edges[i].c;
            if(!done[v] && dp[k][v] > dp[k][u] + c) {
                dp[k][v] = dp[k][u] + c;
                q.push(P(dp[k][v], v));
            }
        }
    }
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
        cnt = 0; memset(head, -1, sizeof head);
        for(int i = 1; i <= m; ++i) {
            int w, k; scanf("%d%d", &w, &k);
            for(int j = 1; j <= k; ++j) {
                int x; scanf("%d", &x);
                add_edge(n + i, x, w);
                add_edge(x, n + i, 0);
            }
        }
        dijkstra(1, 0);
        dijkstra(n, 1);
        LL minv = 1e18;
        for(int i = 1; i <= n; ++i)
            minv = min(minv, max(dp[0][i], dp[1][i]));
        vector<int> ans;
        for(int i = 1; i <= n; ++i)
            if(minv == max(dp[0][i], dp[1][i])) ans.push_back(i);

        if(minv == 1e18) printf("Case #%d: Evil John\n", ++kase);
        else {
            printf("Case #%d: %I64d\n", ++kase, minv);
            for(int i = 0; i < ans.size(); ++i)
                printf("%d%c", ans[i], " \n"[i == ans.size() - 1]);
        }
    }
    return 0;
}
