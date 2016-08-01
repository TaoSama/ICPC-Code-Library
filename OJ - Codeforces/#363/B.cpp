//
//  Created by TaoSama on 2016-07-19
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

int n, m;
char s[N][N];

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);
    clock_t _ = clock();

    while(scanf("%d%d", &n, &m) == 2) {
        vector<int> row(n + 1, 0), col(m + 1, 0);

        for(int i = 1; i <= n; ++i) {
            scanf("%s", s[i] + 1);
        }
        for(int i = 1; i <= n; ++i)
            for(int j = 1; j <= m; ++j)
                row[i] += s[i][j] == '*';
        for(int j = 1; j <= m; ++j)
            for(int i = 1; i <= n; ++i)
                col[j] += s[i][j] == '*';

        int all = accumulate(row.begin(), row.end(), 0);
//      prln(all);

        bool ok = false;
        for(int i = 1; i <= n; ++i) {
            for(int j = 1; j <= m; ++j) {
                int cur = row[i] + col[j] - (s[i][j] == '*');
                if(cur == all) {
                    ok = true;
                    puts("YES");
                    printf("%d %d\n", i, j);
                    break;
                }
            }
            if(ok) break;
        }
        if(!ok) puts("NO");
    }

#ifdef LOCAL
    printf("\nTime cost: %.2fs\n", 1.0 * (clock() - _) / CLOCKS_PER_SEC);
#endif
    return 0;
}
