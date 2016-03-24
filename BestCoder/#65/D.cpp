//
//  Created by TaoSama on 2015-12-05
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
const int N = 5e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, k, A, B;
struct Edge {
    int v, nxt;
} edge[N];
int head[N], cnt;

void addEdge(int u, int v) {
    edge[cnt] = (Edge) {v, head[u]};
    head[u] = cnt++;
}

int dp[N][15];
void dfs1(int u) {
    dp[u][0] = 1;
    for(int i = 1; i <= k; ++i) dp[u][i] = 0;
    for(int i = head[u]; ~i; i = edge[i].nxt) {
        int v = edge[i].v;
        dfs1(v);
        for(int j = 1; j <= k; ++j)
            dp[u][j] += dp[v][j - 1];
    }
}

void dfs2(int u) {
    for(int i = head[u]; ~i; i = edge[i].nxt) {
        int v = edge[i].v;
        for(int j = k; j >= 1; --j)
            dp[v][j] += dp[u][j - 1] - (j >= 2 ? dp[v][j - 2] : 0);
        dfs2(v);
    }
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int t; scanf("%d", &t);
    while(t--) {
        scanf("%d%d%d%d", &n, &k, &A, &B);
        cnt = 0; memset(head, -1, sizeof head);
        for(int i = 2; i <= n; ++i) {
            int f = (1LL * A * i + B) % (i - 1) + 1;
            addEdge(f, i);
        }

        dfs1(1);
        dfs2(1);
        int ans = 0;
        for(int i = 1; i <= n; ++i) {
            ans ^= accumulate(dp[i], dp[i] + k + 1, 0);
        }
        printf("%d\n", ans);
    }
    return 0;
}
