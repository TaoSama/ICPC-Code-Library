//
//  Created by TaoSama on 2017-03-21
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
#define pr(x) cerr << #x << " = " << x << "  "
#define prln(x) cerr << #x << " = " << x << endl
const int N = 200 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, p, q;
int a[N][N], s[N][N];

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int t; scanf("%d", &t);
    while(t--) {
        memset(a, 0, sizeof a);
        scanf("%d%d%d", &n, &p, &q);
        int minv = 1, maxv = n * n, f = 0, x = 1, y = 0;
        auto get = [&]() {
            f ^= 1;
            return f ? minv++ : maxv--;
        };
        while(minv <= maxv) {
            while(y + 1 <= n && !a[x][y + 1]) a[x][++y] = get();
            while(x + 1 <= n && !a[x + 1][y]) a[++x][y] = get();
            while(y - 1 >= 1 && !a[x][y - 1]) a[x][--y] = get();
            while(x - 1 >= 1 && !a[x - 1][y]) a[--x][y] = get();
        }

        for(int i = 1; i <= n; ++i) {
            for(int j = 1; j <= n; ++j) {
                s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + a[i][j];
//                printf("%d %d\n", a[i][j], s[i][j]);
            }
//            puts("");
        }

        auto rect = [&](int x, int y) {
            int x1 = x, y1 = y, x2 = x1 + p - 1, y2 = y1 + q - 1;
            return s[x2][y2] + s[x1 - 1][y1 - 1] - s[x2][y1 - 1] - s[x1 - 1][y2];
        };

        pair<int, pair<int, int>> ans = {0, {0, 0}};
        for(int i = 1; i + p - 1 <= n; ++i)
            for(int j = 1; j + q - 1 <= n; ++j)
                ans = max(ans, {rect(i, j), { -i, -j}});
        printf("%d %d %d\n", ans.first, -ans.second.first, -ans.second.second);
    }

    return 0;
}
