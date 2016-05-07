//
//  Created by TaoSama on 2016-05-07
//  Copyright (c) 2016 TaoSama. All rights reserved.
//
#pragma comment(linker, "/STACK:102400000,102400000")
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
const int N = 1e4 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, w;
int a[N], f[N][105];

void print(int n, int w, vector<int>& path) {
    if(!w) return;
    if(w >= a[n] && f[n - 1][w - a[n]]) {
        print(n - 1, w - a[n], path);
        path.push_back(a[n]);
    } else print(n - 1, w, path);
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);
    clock_t _ = clock();

    while(scanf("%d%d", &n, &w) == 2) {
        for(int i = 1; i <= n; ++i) scanf("%d", a + i);
        sort(a + 1, a + 1 + n);
        reverse(a + 1, a + 1 + n);

        memset(f, 0, sizeof f);
        f[0][0] = 1;
        for(int i = 1; i <= n; ++i) {
            for(int j = 0; j <= w; ++j) {
                f[i][j] |= f[i - 1][j];
                if(j >= a[i]) f[i][j] |= f[i - 1][j - a[i]];
            }
        }
        if(!f[n][w]) {
            puts("No Solution");
            continue;
        }
        vector<int> path;
        print(n, w, path);
        for(int i = path.size() - 1; ~i; --i)
            printf("%d%c", path[i], " \n"[i == 0]);
    }

#ifdef LOCAL
    printf("\n\nTime cost: %.2fs\n", 1.0 * (clock() - _) / CLOCKS_PER_SEC);
#endif
    return 0;
}
