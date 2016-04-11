//
//  Created by TaoSama on 2015-06-30
//  Copyright (c) 2015 TaoSama. All rights reserved.
//
//#pragma comment(linker, "/STACK:1024000000,1024000000")
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

int n, m, c[N];
long long ans[5], cnt[2];
vector<int> G[N];

bool dfs(int u, int cc) {
    c[u] = cc; cnt[cc]++;
    for(int i = 0; i < G[u].size(); ++i) {
        int v = G[u][i];
        if(c[v] == cc) return false;
        if(c[v] == -1 && !dfs(v, cc ^ 1)) return false;
    }
    return true;
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(cin >> n >> m) {
        for(int i = 1; i <= n; ++i) G[i].clear();
        for(int i = 1; i <= m; ++i) {
            int u, v; cin >> u >> v;
            G[u].push_back(v);
            G[v].push_back(u);
        }
        memset(c, -1, sizeof c);
        memset(ans, 0, sizeof ans);

        if(m == 0) ans[3] = 1LL * n * (n - 1) * (n - 2) / 6;

        bool two = true;
        for(int i = 1; i <= n; ++i) two &= G[i].size() <= 1;
        if(two) ans[2] = 1LL * m * (n - 2);

        bool zero = false;
        for(int i = 1; i <= n; ++i) {
            memset(cnt, 0, sizeof cnt);
            if(c[i] == - 1 && !dfs(i, 0)) {
                zero = true;
                break;
            } else ans[1] += cnt[0] * (cnt[0] - 1) / 2 + cnt[1] * (cnt[1] - 1) / 2;
        }

        if(zero) cout << "0 1\n";
        else if(ans[1]) cout << 1 << ' ' << ans[1] << '\n';
        else if(ans[2]) cout << 2 << ' ' << ans[2] << '\n';
        else cout << 3 << ' ' << ans[3] << '\n';
    }
    return 0;
}
