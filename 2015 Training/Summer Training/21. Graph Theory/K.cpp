//
//  Created by TaoSama on 2015-08-16
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

int n, m, k, X;
int a[105][105], row[105][105], col[105][105]; //1->interest 2->obstacle

vector<int> G[2505];

int match[2505];
bool vis[2505];

bool dfs(int u) {
    for(auto &v : G[u]) {
        if(vis[v]) continue;
        vis[v] = true;
        if(match[v] == -1 || dfs(match[v])) {
            match[v] = u;
            return true;
        }
    }
    return false;
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int t; scanf("%d", &t);
    while(t--) {
        scanf("%d%d", &n, &m);
        memset(a, 0, sizeof a);
        for(int z = 1; z <= 2; ++z) {
            scanf("%d", &k);
            for(int i = 1; i <= k; ++i) {
                int u, v; scanf("%d%d", &u, &v);
                a[u][v] = z;
            }
        }

        int cnt = 0; //split row
        for(int i = 1; i <= n; ++i) {
            bool inc = true;
            for(int j = 1; j <= m; ++j) {
                if(a[i][j] == 1) {
                    if(inc) ++cnt;
                    row[i][j] = cnt;
                    inc = false;
                }
                if(a[i][j] == 2) inc = true;
            }
        }
        X = cnt;

        cnt = 0; //split column
        for(int j = 1; j <= m; ++j) {
            bool inc = true;
            for(int i = 1; i <= n; ++i) {
                if(a[i][j] == 1) {
                    if(inc) ++cnt;
                    col[i][j] = cnt;
                    inc = false;
                }
                if(a[i][j] == 2) inc = true;
            }
        }

        //construct the graph
        for(int i = 1; i <= X; ++i) G[i].clear();
        for(int i = 1; i <= n; ++i) {
            for(int j = 1; j <= m; ++j) {
                if(a[i][j] == 1) {
                    int &u = row[i][j], &v = col[i][j];
                    G[u].push_back(v);
                }
            }
        }

        int ans = 0;  //Hungary algorithm
        memset(match, -1, sizeof match);
        for(int i = 1; i <= X; ++i) {
            memset(vis, false, sizeof vis);
            ans += dfs(i);
        }
        printf("%d\n", ans);
    }
    return 0;
}
