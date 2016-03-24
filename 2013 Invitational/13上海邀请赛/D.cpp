//
//  Created by TaoSama on 2015-04-26
//  Copyright (c) 2015 TaoSama. All rights reserved.
//
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

int n, m, nx, ny;
char a[55][55];
int x[55][55], y[55][55], match[2505], cnt;

bool vis[2505];

int pnt[50005], nxt[50005], head[5005];
void add_edge(int u, int v) {
    pnt[cnt] = v;
    nxt[cnt] = head[u];
    head[u] = cnt++;
}

bool dfs(int u) {
    for(int i = head[u]; ~i; i = nxt[i]) {
		int &v = pnt[i];
        if(!vis[v]) {
            vis[v] = true;
            if(match[v] == -1 || dfs(match[v])) {
                match[v] = u;
                return true;
            }
        }
    }
    return false;
}

int Hungary() {
    int ret = 0;
    memset(match, -1, sizeof match);
    for(int i = 1; i <= nx; ++i) {
        memset(vis, false, sizeof vis);
        ret += dfs(i);
    }
    return ret;
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int t; cin >> t;
    while(t--) {
        cin >> n >> m;
        for(int i = 1; i <= n; ++i) cin >> a[i] + 1;

        cnt = 0;
        memset(x, 0, sizeof x);
        memset(y, 0, sizeof y);
        memset(head, -1, sizeof head);

        int tot = 0;
        for(int i = 1; i <= n; ++i) {
            bool have = false;
            for(int j = 1; j <= m; ++j) {
                if(a[i][j] == '*') {
                    if(have == false) tot++;
                    x[i][j] = tot;
                    //printf("x[%d][%d]: %d\n", i, j, x[i][j]);
                    have = true;
                } else if(a[i][j] == '#') have = false;
            }
        }
        nx = tot;
        tot = 0;
        for(int j = 1; j <= m; ++j) {
            bool have = false;
            for(int i = 1; i <= n; ++i) {
                if(a[i][j] == '*') {
                    if(have == false) tot++;
                    y[i][j] = tot;
                    //printf("y[%d][%d]: %d\n", i, j, y[i][j]);
                    have = true;
                } else if(a[i][j] == '#') have = false;
            }
        }
        ny = tot;
        for(int i = 1; i <= n; ++i) {
            for(int j = 1; j <= m; ++j) {
                int &u = x[i][j], &v = y[i][j];
                if(u && v) add_edge(u, v);
            }
        }
        int ans = Hungary();
        cout << ans << '\n';
    }
    return 0;
}
