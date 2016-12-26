//
//  Created by TaoSama on 2016-12-14
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

int n, a[N];
vector<int> G[N];

void dfs(int u, int d, int& ans) {
    if(d) ans ^= a[u];
    for(int v : G[u]) dfs(v, d ^ 1, ans);
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\luwt\\Desktop\\in.txt", "r", stdin);
#endif // LOCAL
    ios_base::sync_with_stdio(0);

    int t; scanf("%d", &t);
    while(t--) {
        scanf("%d", &n);
        for(int i = 0; i < n; ++i) G[i].clear();
        for(int i = 1; i < n; ++i) {
            int fa; scanf("%d", &fa);
            G[fa].push_back(i);
        }
        for(int i = 0; i < n; ++i) scanf("%d", a + i);

        int ans = 0;
        dfs(0, 0, ans);
        puts(ans ? "win" : "lose");
    }
    return 0;
}
