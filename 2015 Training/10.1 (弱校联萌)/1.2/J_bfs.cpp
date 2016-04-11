//
//  Created by TaoSama on 2015-10-02
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
#include <stack>
#include <string>
#include <set>
#include <vector>

using namespace std;
#define pr(x) cout << #x << " = " << x << "  "
#define prln(x) cout << #x << " = " << x << endl
const int N = 1e6 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

vector<int> G[N];

typedef long long LL;

int n, fa[N], sum[N];
LL dp[N];

bool cmp(int x, int y) {
    return sum[x] > sum[y];
}

void bfs(int root) {
    queue<int> q;
    stack<int> s;
    q.push(root); s.push(root);
    while(q.size()) {
        int u = q.front(); q.pop();
        for(int i = 0; i < G[u].size(); ++i) {
            int v = G[u][i];
            q.push(v);
            s.push(v);
        }
    }
    while(s.size()) {
        int u = s.top(); s.pop();
        dp[u] = 0;
        sort(G[u].begin(), G[u].end(), cmp);
        for(int i = 0; i < G[u].size(); ++i) {
            int v = G[u][i];
            dp[u] += dp[v] + 1LL * i * sum[v];
            sum[u] += sum[v];
        }
    }
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d", &n) == 1) {
        for(int i = 0; i < n; ++i) G[i].clear();
        for(int v = 0; v < n; ++v) {
            scanf("%d%d", sum + v, fa + v);
            if(~fa[v]) G[fa[v]].push_back(v);
        }
        LL ans = 0;
        for(int i = 0; i < n; ++i) {
            if(fa[i] == -1) {
                bfs(i);
                ans += dp[i];
            }
        }
        printf("%lld\n", ans);
    }
    return 0;
}
