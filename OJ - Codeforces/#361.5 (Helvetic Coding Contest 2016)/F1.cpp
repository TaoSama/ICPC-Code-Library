//
//  Created by TaoSama on 2016-07-10
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
const int N = 1e4 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n;
vector<int> G[N];
int d[N];

void bfs(int s, int& ans) {
    queue<int> q;
    q.push(s);
    memset(d, -1, sizeof d);
    d[s] = 0;
    while(q.size()) {
        int u = q.front(); q.pop();
        if(d[u] == 2) {
            ans += u >= s;
            continue;
        }
        for(int v : G[u]) {
            if(d[v] == -1) {
                d[v] = d[u] + 1;
                q.push(v);
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
    clock_t _ = clock();

    while(scanf("%d", &n) == 1) {
        for(int i = 1; i <= n; ++i) G[i].clear();
        for(int i = 1; i < n; ++i) {
            int u, v;  scanf("%d%d", &u, &v);
            G[u].push_back(v);
            G[v].push_back(u);
        }

        int ans = 0;
        for(int i = 1; i <= n; ++i) bfs(i, ans);
        printf("%d\n", ans);
    }

#ifdef LOCAL
    printf("\nTime cost: %.2fs\n", 1.0 * (clock() - _) / CLOCKS_PER_SEC);
#endif
    return 0;
}
