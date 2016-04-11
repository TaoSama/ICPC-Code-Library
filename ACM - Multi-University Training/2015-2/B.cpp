//
//  Created by TaoSama on 2016-03-17
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

int n, m, x0, y0;

int get(int x, int y) {
    if(x == x0 && y == y0) return 0;
    int u = x, d = n - x + 1, l = y, r = m - y + 1;
    //cross the obstacle
    if(x == x0) {
        if(y > y0) l = INF;
        else r = INF;
    }
    if(y == y0) {
        if(x > x0) u = INF;
        else d = INF;
    }
    return min(min(u, d), min(l, r));
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d%d%d%d", &n, &m, &x0, &y0) == 4) {
        //just one center, because of symmetric
        int ans = get(n + 1 >> 1, m + 1 >> 1);

        //even if the obstacle occupying the center, but we still ensure the answer
        //since iterating the 4 directions, one center must be included
        int d[][2] = { -1, 0, 0, -1, 1, 0, 0, 1};
        for(int i = 0; i < 4; ++i) {
            int x = x0 + d[i][0], y = y0 + d[i][1];
            if(x < 1 || x > n || y < 1 || y > m) continue;
            ans = max(ans, get(x, y));
        }
        printf("%d\n", ans);
    }
    return 0;
}
