//
//  Created by TaoSama on 2016-06-30
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
const int N = 500 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, m;
int a[N];
int f[2][N][N];

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);
    clock_t _ = clock();

    while(scanf("%d%d", &n, &m) == 2) {
        for(int i = 1; i <= n; ++i) scanf("%d", a + i);

        int p = 0;
        memset(f[p], 0, sizeof f[p]);
        f[p][0][0] = 1;
        for(int i = 1; i <= n; ++i) {
            memset(f[!p], 0, sizeof f[!p]);
            for(int j = 0; j <= m; ++j) {
                for(int k = 0; k <= m; ++k) {
                    f[!p][j][k] |= f[p][j][k];
                    if(j >= a[i]) {
                        f[!p][j][k] |= f[p][j - a[i]][k];
                        if(k >= a[i]) f[!p][j][k] |= f[p][j - a[i]][k - a[i]];
                    }
                }
            }
            p = !p;
        }

        vector<int> ans;
        for(int i = 0; i <= m; ++i) if(f[p][m][i]) ans.push_back(i);

        printf("%d\n", ans.size());
        for(int i = 0; i < ans.size(); ++i)
            printf("%d%c", ans[i], " \n"[i == ans.size() - 1]);
    }

#ifdef LOCAL
    printf("\nTime cost: %.2fs\n", 1.0 * (clock() - _) / CLOCKS_PER_SEC);
#endif
    return 0;
}
