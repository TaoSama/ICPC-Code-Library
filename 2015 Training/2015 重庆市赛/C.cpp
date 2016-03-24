//
//  Created by TaoSama on 2015-11-19
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

int n, a[15][15];

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int kase = 0;
    while(scanf("%d", &n) == 1) {
        memset(a, 0, sizeof a);
        int x, y, cnt = a[x = 1][y = 1] = 1;
        while(cnt < n * n) {
            while(y + 1 <= n && !a[x][y + 1]) a[x][++y] = ++cnt;
            while(x + 1 <= n && !a[x + 1][y]) a[++x][y] = ++cnt;
            while(y - 1 >= 1 && !a[x][y - 1]) a[x][--y] = ++cnt;
            while(x - 1 >= 1 && !a[x - 1][y]) a[--x][y] = ++cnt;
        }
        if(kase++) puts("");
        for(x = 1; x <= n; ++x) {
            for(y = 1; y <= n; ++y)
                printf("%3d", a[x][y]);
            puts("");
        }
    }
    return 0;
}
