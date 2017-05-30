//
//  Created by TaoSama on 2017-05-04
//  Copyright (c) 2017 TaoSama. All rights reserved.
//
#pragma comment(linker, "/STACK:102400000,102400000")
#include <bits/stdc++.h>

using namespace std;
#define pr(x) cerr << #x << " = " << x << "  "
#define prln(x) cerr << #x << " = " << x << endl
const int N = 3e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, m;
vector<int> col[N], G[N];
int ans[N];

void dfs(int u, int fa) {
    set<int> s;
    vector<int>& g = col[u];
    for(int v : g) if(ans[v]) s.insert(ans[v]);
    int c = 1;
    for(int v : g) {
        if(ans[v]) continue;
        while(s.count(c)) ++c;
        s.insert(c);
        ans[v] = c;
    }
    for(int v : G[u]) if(v != fa) dfs(v, u);
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d%d", &n, &m) == 2) {
        int maxc = 1;
        for(int i = 1; i <= n; ++i) {
            int cnt; scanf("%d", &cnt);
            col[i].clear();
            col[i].resize(cnt);
            maxc = max(maxc, cnt);
            for(auto& x : col[i]) scanf("%d", &x);
        }
        for(int i = 1; i <= n; ++i) G[i].clear();
        for(int i = 1; i < n; ++i) {
            int u, v; scanf("%d%d", &u, &v);
            G[u].push_back(v);
            G[v].push_back(u);
        }

        memset(ans, 0, sizeof ans);
        dfs(1, -1);

        printf("%d\n", maxc);
        for(int i = 1; i <= m; ++i) {
            if(!ans[i]) ans[i] = 1;
            printf("%d%c", ans[i], " \n"[i == m]);
        }
    }

    return 0;
}
