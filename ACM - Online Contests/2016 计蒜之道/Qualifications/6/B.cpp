//
//  Created by TaoSama on 2016-06-11
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
int n;
vector<int> G[N], T[N];
int r[N], p[N];

void dfs(int u, int f) {
    for(int v : G[u]) {
        if(v == f) continue;
        T[u].push_back(v);
        dfs(v, u);
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
        for(int i = 0; i < n; ++i) {
            scanf("%d%d", r + i, p + i);
            G[i].clear();
            T[i].clear();
        }
        for(int i = 1; i < n; ++i) {
            int x, y; scanf("%d%d", &x, &y);
            --x; --y;
            G[x].push_back(y);
            G[y].push_back(x);
        }
        dfs(0, -1);


        LL ans = -1e18;
        for(int i = 0; i < 1 << n; ++i) {
            int b[20] = {};
            for(int j = 0; j < n; ++j)
                if(i >> j & 1) b[j] = r[j];
                else b[j] = p[j];
            LL tmp = 0;
            for(int j = 0; j < n; ++j) {
                int maxv, minv;
                maxv = minv = b[j];
                for(int son : T[j]) {
                    maxv = max(maxv, b[son]);
                    minv = min(minv, b[son]);
                }
                LL diff = maxv - minv;
                LL delta = 1LL * (diff + 999) / 1000 * 666 * (j + 1);
                tmp += b[j] - delta;
            }
            ans = max(ans, tmp);
        }
        printf("%lld\n", ans);
    }

#ifdef LOCAL
    printf("\nTime cost: %.2fs\n", 1.0 * (clock() - _) / CLOCKS_PER_SEC);
#endif
    return 0;
}
