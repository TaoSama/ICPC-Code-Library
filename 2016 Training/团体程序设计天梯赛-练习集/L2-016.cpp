//
//  Created by TaoSama on 2016-07-16
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

int n;
int ge[N], fa[N], mo[N];

vector<int> up(int x) {
    vector<int> ret;
    queue<pair<int, int> > q; q.push({x, 1});
    while(q.size()) {
        int u, d; tie(u, d) = q.front(); q.pop();
        ret.push_back(u);
        if(d == 5) continue;
        if(~fa[u]) q.push({fa[u], d + 1});
        if(~mo[u]) q.push({mo[u], d + 1});
    }
    sort(ret.begin(), ret.end());
    return ret;
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);
    clock_t _ = clock();

    scanf("%d", &n);
    memset(fa, -1, sizeof fa);
    memset(mo, -1, sizeof mo);
    for(int i = 1; i <= n; ++i) {
        int x; char g[2]; int f, m;
        scanf("%d%s%d%d", &x, g, &f, &m);
        ge[f] = 1; ge[m] = 0;
        ge[x] = *g == 'M';
        fa[x] = f;
        mo[x] = m;
    }

    int q; scanf("%d", &q);
    while(q--) {
        int u, v; scanf("%d%d", &u, &v);
        if(!(ge[u] ^ ge[v])) {
            puts("Never Mind");
            continue;
        }

        vector<int> a = up(u);
        vector<int> b = up(v);
        static auto lam = [](vector<int>& a) {
            for(auto x : a) printf("%d ", x); puts("");
        };
//      lam(a); lam(b);
//      puts("");
        vector<int> c(max(a.size(), b.size()), -1);
//      prln(c.size());
        set_intersection(a.begin(), a.end(), b.begin(), b.end(), c.begin());
//      prln(c.size());
        bool ok = true;
        for(int x : c) {
            if(~x) {
                ok = false;
                break;
            }
        }
        puts(ok ? "Yes" : "No");
    }

#ifdef LOCAL
    printf("\nTime cost: %.2fs\n", 1.0 * (clock() - _) / CLOCKS_PER_SEC);
#endif
    return 0;
}
