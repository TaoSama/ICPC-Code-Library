//
//  Created by TaoSama on 2016-10-08
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

int n, m, a[100][100];

bool check() {
    for(int i = 1; i <= n; ++i) {
        int cnt = 0;
        for(int j = 1; j <= m; ++j) {
            if(a[i][j] != j) ++cnt;
        }
        if(cnt > 2) return false;
    }
    return true;
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d%d", &n, &m) == 2) {
        for(int i = 1; i <= n; ++i)
            for(int j = 1; j <= m; ++j)
                scanf("%d", a[i] + j);

        bool ok = check();
        for(int x = 1; x <= m; ++x) {
            for(int y = x + 1; y <= m; ++y) {
                for(int i = 1; i <= n; ++i)
                    swap(a[i][x], a[i][y]);
                ok |= check();
                for(int i = 1; i <= n; ++i)
                    swap(a[i][x], a[i][y]);
            }
        }

        puts(ok ? "YES" : "NO");
    }

    return 0;
}
