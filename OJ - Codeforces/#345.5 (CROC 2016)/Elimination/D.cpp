//
//  Created by TaoSama on 2016-03-19
//  Copyright (c) 2016 TaoSama. All rights reserved.
//
#pragma comment(linker, "/STACK:1024000000,1024000000")
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
int u[N], v[N];
vector<int> G[N];

bool check(int m) {
    for(int i = 1; i <= n; ++i) G[i].clear();
    vector<int> in(n + 1, 0);
    for(int i = 1; i <= m; ++i) {
        G[u[i]].push_back(v[i]);
        ++in[v[i]];
    }
    queue<int> q;
    for(int i = 1; i <= n; ++i) if(!in[i]) q.push(i);
    while(q.size()) {
        int u = q.front(); q.pop();
        if(q.size()) return false;
        for(int v : G[u])
            if(--in[v] == 0) q.push(v);
    }
    return true;
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    scanf("%d%d", &n, &m);
    for(int i = 1; i <= m; ++i) scanf("%d%d", u + i, v + i);
    int l = 1, r = m;
    while(l <= r) {
        int m = l + r >> 1;
        if(check(m)) r = m - 1;
        else l = m + 1;
    }
    if(l == m + 1) l = -1;
    printf("%d\n", l);
    return 0;
}
