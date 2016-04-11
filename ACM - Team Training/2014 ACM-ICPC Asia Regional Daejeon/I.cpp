//
//  Created by TaoSama on 2015-12-14
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

int n, x[N], y[N], vis[N];

inline void getMin(int &x, int y) {x = min(x, y);}
inline void getMax(int &x, int y) {x = max(x, y);}

inline bool inBound(int i, int l, int r, int d, int u) {
    return x[i] >= l && x[i] <= r && y[i] >= d && y[i] <= u;
}

inline void update(int l, int r, int d, int u, bool v) {
    for(int i = 1; i <= n; ++i)
        if(inBound(i, l, r, d, u)) vis[i] = v;
}

bool dfs(int d, int l) {
    if(d > 3) {
        int cnt = 0;
        for(int i = 1; i <= n; ++i) cnt += vis[i];
        return cnt == n;
    }

    int minX = INF, maxX = -INF, minY = INF, maxY = -INF;
    for(int i = 1; i <= n; ++i) {
        if(vis[i]) continue;
        getMin(minX, x[i]);
        getMax(maxX, x[i]);
        getMin(minY, y[i]);
        getMax(maxY, y[i]);
    }

    //top left
    update(minX, minX + l, maxY - l, maxY, true);
    if(dfs(d + 1, l)) return true;
    update(minX, minX + l, maxY - l, maxY, false);

    //top right
    update(maxX - l, maxX, maxY - l, maxY, true);
    if(dfs(d + 1, l)) return true;
    update(maxX - l, maxX, maxY - l, maxY, false);

    //bottom right
    update(maxX - l, maxX, minY, minY + l, true);
    if(dfs(d + 1, l)) return true;
    update(maxX - l, maxX, minY, minY + l, false);

    //bottom left
    update(minX, minX + l, minY, minY + l, true);
    if(dfs(d + 1, l)) return true;
    update(minX, minX + l, minY, minY + l, false);

    return false;
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int t; scanf("%d", &t);
    while(t--) {
        scanf("%d", &n);
        for(int i = 1; i <= n; ++i) scanf("%d%d", x + i, y + i);

        int l = 0, r = 2e9 + 10;
        while(l <= r) {
            int m = l + r >> 1;
            memset(vis, false, sizeof vis);
            if(dfs(1, m)) r = m - 1;
            else l = m + 1;
        }
        printf("%d\n", l);
    }
    return 0;
}
