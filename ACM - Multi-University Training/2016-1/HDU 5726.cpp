//
//  Created by TaoSama on 2016-07-20
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

int n, a[N];
vector<pair<int, int> > f[2];
map<int, LL> mp;
int g[17][N];

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);
    clock_t _ = clock();

    int t; scanf("%d", &t);
    while(t--) {
        scanf("%d", &n);
        for(int i = 1; i <= n; ++i) scanf("%d", a + i);

        mp.clear();

        int p = 0; f[p].clear();
        f[p].push_back({0, 1});
        for(int i = 1; i <= n; ++i) {
            f[!p].clear(); f[!p].push_back({0, 1});
            for(auto& u : f[p]) {
                int x, cnt; tie(x, cnt) = u;
                x = __gcd(x, a[i]);

                bool ok = true;
                for(auto& v : f[!p]) {
                    if(x == v.first) {
                        ok = false;
                        v.second += cnt;
                        break;
                    }
                }
                if(ok) f[!p].push_back({x, cnt});
//                printf("%d: %d %d\n", i, x, cnt);
                mp[x] += cnt; //global
            }
            p = !p;
        }

        for(int i = 1; i <= n; ++i) g[0][i] = a[i];

        for(int i = 1; 1 << i <= n; ++i)
            for(int j = 1; j <= n; ++j)
                g[i][j] = __gcd(g[i - 1][j], g[i - 1][j + (1 << i - 1)]);

        static int kase = 0;
        printf("Case #%d:\n", ++kase);

        int q; scanf("%d", &q);
        while(q--) {
            int l, r; scanf("%d%d", &l, &r);
            int k = 31 - __builtin_clz(r - l + 1);
            int gcd = __gcd(g[k][l], g[k][r - (1 << k) + 1]);
            printf("%d %I64d\n", gcd, mp[gcd]);
        }
    }

#ifdef LOCAL
    printf("\nTime cost: %.2fs\n", 1.0 * (clock() - _) / CLOCKS_PER_SEC);
#endif
    return 0;
}
