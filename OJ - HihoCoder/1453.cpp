//
//  Created by TaoSama on 2016-12-25
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
const int N = 3e3 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n;

int f[N][N];

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);


    scanf("%d", &n);
    vector<int> d(n + 1, 0);
    for(int i = 2; i <= n; ++i) {
        int f; scanf("%d", &f);
        ++d[f];
    }

    memset(f, 0x3f, sizeof f);
    f[0][1] = 0;
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= n; ++j) {
            f[i][j] = min(f[i][j], f[i - 1][j]);
            if(j - d[i] >= 1) f[i][j] = min(f[i][j], f[i - 1][j - d[i]] + 1);
        }
    }
    for(int i = 1; i <= n; ++i)
        printf("%d%c", f[n][i] == INF ? -1 : f[n][i], " \n"[i == n]);

    return 0;
}
