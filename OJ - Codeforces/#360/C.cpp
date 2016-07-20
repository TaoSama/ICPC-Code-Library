//
//  Created by TaoSama on 2016-06-30
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

int col[N];
int n, m;
vector<int> G[N];

bool dfs(int u, int c) {
    col[u] = c;
    for(int v : G[u]) {
        if(col[v] == col[u]) return false;
        if(!col[v] && !dfs(v, -c)) return false;
    }
    return true;
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);
    clock_t _ = clock();

    while(scanf("%d%d", &n, &m) == 2) {
        for(int i = 1; i <= n; ++i) G[i].clear();
        for(int i = 1; i <= m; ++i) {
            int u, v; scanf("%d%d", &u, &v);
            G[u].push_back(v);
            G[v].push_back(u);
        }
        bool ok = true;
        memset(col, 0, sizeof col);
        for(int i = 1; i <= n; ++i) {
            if(!col[i]) {
                if(!dfs(i, 1)) {
                    ok = false;
                    break;
                }
            }
        }

        if(!ok) {puts("-1"); continue;}
        vector<int> ans[2];
        for(int i = 1; i <= n; ++i) {
            if(col[i] == 1) ans[0].push_back(i);
            else ans[1].push_back(i);
        }
        for(int i = 0; i < 2; ++i) {
            printf("%d\n", ans[i].size());
            for(int j = 0; j < ans[i].size(); ++j) {
                printf("%d%c", ans[i][j], " \n"[j == ans[i].size() - 1]);
            }
        }
    }

#ifdef LOCAL
    printf("\nTime cost: %.2fs\n", 1.0 * (clock() - _) / CLOCKS_PER_SEC);
#endif
    return 0;
}
