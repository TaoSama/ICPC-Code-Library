//
//  Created by TaoSama on 2016-04-06
//  Copyright (c) 2016 TaoSama. All rights reserved.
//
#pragma comment(linker, "/STACK:102400000,102400000")
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

int n, m, k;
vector<int> G[N];

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int t; scanf("%d", &t);
    while(t--) {
        scanf("%d%d%d", &n, &m, &k);
        for(int i = 1; i <= n; ++i) G[i].clear();

        vector<int> in(N, 0);
        for(int i = 1; i <= m; ++i) {
            int u, v; scanf("%d%d", &u, &v);
            G[u].push_back(v);
            ++in[v];
        }

        vector<bool> used(N, false);
        priority_queue<int, vector<int>, greater<int> > q;
        for(int i = 1; i <= n; ++i) if(in[i] <= k) q.push(i);

        int ans = 0;
        for(int i = 1; i <= n; ++i) {
            int u;
            while(true) {
                u = q.top(); q.pop();
                if(!used[u] && in[u] <= k) break;
            }
            k -= in[u];
            used[u] = true;

            ans += 1LL * i * u % MOD;
            if(ans >= MOD) ans -= MOD;

            for(int v : G[u])
                if(--in[v] <= k) q.push(v);
        }
        printf("%d\n", ans);
    }
    return 0;
}
