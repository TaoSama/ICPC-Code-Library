//
//  Created by TaoSama on 2017-01-31
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
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n;
vector<int> G[N];
bool have[N][4];
pair<int, int> ans[N];
int d[][2] = { -1, 0, 0, 1, 1, 0, 0, -1};
int dis;

void dfs(int u, int fa) {
    if(u == 1) ans[1] = {0, 0};
    else {
        for(int i = 0; i < 4; ++i) {
            if(!have[fa][i]) {
                have[fa][i] = true;
                have[u][(i + 2) % 4] = true;
//                pr(fa); pr(u); pr(i); pr(d[i][0]); prln(d[i][1]);
                ans[u] = {ans[fa].first + dis* d[i][0], ans[fa].second + dis* d[i][1]};
                break;
            }
        }
        dis >>= 1;
    }
    for(int v : G[u]) {
        if(v != fa) dfs(v, u);
    }
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(cin >> n) {
        for(int i = 1; i <= n; ++i) G[i].clear();
        for(int i = 1; i < n; ++i) {
            int u, v; cin >> u >> v;
            G[u].push_back(v);
            G[v].push_back(u);
        }
        bool ok = true;
        for(int i = 1; i <= n && ok; ++i) ok &= G[i].size() <= 4;
        if(!ok) {cout << "NO\n"; continue;}

        memset(have, 0, sizeof have);
        dis = 1 << n;
        dfs(1, 0);

        cout << "YES\n";
        for(int i = 1; i <= n; ++i) cout << ans[i].first << ' ' << ans[i].second << endl;
    }

    return 0;
}
