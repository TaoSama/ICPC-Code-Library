//
//  Created by TaoSama on 2015-07-14
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

int n, a[N], to[N], cnt[N], q[N], sz;
int ans;
bool vis[N];

void dfs(int x, int k) {
    if(x < 1 || x > 100000 || vis[x]) return;

    vis[x] = true;
    q[++sz] = x;
    cnt[x] += k;
    if(++to[x] == n) ans = min(ans, cnt[x]);
    dfs(x << 1, k + 1);
    dfs(x >> 1, k + 1);
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(cin >> n) {
        for(int i = 1; i <= n; ++i) cin >> a[i];

        ans = INF;
        memset(vis, false, sizeof vis);
        memset(to, 0, sizeof to);
        memset(cnt, 0, sizeof cnt);
        for(int i = 1; i <= n; ++i) {
            sz = 0;
            dfs(a[i], 0);
            for(int j = 1; j <= sz; ++j) vis[q[j]] = false;
        }

        cout << ans << '\n';
    }
    return 0;
}
