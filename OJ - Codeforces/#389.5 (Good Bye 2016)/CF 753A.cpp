//
//  Created by TaoSama on 2016-12-30
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

int n, f[1005][1005], g[1005][1005];

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d", &n) == 1) {
        memset(f, 0xc0, sizeof f);
        f[0][0] = g[0][0] = 0;
        for(int i = 1; i <= 1000; ++i) {
            for(int j = 0; j <= n; ++j) {
                f[i][j] = f[i - 1][j];
                g[i][j] = j;
                if(j >= i) {
                    if(f[i - 1][j - i] + 1 > f[i][j]) {
                        f[i][j] = f[i - 1][j - i] + 1;
                        g[i][j] = j - i;
                    }
                }
            }
        }
        printf("%d\n", f[1000][n]);
        vector<int> path;
        int x = 1000, y = n;
        while(true) {
            int t = y - g[x][y];
            if(t) path.push_back(t);
            if(!g[x][y]) break;
            y = g[x][y];
            --x;
        }
        for(int x : path) printf("%d ", x); puts("");
    }

    return 0;
}
