//
//  Created by TaoSama on 2016-06-18
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
struct Edge {
    int v, c;
};
vector<Edge> G[N];

int n, a[N], fa[N];
bool sadSon[N];

void dfs(int u, int f, LL sum, LL minp) {
    for(Edge e : G[u]) {
        int v = e.v, c = e.c;
        if(v == f) continue;
        fa[v] = u;
        LL newSum = sum + c;
        LL newMinp = min(minp, newSum);
//        printf("%d: sum = %lld minp = %lld a = %d\n", v, newSum, newMinp, a[v]);
        if(newSum - newMinp > a[v]) sadSon[v] = true;
        dfs(v, u, newSum, newMinp);
    }
}

void dfs2(int u, int f, int& lft) {
    ++lft;
    for(Edge e : G[u]) {
        int v = e.v;
        if(v == f) continue;
        if(sadSon[v]) continue;
        dfs2(v, u, lft);
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
    for(int i = 1; i <= n; ++i) scanf("%d", a + i);
    for(int i = 2; i <= n; ++i) {
        int p, c; scanf("%d%d", &p, &c);
        G[p].push_back({i, c});
        G[i].push_back({p, c});
    }

    dfs(1, -1, 0, 0);

    int lft = 0;
    dfs2(1, -1, lft);
    printf("%d\n", n - lft);


#ifdef LOCAL
    printf("\nTime cost: %.2fs\n", 1.0 * (clock() - _) / CLOCKS_PER_SEC);
#endif
    return 0;
}
