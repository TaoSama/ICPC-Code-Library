//
//  Created by TaoSama on 2017-04-13
//  Copyright (c) 2017 TaoSama. All rights reserved.
//
#pragma comment(linker, "/STACK:102400000,102400000")
#include <bits/stdc++.h>

using namespace std;
#define pr(x) cerr << #x << " = " << x << "  "
#define prln(x) cerr << #x << " = " << x << endl
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int f[105][105];

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int n, m; cin >> n >> m;
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= n; ++j)
            f[i][j] = i == j ? : INF;
    for(int i = 1; i <= m; ++i) {
        int a, b, c; cin >> a >> b >> c;
        f[a][b] = f[b][a] = min(f[b][a], c);
    }

    for(int k = 1; k <= n; ++k)
        for(int i = 1; i <= n; ++i)
            for(int j = 1; j <= n; ++j)
                f[i][j] = min(f[i][j], f[i][k] + f[k][j]);

    pair<int, int> ans = {INF, INF};
    for(int i = 1; i <= n; ++i) {
        int cur = 0;
        for(int j = 1; j <= n; ++j) cur = max(cur, f[i][j]);
        ans = min(ans, {cur, i});
    }
    if(ans.first == INF) cout << 0 << endl;
    else cout << ans.second << ' ' << ans.first << endl;

    return 0;
}
