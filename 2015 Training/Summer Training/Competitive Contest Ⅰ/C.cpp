//
//  Created by TaoSama on 2015-08-21
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
#include <stack>

using namespace std;
#define pr(x) cout << #x << " = " << x << "  "
#define prln(x) cout << #x << " = " << x << endl
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n;
int g[55][55], deg[55];

bool vis[55];

stack<int> x, y;

void euler(int u) {
    for(int i = 1; i <= 50; ++i) {
        if(g[u][i]) {
            g[u][i]--; g[i][u]--;
            euler(i);
            x.push(u); y.push(i);
        }
    }
}

int p[55], r[55];

void init() {
    for(int i = 1; i <= 50; ++i) p[i] = i;
    for(int i = 1; i <= 50; ++i) r[i] = 1;
}
int find(int x) {
    return p[x] = p[x] == x ? x : p[x];
}

void unite(int x, int y) {
    x = find(x); y = find(y);
    if(x == y) return ;
    if(r[x] < r[y]) p[x] = y;
    else {
        p[y] = x;
        if(r[x] == r[y]) ++r[x];
    }
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int t; scanf("%d", &t);
    int kase = 0;
    while(t--) {
        scanf("%d", &n);
        memset(g, 0, sizeof g);
        memset(deg, 0, sizeof deg);
        memset(vis, false, sizeof vis);

        int x;
        for(int i = 1; i <= n; ++i) {
            int u, v; scanf("%d%d", &u, &v);
            x = u;
            g[u][v]++; g[v][u]++;
            deg[u]++; deg[v]++;
            vis[u] = vis[v] = true;
            unite(u, v);
        }

        if(kase++) puts("");
        printf("Case #%d\n", kase);

        set<int> s;
        for(int i = 1; i <= 50; ++i) {
            if(vis[i]) s.insert(find(i));
        }
        if(s.size() != 1) {puts("some beads may be lost"); continue;}

//      for(int i = 1; i <= 6; ++i)
//          printf("%d%c", deg[i], " \n"[i == 6]);

        bool ok = true;
        for(int i = 1; i <= 50; ++i) {
            if(deg[i] & 1) {
//              printf("%d: %d\n", i, deg[i]);
                ok = false;
                break;
            }
        }
        if(!ok) {puts("some beads may be lost"); continue;}
        euler(x);
        while(x.size()) {
            printf("%d %d\n", x.top(), y.top());
            x.pop(); y.pop();
        }
    }
    return 0;
}
