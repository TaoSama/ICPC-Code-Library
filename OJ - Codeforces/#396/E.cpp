//
//  Created by TaoSama on 2017-02-08
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

int n, a[N], s[N];
vector<int> G[N];

typedef long long LL;
LL cnt[N][20][2], f[20];
void dfs(int u, int fa) {
    s[u] = s[fa] ^ a[u];
    for(int i = 0; i < 20; ++i) {
        f[i] += a[u] >> i & 1;
        ++cnt[u][i][s[u] >> i & 1];
    }
    for(int v : G[u]) {
        if(v == fa) continue;
        dfs(v, u);
        for(int i = 0; i < 20; ++i) {
            int b = a[u] >> i & 1;
            for(int j = 0; j < 2; ++j)
                f[i] += cnt[u][i][j ^ b] * cnt[v][i][j ^ 1];
            for(int j = 0; j < 2; ++j)
                cnt[u][i][j] += cnt[v][i][j];
        }
    }
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(cin >> n) {
        for(int i = 1; i <= n; ++i) {
            G[i].clear();
            cin >> a[i];
        }
        for(int i = 1; i < n; ++i) {
            int u, v; cin >> u >> v;
            G[u].push_back(v);
            G[v].push_back(u);
        }

        memset(f, 0, sizeof f);
        memset(cnt, 0, sizeof cnt);
        dfs(1, 0);

        long long ans = 0;
        for(int i = 0; i < 20; ++i) ans += f[i] << i;
        cout << ans << endl;

//        return 0;
    }

    return 0;
}
