//
//  Created by TaoSama on 2015-06-14
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
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int N = 1e4 + 10;

int n, m;
int head[N], pnt[N], nxt[N], cnt;

void add_edge(int u, int v) {
    pnt[cnt] = v;
    nxt[cnt] = head[u];
    head[u] = cnt++;
}

int dfn[5005], low[5005], cut[5005], tim;
bool in[5005];
void dfs(int u, int f, int del) {
    dfn[u] = low[u] = ++tim;
    int son = 0;
    for(int i = head[u]; ~i; i = nxt[i]) {
        int &v = pnt[i];
        if(v == f || v == del) continue;
        if(!dfn[v]) {
            ++son;
            dfs(v, u, del);
            low[u] = min(low[u], low[v]);
            if(low[v] >= dfn[u]) cut[u]++;
        } else low[u] = min(low[u], dfn[v]);
    }
    if(f < 0) cut[u]--;
    //根节点要-1 孤立节点算1个cc没有儿子0-1 = -1 不是孤立节点的话减少1 总之都要-1
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d%d", &n, &m) == 2) {
        cnt = 0;
        memset(head, -1, sizeof head);
        for(int i = 0; i < m; ++i) {
            int u, v; scanf("%d%d", &u, &v);
            add_edge(u, v);
            add_edge(v, u);
        }

        int ans = -INF, cc;
        for(int i = 0; i < n; ++i) {
            cc = tim = 0;
            memset(dfn, 0, sizeof dfn);
            memset(low, 0, sizeof low);
            memset(cut, 0, sizeof cut);
            for(int j = 0; j < n; ++j) {
                if(i == j) continue;
                if(!dfn[j]) {
                    ++cc;
                    dfs(j, -1, i);
                }
            }
            for(int j = 0; j < n; ++j) {
                if(i == j) continue;
                ans = max(ans, cc + cut[j]);
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
