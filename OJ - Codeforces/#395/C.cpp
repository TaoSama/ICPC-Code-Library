//
//  Created by TaoSama on 2017-02-02
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
int u[N], v[N], c[N], same[N];

void dfs(int u, int root, int fa) {
    same[u] = 1;
    for(int v : G[u]) {
        if(v == fa) continue;
        dfs(v, root, u);
//        cout << u << c[u] << v << c[v] << endl;
        same[u] &= same[v];
        if(u != root) same[u] &= c[u] == c[v];
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
            cin >> u[i] >> v[i];
            G[u[i]].push_back(v[i]);
            G[v[i]].push_back(u[i]);
        }

        for(int i = 1; i <= n; ++i) {
            cin >> c[i];
        }

        int ok = -1;
        for(int i = 1; i < n && ok == -1; ++i) {
            if(c[u[i]] != c[v[i]]) {
                ok = i;
            }
        }
        if(ok == -1) {
            cout << "YES\n1\n";
            continue;
        }

//      pr(u[ok]); prln(v[ok]);

        int ans = -1;
        dfs(u[ok], u[ok], -1);
        if(same[u[ok]]) ans = u[ok];
        dfs(v[ok], v[ok], -1);
        if(same[v[ok]]) ans = v[ok];

        if(ans == -1) cout << "NO\n";
        else {
            cout << "YES\n";
            cout << ans << "\n";
        }
    }

    return 0;
}
