//
//  Created by TaoSama on 2015-11-09
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
const int N = 1e3 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, q, ancestor[N];

vector<int> G[N];
struct Query {
    int v, id;
};
vector<Query> Q[N];

int find(int x) {
    return ancestor[x] = ancestor[x] == x ? x : find(ancestor[x]);
}

bool checked[N], vis[N], answered[N * N];

map<int, int> mp;

void tarjan(int u) {
    checked[u] = true;
    ancestor[u] = u;
    for(int i = 0; i < G[u].size(); ++i) {
        int v = G[u][i];
        tarjan(v);
        ancestor[v] = u;
    }
    for(int i = 0; i < Q[u].size(); ++i) {
        Query &q = Q[u][i];
        if(checked[q.v] && !answered[q.id]) {
            answered[q.id] = true;
            ++mp[find(q.v)];
        }
    }
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d", &n) == 1) {
        for(int i = 1; i <= n; ++i) G[i].clear(), Q[i].clear();
        memset(vis, false, sizeof vis);
        memset(checked, false, sizeof checked);
        memset(answered, false, sizeof answered);
        mp.clear();
        for(int i = 1; i <= n; ++i) {
            int u, v, k; scanf("%d:(%d)", &u, &k);
            while(k--) {
                scanf("%d", &v);
                vis[v] = true;
                G[u].push_back(v);
            }
        }
        scanf("%d", &q);
        for(int i = 1; i <= q; ++i) {
            int u, v; scanf(" (%d%d)", &u, &v);
            Q[u].push_back((Query) {v, i});
            Q[v].push_back((Query) {u, i});
        }

        for(int i = 1; i <= n; ++i) if(!vis[i]) {tarjan(i); break;}
        map<int, int>::iterator iter = mp.begin();
        for(; iter != mp.end(); ++iter) printf("%d:%d\n", iter->first, iter->second);
    }
    return 0;
}
