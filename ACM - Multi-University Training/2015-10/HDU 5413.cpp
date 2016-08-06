//
//  Created by TaoSama on 2016-07-18
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
#include <bitset>

using namespace std;
#define pr(x) cout << #x << " = " << x << "  "
#define prln(x) cout << #x << " = " << x << endl
const int N = 2e4 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, m;
vector<int> G[N], rG[N];
bitset<N> reach[N];

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);
    clock_t _ = clock();

    int t; scanf("%d", &t);
    while(t--) {
        scanf("%d%d", &n, &m);
        for(int i = 1; i <= n; ++i) {
            G[i].clear();
            rG[i].clear();
            reach[i].reset();
            reach[i][i] = 1;
        }

        vector<int> in(n + 1, 0);
        for(int i = 1; i <= m; ++i) {
            int u, v; scanf("%d%d", &u, &v);
            G[u].push_back(v);
            rG[v].push_back(u);
            ++in[v];
        }

        queue<int> q;
        for(int i = 1; i <= n; ++i) if(!in[i]) q.push(i);
        vector<int> topoSeq, topoStp(n + 1);
        while(q.size()) {
            int u = q.front(); q.pop();
            topoSeq.push_back(u);
            topoStp[u] = topoSeq.size();
            for(int v : G[u]) if(--in[v] == 0) q.push(v);
        }

        int ans = 0;
        for(int u : topoSeq) {
            sort(rG[u].begin(), rG[u].end(), [&](int x, int y) {
                return topoStp[x] > topoStp[y];
            });
            for(int v : rG[u]) {
                ans += reach[u][v];
                reach[u] |= reach[v];
            }
        }
        printf("%d\n", ans);
    }

#ifdef LOCAL
    printf("\nTime cost: %.2fs\n", 1.0 * (clock() - _) / CLOCKS_PER_SEC);
#endif
    return 0;
}
