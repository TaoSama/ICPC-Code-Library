//
//  Created by TaoSama on 2017-04-30
//  Copyright (c) 2017 TaoSama. All rights reserved.
//
#pragma comment(linker, "/STACK:102400000,102400000")
#include <bits/stdc++.h>

using namespace std;
#define pr(x) cerr << #x << " = " << x << "  "
#define prln(x) cerr << #x << " = " << x << endl
const int N = 3e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, w[N];
vector<int> G[N];

int dwMax[N][2], dwMin[N][2], upMax[N][2], upMin[N][2];
//1choose, 0any is ok, dw->u, up->fa[u]

void dfs1(int u, int fa) {
    vector<int> sons(1, 0);
    for(int v : G[u]) if(v != fa) sons.push_back(v);
    for(int i = 1; i < sons.size(); ++i) dfs1(sons[i], u);

    dwMax[u][0] = -INF; dwMax[u][1] = w[u];
    for(int i = 1; i < sons.size(); ++i) {
        int v = sons[i];
        dwMax[u][1] += max(0, dwMax[v][1]);
        dwMax[u][0] = max(dwMax[u][0], dwMax[v][0]);
    }
    dwMax[u][0] = max(dwMax[u][0], dwMax[u][1]);

    dwMin[u][0] = INF; dwMin[u][1] = w[u];
    for(int i = 1; i < sons.size(); ++i) {
        int v = sons[i];
        dwMin[u][1] += min(0, dwMin[v][1]);
        dwMin[u][0] = min(dwMin[u][0], dwMin[v][0]);
    }
    dwMin[u][0] = min(dwMin[u][0], dwMin[u][1]);
}

int pre[N], suf[N];
void dfs2(int u, int fa) {
    vector<int> sons(1, 0);
    for(int v : G[u]) if(v != fa) sons.push_back(v);

    int sum = 0;
    for(int i = 1; i < sons.size(); ++i) sum += max(0, dwMax[sons[i]][1]);
    for(int i = 1; i < sons.size(); ++i) {
        int v = sons[i];
        upMax[v][1] += w[u] + max(0, upMax[u][1]) + sum - max(0, dwMax[v][1]);
    }

    pre[0] = pre[sons.size()] = suf[0] = suf[sons.size()] = -INF;
    for(int i = 1; i < sons.size(); ++i) {
        int v = sons[i];
        pre[i] = max(pre[i - 1], dwMax[v][0]);
    }
    for(int i = sons.size() - 1; i; --i) {
        int v = sons[i];
        suf[i] = max(suf[i + 1], dwMax[v][0]);
    }

    for(int i = 1; i < sons.size(); ++i) {
        int v = sons[i];
        upMax[v][0] = max({upMax[u][0], upMax[v][1], pre[i - 1], suf[i + 1]});
    }

    /*--------------------------------------------------------------------*/

    sum = 0;
    for(int i = 1; i < sons.size(); ++i) sum += min(0, dwMin[sons[i]][1]);
    for(int i = 1; i < sons.size(); ++i) {
        int v = sons[i];
        upMin[v][1] += w[u] + min(0, upMin[u][1]) + sum - min(0, dwMin[v][1]);
    }

    pre[0] = pre[sons.size()] = suf[0] = suf[sons.size()] = INF;
    for(int i = 1; i < sons.size(); ++i) {
        int v = sons[i];
        pre[i] = min(pre[i - 1], dwMin[v][0]);
    }
    for(int i = sons.size() - 1; i; --i) {
        int v = sons[i];
        suf[i] = min(suf[i + 1], dwMin[v][0]);
    }
    for(int i = 1; i < sons.size(); ++i) {
        int v = sons[i];
        upMin[v][0] = min({upMin[u][0], upMin[v][1], pre[i - 1], suf[i + 1]});
    }

    for(int i = 1; i < sons.size(); ++i) dfs2(sons[i], u);
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    scanf("%d", &n);
    for(int i = 1; i <= n; ++i) scanf("%d", w + i);
    for(int i = 1; i < n; ++i) {
        int u, v; scanf("%d%d", &u, &v);
        G[u].push_back(v);
        G[v].push_back(u);
    }

    dfs1(1, 0);
    dfs2(1, 0);
//    for(int i = 1; i <= n; ++i)
//        for(int j = 0; j < 2; ++j)
//            printf("dwMax[%d][%d] = %d dwMin[%d][%d] = %d\n", i, j, dwMax[i][j], i, j, dwMin[i][j]);
//    for(int i = 1; i <= n; ++i)
//        for(int j = 0; j < 2; ++j)
//            if(i != 1) printf("upMax[%d][%d] = %d upMin[%d][%d] = %d\n", i, j, upMax[i][j], i, j, upMin[i][j]);


    long long ans = 1e-18;
    for(int i = 1; i <= n; ++i) {
        ans = max(ans, 0LL + dwMax[i][0]);
        ans = max(ans, 0LL + upMax[i][0]);
        if(i != 1) {
            ans = max(ans, 1LL * dwMax[i][0] * upMax[i][0]);
            ans = max(ans, 1LL * dwMin[i][0] * upMin[i][0]);
        }
    }
    printf("%lld\n", ans);

    return 0;
}
