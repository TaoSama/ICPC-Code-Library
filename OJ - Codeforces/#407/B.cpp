//
//  Created by TaoSama on 2017-03-29
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
#define pr(x) cerr << #x << " = " << x << "  "
#define prln(x) cerr << #x << " = " << x << endl
const int N = 1e6 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, m;
int fa[N];

int find(int x) {
    return fa[x] = fa[x] == x ? x : find(fa[x]);
}

typedef long long LL;

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(cin >> n >> m) {
        for(int i = 1; i <= n; ++i) fa[i] = i;

        int u, v;
        LL cycle = 0;
        vector<int> deg(n + 1, 0), vis(n + 1, 0);
        for(int i = 1; i <= m; ++i) {
            cin >> u >> v;
            vis[u] = vis[v] = true;
            if(u == v) {++cycle; continue;}
            ++deg[u]; ++deg[v];
            fa[find(u)] = find(v);
        }

        auto C2 = [](LL x) {return x * (x - 1) / 2;};

        LL ans = 0, ok = true;
        for(int i = 1; i <= n; ++i) {
            if(vis[i] && find(i) != find(u)) ok = false;
            ans += C2(deg[i]);
        }
        if(!ok) {cout << "0\n"; continue;}

        ans += C2(cycle) + cycle * (m - cycle);
        cout << ans << endl;
    }

    return 0;
}
