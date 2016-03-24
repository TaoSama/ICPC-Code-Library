//
//  Created by TaoSama on 2015-06-02
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
const int N = 1e5 + 10;

int n, m, k;
int nxt[N << 1], head[N << 1], pnt[N << 1], tot;

void add_edge(int u, int v) {
    pnt[tot] = v;
    nxt[tot] = head[u];
    head[u] = tot++;
}

bool vis[N];
vector<int> path;

void dfs(int u) {
    if(path.size() > k) {
        /*for(int i = 0; i < path.size(); ++i)
            cout<<path[i]<<' ';
        cout<<endl;*/
        for(int i = head[u]; ~i; i = nxt[i])
            if(pnt[i] == path[0]) throw 1;
    }
    for(int i = head[u]; ~i; i = nxt[i]) {
        int &v = pnt[i];
        if(vis[v]) continue;
        path.push_back(v); vis[v] = true;
        dfs(v);
        path.pop_back(); vis[v] = false;
    }
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d%d%d", &n, &m, &k) == 3) {
        tot = 0;  path.clear();
        memset(head, -1, sizeof head);
        memset(vis, false, sizeof vis);
        for(int i = 1; i <= m; ++i) {
            int u, v; scanf("%d%d", &u, &v);
            add_edge(u, v);
            add_edge(v, u);
        }
        //s = spfa();
        //cout << s << endl;
        try {
            for(int i = 1; i <= n; ++i) {
                path.push_back(i); vis[i] = true;
                dfs(i);
                path.pop_back(); vis[i] = false;
            }
        } catch(int) {
            printf("%d\n", path.size());
            for(int i = 0; i < path.size(); ++i)
                printf("%d ", path[i]);
            puts("");
        }
    }
    return 0;
}
