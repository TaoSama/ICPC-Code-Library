//
//  Created by TaoSama on 2016-12-06
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
const int N = 2e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, col[N], u[N], v[N];
vector<int> G[N];

void dfs(int u, int c) {
    col[u] = c;
    for(int v : G[u]) if(!col[v]) dfs(v, 3 - c);
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    scanf("%d", &n);
    for(int i = 1; i <= n; ++i) {
        scanf("%d%d", u + i, v + i);
        G[u[i]].push_back(v[i]);
        G[v[i]].push_back(u[i]);
    }
    for(int i = 1; i <= n; ++i) {
        G[2 * i - 1].push_back(2 * i);
        G[2 * i ].push_back(2 * i - 1);
    }
    for(int i = 1; i <= 2 * n; ++i) if(!col[i]) dfs(i, 1);
    for(int i = 1; i <= n; ++i)
        printf("%d %d\n", col[u[i]], col[v[i]]);

    return 0;
}
