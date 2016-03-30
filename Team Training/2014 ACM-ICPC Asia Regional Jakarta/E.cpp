//
//  Created by TaoSama on 2015-12-21
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

using namespace std;
#define pr(x) cout << #x << " = " << x << "  "
#define prln(x) cout << #x << " = " << x << endl
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, q, ans[N];
int fa[N], a[N], b[N], removed[N];

int par[N];
int find(int x) {
    return par[x] = par[x] == x ? x : find(par[x]);
}

void unite(int x, int y) {
    x = find(x); y = find(y);
    par[x] = y;
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int t; scanf("%d", &t);
    while(t--) {
        scanf("%d%d", &n, &q);
        for(int i = 1; i <= n; ++i) scanf("%d", fa + i);
        memset(removed, 0, sizeof removed);
        for(int i = 1; i <= q; ++i) {
            char op[5]; b[i] = 0;
            scanf("%s%d", op, a + i);
            if(*op == 'Q') scanf("%d", b + i);
            else ++removed[a[i]];
        }

        for(int i = 1; i <= n; ++i) par[i] = i;
        for(int i = 1; i <= n; ++i) {
            if(!fa[i] || removed[i]) continue;
            unite(i, fa[i]);
        }
        for(int i = q; i; --i) {
            if(b[i]) ans[i] = find(a[i]) == find(b[i]);
            else if(--removed[a[i]] == 0 && fa[a[i]])
                unite(a[i], fa[a[i]]);
        }

        static int kase = 0;
        printf("Case #%d:\n", ++kase);
        for(int i = 1; i <= q; ++i)
            if(b[i]) puts(ans[i] ? "YES" : "NO");
    }
    return 0;
}
