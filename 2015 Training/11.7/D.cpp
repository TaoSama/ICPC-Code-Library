//
//  Created by TaoSama on 2015-11-08
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
const int N = 26, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n;
vector<int> G[N];

int dfn[N], low[N], in[N], stk[N], top, dfsNum, scc;
string ans[26];

void tarjan(int u) {
    low[u] = dfn[u] = ++dfsNum;
    in[u] = true;
    stk[++top] = u;
    for(auto v : G[u]) {
        if(!dfn[v]) {
            tarjan(v);
            low[u] = min(low[u], low[v]);
        } else if(in[v]) low[u] = min(low[u], dfn[v]);
    }
    if(low[u] == dfn[u]) {
        ans[++scc] = "";
        while(true) {
            int v = stk[top--];
            in[v] = false;
            ans[scc] += char(v + 'A');
            if(v == u) break;
        }
        sort(ans[scc].begin(), ans[scc].end());
    }
}

bool vis[26];

void init() {
    top = scc = dfsNum = 0;
    memset(dfn, 0, sizeof dfn);
    memset(low, 0, sizeof low);
    memset(in, 0, sizeof in);
    memset(vis, 0, sizeof vis);
    for(int i = 0; i < 26; ++i) G[i].clear();
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int kase = 0;
    while(scanf("%d", &n) == 1 && n) {
        init();
        char buf[10][2];
        for(int i = 1; i <= n; ++i) {
            for(int j = 1; j <= 6; ++j) scanf("%s", buf[j]);
            int u = buf[6][0] - 'A', v;
            vis[u] = true;
            for(int j = 1; j <= 5; ++j) {
                v = buf[j][0] - 'A';
                vis[v] = true;
                if(v == u) continue;
                G[u].push_back(v);
            }
        }
        for(int i = 0; i < 26; ++i) if(vis[i] && !dfn[i]) tarjan(i);
        sort(ans + 1, ans + 1 + scc);
        if(kase++) puts("");
        for(int i = 1; i <= scc; ++i)
            for(int j = 0; j < ans[i].size(); ++j)
                printf("%c%c", ans[i][j], " \n"[j == ans[i].size() - 1]);
    }
    return 0;
}
