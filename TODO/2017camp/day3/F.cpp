//
//  Created by TaoSama on 2017-02-14
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

int n, w[N];
vector<int> G[N];

int pos[N], z[N], f[N], ans[N];

int query(int u) {
    int ret = z[u];
    if((u << 1) <= n) ret += max(f[u << 1], 0);
    if((u << 1 | 1) <= n) ret += max(f[u << 1 | 1], 0);

    int up = 0, cur = 0;
    while(u != 1) {
        int fa = u >> 1;
        cur += z[fa];
        cur += max(f[u ^ 1], 0);
        up = max(up, cur);
        u = fa;
    }
    ret += up;
    return ret;
}

void update(int u) {
    f[u] = z[u];
    if((u << 1) <= n) f[u] += max(f[u << 1], 0);
    if((u << 1 | 1) <= n) f[u] += max(f[u << 1 | 1], 0);
    while(u != 1) {
        int fa = u >> 1;
        f[fa] = z[fa];
        f[fa] += max(f[fa << 1], 0);
        f[fa] += max(f[fa << 1 | 1], 0);
        u = fa;
    }
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d", &n) == 1) {
        for(int i = 1; i <= n; ++i) scanf("%d", w + i);

        for(int i = 1; i <= n; ++i) pos[i] = i;
        sort(pos + 1, pos + 1 + n, [](int x, int y) {
            return w[x] > w[y];
        });

        for(int i = 1; i <= n + 1; ++i) z[i] = -1, ans[i] = f[i] = 0;
        for(int i = 1; i <= n; ++i) {
            int u = pos[i];
            z[u] = 1;
            int a = query(u) - 1;
            ans[a] = max(ans[a], w[u]);
            if(a) ans[a - 1] = max(ans[a - 1], w[u]);
            update(u);
        }

        for(int i = 0; i < n; ++i) printf("%d%c", ans[i], " \n"[i + 1 == n]);
    }

    return 0;
}
