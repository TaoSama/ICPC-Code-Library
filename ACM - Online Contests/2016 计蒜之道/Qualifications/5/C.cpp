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

int n, q, need[N];
vector<int> G[N];

void change(int x, int a, int y, int b) {
    vector<int> tmp[2];
    tmp[0].resize(a);
    tmp[1].resize(b);
    copy(G[x].begin(), G[x].begin() + a, tmp[0].begin());
    G[x].erase(G[x].begin(), G[x].begin() + a);
    copy(G[y].begin(), G[y].begin() + b, tmp[1].begin());
    G[y].erase(G[y].begin(), G[y].begin() + b);

    G[x].insert(G[x].begin(), tmp[1].begin(), tmp[1].end());
    G[y].insert(G[y].begin(), tmp[0].begin(), tmp[0].end());
}

void calc(int i) {
    need[i] = 0;
    int cur = 0;
    for(int x : G[i]) {
        int nxt = max(cur, x);
        need[i] += nxt - cur;
        cur = nxt;
        ++cur;
    }
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);
    clock_t _ = clock();

    scanf("%d", &n);
    for(int i = 1; i <= n; ++i) {
        int cnt; scanf("%d", &cnt);
        while(cnt--) {
            int x; scanf("%d", &x);
            G[i].push_back(x);
        }
    }
    for(int i = 1; i <= n; ++i)  calc(i);

    int q; scanf("%d", &q);
    while(q--) {
        int x, a, y, b; scanf("%d%d%d%d", &x, &a, &y, &b);
        change(x, a, y, b);
        calc(x); calc(y);

        vector<pair<int, int> > v;
        for(int i = 1; i <= n; ++i) v.push_back({need[i], i});
        sort(v.begin(), v.end());

        int ans = 0, cur = 0;
        for(auto i : v) {
            int x = i.second;
            for(int y : G[x]) {
                int nxt = max(cur, y);
                ans += nxt - cur;
                cur = nxt;
                ++cur;
            }
        }
        printf("%d\n", ans);

//        for(auto u : G[x]) printf("%d ", u); puts("");
//        for(auto v : G[y]) printf("%d ", v); puts("");

    }

#ifdef LOCAL
    printf("\nTime cost: %.2fs\n", 1.0 * (clock() - _) / CLOCKS_PER_SEC);
#endif
    return 0;
}
