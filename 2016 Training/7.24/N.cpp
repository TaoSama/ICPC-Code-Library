//
//  Created by TaoSama on 2016-07-24
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
const int N = 400 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int x, y, n, d;
int vx[N], vy[N];

const int OFF = 200;
int f[N][N][3];

int dis(int x, int y) {
    x -= OFF; y -= OFF;
    return x * x + y * y;
}

int dfs(int x, int y, int z) {
    int& ret = f[x][y][z];
    if(~ret) return ret;
//    printf("%d %d\n", x, y);
    set<int> s;
    if(z < 2) {
        int nx = x, ny = y;
        swap(nx, ny);
        if(dis(nx, ny) <= d) s.insert(dfs(nx, ny, z + 1));
    }
    for(int i = 1; i <= n; ++i) {
        int nx = x + vx[i], ny = y + vy[i];
        if(dis(nx, ny) > d) continue;
        s.insert(dfs(nx, ny, z));
    }
    for(int i = 0; ; ++i) if(!s.count(i)) return ret = i;
    return -1;
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);
    clock_t _ = clock();

    while(scanf("%d%d%d%d", &x, &y, &n, &d) == 4) {
        x += OFF; y += OFF;
        d *= d;
        for(int i = 1; i <= n; ++i) scanf("%d%d", vx + i, vy + i);
        memset(f, -1, sizeof f);
//        prln(dfs(x, y, 0));
        puts(dfs(x, y, 0) ? "Anton" : "Dasha");
    }

#ifdef LOCAL
    printf("\nTime cost: %.2fs\n", 1.0 * (clock() - _) / CLOCKS_PER_SEC);
#endif
    return 0;
}
