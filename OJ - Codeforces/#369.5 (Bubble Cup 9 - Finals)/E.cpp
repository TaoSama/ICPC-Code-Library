//
//  Created by TaoSama on 2016-09-11
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
#include <cassert>

using namespace std;
#define pr(x) cout << #x << " = " << x << "  "
#define prln(x) cout << #x << " = " << x << endl
const int N = 2e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, col[N], pink[N];
vector<int> G[N];

void dfs1(int u, int fa) {
    pink[u] = !col[u];
    for(int v : G[u]) {
        if(v == fa) continue;
        dfs1(v, u);
        pink[u] += pink[v];
    }
}

int all;
void doIt(int u, vector<int>& ans) {
    if(!all) return;
    col[u] ^= 1;
    all += col[u] ? -1 : 1;
    ans.push_back(u);
}

void dfs2(int u, int fa, vector<int>& ans) {
    for(int v : G[u]) {
        if(v == fa) continue;
        if(pink[v]) {
            doIt(v, ans);
            dfs2(v, u, ans);
            doIt(u, ans);
            if(!col[v]) {
                doIt(v, ans);
                doIt(u, ans);
            }
        }
    }
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    cin >> n;
    for(int i = 1; i <= n; ++i) {
        cin >> col[i];
        if(col[i] == -1) col[i] = 0;
    }

    for(int i = 1; i < n; ++i) {
        int u, v; cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    dfs1(1, 0);
    vector<int> ans(1, 1);
    all = pink[1];
    dfs2(1, 0, ans);
    if(!col[1]) {
        doIt(G[1][0], ans);
        doIt(1, ans);
        doIt(G[1][0], ans);
    }
    for(auto x : ans) cout << x << ' ';
    cout << endl;

    for(int i = 1 ;  i <= n; ++i) assert(col[i]);

    return 0;
}
