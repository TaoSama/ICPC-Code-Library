//
//  Created by TaoSama on 2016-08-01
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

int n, val[N];
int rt, ls[N], rs[N];
int minv[N], maxv[N], dep[N];
double f[N];

void dfs1(int u) {
    if(!ls[u]) {
        minv[u] = maxv[u] = val[u];
        return;
    }

    int v1 = ls[u], v2 = rs[u];
    dfs1(v1);
    dfs1(v2);

    minv[u] = minv[v1];
    maxv[u] = maxv[v2];
}

void dfs2(int u) {
    if(!ls[u]) return;

    int v1 = ls[u], v2 = rs[u];
    dep[v1] = dep[v2] = dep[u] + 1;
    f[v1] = f[u] + minv[v2];
    f[v2] = f[u] + maxv[v1];

    dfs2(v1);
    dfs2(v2);
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    scanf("%d", &n);

    vector<pair<int, int> > keys;
    for(int i = 1; i <= n; ++i) {
        int fa; scanf("%d%d", &fa, val + i);
        if(fa == -1) rt = i;
        else if(!ls[fa]) ls[fa] = i;
        else rs[fa] = i;
        if(val[ls[fa]] > val[rs[fa]]) swap(ls[fa], rs[fa]);
        keys.push_back({val[i], i});
    }
    sort(keys.begin(), keys.end());

    dfs1(rt);
    dfs2(rt);

    int q; scanf("%d", &q);
    while(q--) {
        int x; scanf("%d", &x);
        auto iter = upper_bound(keys.begin(), keys.end(), make_pair(x, -INF));
        if(iter == keys.end()) --iter;
        if(ls[iter->second]) --iter; //must be leaves
        int y = iter->second;
        printf("%.10f\n", f[y] / dep[y]);
    }


    return 0;
}
