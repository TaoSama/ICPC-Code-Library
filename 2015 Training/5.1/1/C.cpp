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

int n, ans[N];
vector<int> G[N];
map<int, bool> con[N];
bool vis[N];

void dfs(int k) {
    if(k == n) {
        if(con[ans[n - 1]][ans[1]] && con[ans[n]][ans[1]] && con[ans[n]][ans[2]])
            throw true;
        return;
    }

    for(int i = 0; i < 4; ++i) {
        int &v = G[ans[k]][i];
        ans[k + 1] = v;
        if(vis[v] || ans[k - 1] && ans[k + 1] && !con[ans[k - 1]][ans[k + 1]])
            continue;
        vis[v] = true;
        dfs(k + 1);
        vis[v] = false;
    }
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    scanf("%d", &n);
    for(int i = 1; i <= n << 1; ++i) {
        int u, v; scanf("%d%d", &u, &v);
        G[u].push_back(v); G[v].push_back(u);
        con[u][v] = con[v][u] = true;
    }

    for(int i = 1; i <= n; ++i) {
        if(G[i].size() != 4) {
            puts("-1");
            return 0;
        }
    }

    vis[1] = true;  ans[1] = 1;
    try {
        //cout<<"search"<<endl;
        dfs(1);
    } catch(bool) {
        for(int i = 1; i <= n; ++i)
            printf("%d ", ans[i]);
        puts("");
        return 0;
    }
    puts("-1");
    return 0;
}
