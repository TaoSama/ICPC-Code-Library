//
//  Created by TaoSama on 2016-03-07
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
#include <bitset>

using namespace std;
#define pr(x) cout << #x << " = " << x << "  "
#define prln(x) cout << #x << " = " << x << endl
const int N = 2500, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, a[N][N];
bitset<N> b[N];
pair<int, pair<int, int> > q[N * N];

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    scanf("%d", &n);
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            scanf("%d", a[i] + j);
            q[i * n + j] = {a[i][j], {i, j}};
        }
    }
    sort(q, q + n * n);
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < n; ++j)
            if(i == j && a[i][j] || a[i][j] != a[j][i])
                return puts("NOT MAGIC");

    int idx = 0;
    for(int i = 0; i < n * n; ++i) {
        auto wh = q[i].second;
        int x = wh.first, y = wh.second;
        while(q[idx].first < a[x][y]) {
            wh = q[idx].second;
            b[wh.first][wh.second] = 1;
            ++idx;
        }
        if((b[x] & b[y]).any()) return puts("NOT MAGIC");
    }
    puts("MAGIC");
    return 0;
}
