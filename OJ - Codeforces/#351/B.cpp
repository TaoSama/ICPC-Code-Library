//
//  Created by TaoSama on 2016-05-07
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

int n, m;
vector<int> G[N];

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);
    clock_t _ = clock();

    while(scanf("%d%d", &n, &m) == 2) {
        for(int i = 1; i <= n; ++i) G[i].clear();

        bool ok = true;
        set<int> s, lft, rig;
        for(int i = 1; i <= m; ++i) {
            int u, v; scanf("%d%d", &u, &v);
            s.insert(u); s.insert(v);
            if(u > v) swap(u, v);
            if(rig.count(u) || lft.count(v)) ok = false;
            lft.insert(u); rig.insert(v);
        }
        if(lft.size() && rig.size()) {
            if(*lft.rbegin() >= *rig.begin()) ok = false;
        }

        int ans = 0;
        for(int i = 1; i <= n; ++i) {
            if(s.count(i) || !lft.size()) continue;
            if(i > *lft.rbegin() && i < *rig.begin()) ++ans;
        }

        if(!ok) puts("0");
        else {
            if(!lft.size()) ans = n - 1;
            else ++ans;
            printf("%d\n", ans); // C(n + 2 - 1, 2 - 1)
        }
    }

#ifdef LOCAL
    printf("\nTime cost: %.2fs\n", 1.0 * (clock() - _) / CLOCKS_PER_SEC);
#endif
    return 0;
}
