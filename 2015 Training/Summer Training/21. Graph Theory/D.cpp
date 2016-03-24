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

int n, m, vis[30];
bool g[30][30];

int cnt, kase;
string name[30];
map<string, int> mp;
int ID(string &s) {
    if(!mp.count(s)) {
        mp[s] = ++cnt;
        name[cnt] = s;
    }
    return mp[s];
}

vector<int> path;
void dfs(int u) {
    vis[u] = kase;
    path.push_back(u);
    for(int v = 1; v <= n; ++v) {
        if(g[u][v] && vis[v] != kase) {
            dfs(v);
        }
    }
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(cin >> n >> m && (n || m)) {
        mp.clear(); cnt = 0;
        memset(g, false, sizeof g);
        for(int i = 1; i <= n; ++i) g[i][i] = true;
        for(int i = 1; i <= m; ++i) {
            string s, t; cin >> s >> t;
            int u = ID(s), v = ID(t);
            g[u][v] = true;
        }

        for(int k = 1; k <= n; ++k)
            for(int i = 1; i <= n; ++i)
                for(int j = 1; j <= n; ++j)
                    g[i][j] |= g[i][k] && g[k][j];

        for(int i = 1; i <= n; ++i)
            for(int j = i + 1; j <= n; ++j)
                if(!g[i][j] || !g[j][i])
                    g[i][j] = g[j][i] = false;

        if(kase++) cout << '\n';
        cout << "Calling circles for data set " << kase << ":\n";
        for(int i = 1; i <= n; ++i) {
            if(vis[i] != kase) {
                path.clear();
                dfs(i);
                cout << name[path[0]];
                for(int j = 1; j < path.size(); ++j)
                    cout << ", " << name[path[j]];
                cout << '\n';
            }
        }
    }
    return 0;
}
