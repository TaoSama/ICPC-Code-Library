//
//  Created by TaoSama on 2016-09-05
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

typedef long long LL;
int n, m;
int a[N], b[N];
LL cnt[N], ans[N];
vector<int> G[N];

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(cin >> n >> m) {
        for(int i = 1; i <= n; ++i) G[i].clear();
        for(int i = 1; i <= n; ++i) cin >> a[i] >> b[i];

        vector<int> in(n + 1, 0);
        for(int i = 1; i <= m; ++i) {
            int u, v; cin >> u >> v;
            G[u].push_back(v);
            ++in[v];
        }

        vector<int> topo;
        for(int i = 1; i <= n; ++i) if(!in[i]) topo.push_back(i);
        for(int i = 0; i < n; ++i) {
            int u = topo[i];
            for(int v : G[u]) if(!--in[v]) topo.push_back(v);
        }

        auto add = [](LL & x, LL y) {
            if((x += y) >= MOD) x -= MOD;
        };

        memset(cnt, 0, sizeof cnt);
        for(int u : topo) {
            ans[u] = cnt[u] * b[u] % MOD;
            add(cnt[u], a[u]);
            for(int v : G[u]) add(cnt[v], cnt[u]);
        }

        LL sum = 0;
        for(int i = 1; i <= n; ++i) add(sum, ans[i]);
        cout << sum << endl;
    }

    return 0;
}
