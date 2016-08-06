//
//  Created by TaoSama on 2016-08-06
//  Copyright (c) 2016 TaoSama. All rights reserved.
//
#pragma comment(linker, "/STACK:102400000,102400000")
#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
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
const int N = 50 + 1, INF = 0x3f3f3f3f, MOD = 998244353;

int n, m, k, q;
int w[N];
vector<int> G[N];
int f[N][N][N][3];

void add(int& x, int y) {
    if((x += y) >= MOD) x -= MOD;
}

int dfs(int x, int y, int z, int who) {
    int& ret = f[x][y][z][who];
    if(ret >= 0) return ret;
    ret = 0;

    if(who == 2) {
        ret = 1;
        for(int v : G[x]) add(ret, dfs(v, y, z, 0));
    } else if(who == 0) {
        for(int v : G[y]) {
            if(abs(w[x] - w[v]) > k) continue;
            add(ret, dfs(x, v, z, 1));
        }
    } else {
        for(int v : G[z]) {
            if(abs(w[x] - w[v]) > k || abs(w[y] - w[v]) > k) continue;
            add(ret, dfs(x, y, v, 2));
        }
    }
    return ret;
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int t; scanf("%d", &t);
    while(t--) {
        scanf("%d%d%d%d", &n, &m, &k, &q);
        for(int i = 1; i <= n; ++i) scanf("%d", w + i);
        for(int i = 1; i <= n; ++i) G[i].clear();
        for(int i = 1; i <= m; ++i) {
            int u, v; scanf("%d%d", &u, &v);
            G[u].push_back(v);
        }

        memset(f, -1, sizeof f);
        while(q--) {
            int x, y, z; scanf("%d%d%d", &x, &y, &z);
            printf("%d\n", dfs(x, y, z, 2));
        }
    }

    return 0;
}
