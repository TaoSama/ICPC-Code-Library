//
//  Created by TaoSama on 2016-06-18
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
const int N = 1e3 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, m, K;
char s[N], t[N];
int f[N][N][15];
int lcp[N][N];

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);
    clock_t _ = clock();

    while(scanf("%d%d%d", &n, &m, &K) == 3) {
        scanf("%s%s", s + 1, t + 1);

        memset(lcp, 0, sizeof lcp);
        for(int i = n; i; --i)
            for(int j = m; j; --j)
                if(s[i] == t[j]) lcp[i][j] = lcp[i + 1][j + 1] + 1;
//      for(int i = 1; i <= n; ++i)
//          for(int j = 1; j <= m; ++j)
//              printf("lcp[%d][%d] = %d\n", i, j, lcp[i][j]);

        f[0][0][0] = 0;
        for(int i = 0; i <= n; ++i) {
            for(int j = 0; j <= m; ++j) {
                for(int k = 0; k <= K; ++k) {
                    int c = lcp[i + 1][j + 1];
//                    if(i == 5 && j == 10 && k == 2) {
//                    printf("s[%d] = %c\n", i + 1, s[i + 1]);
//                    printf("t[%d] = %c\n", j + 1, t[j + 1]);
//                    printf("lcp = %d\n", c);
//                    printf("f[%d][%d][%d] = %d\n", i, j, k, f[i][j][k]);
//                    }
                    f[i + c][j + c][k + 1] =
                        max(f[i + c][j + c][k + 1], f[i][j][k] + c);
                    f[i + 1][j][k] = max(f[i + 1][j][k], f[i][j][k]);
                    f[i][j + 1][k] = max(f[i][j + 1][k], f[i][j][k]);
                }
            }
        }

        auto see = [&](int i, int j, int k) {
            printf("f[%d][%d][%d] = %d\n", i, j, k, f[i][j][k]);
        };
//        see(n, m, K);
//        see(3, 5, 1);
//        see(5, 9, 2);
//        see(6, 11, 3);
//        see(5, 10, 2);

        int ans = 0;
        for(int i = 1; i <= K; ++i) {
            if(f[n][m][i] >= K) ans = max(ans, f[n][m][i]);
        }
        printf("%d\n", ans);
    }

#ifdef LOCAL
    printf("\nTime cost: %.2fs\n", 1.0 * (clock() - _) / CLOCKS_PER_SEC);
#endif
    return 0;
}
