//
//  Created by TaoSama on 2016-07-23
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
#include <bitset>

using namespace std;
#define pr(x) cout << #x << " = " << x << "  "
#define prln(x) cout << #x << " = " << x << endl
const int N = 2e6 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;
const int M = 500 + 10;

int n;
char s[N], t[M];
typedef bitset<M> Sta;
Sta f[2], g[256]; //f[M][N]

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);
    clock_t _ = clock();

    while(gets(s + 1)) {
        scanf(" %d", &n);
        for(int i = 0; i < 256; ++i) g[i].reset();
        for(int i = 1; i <= n; ++i) {
            int cnt; scanf("%d%s", &cnt, t + 1);
            for(int j = 1; j <= cnt; ++j) g[t[j]][i] = 1;
        }

        bool ok = false;

        int p = 0;
        f[p].reset();
        f[p][0] = 1;
        for(int i = 1; s[i]; ++i) {
            f[!p] = (f[p] << 1) & g[s[i]];
            f[!p][0] = 1;
            if(f[!p][n]) {
                ok = true;
                printf("%d\n", i - n + 1);
            }
            p = !p;
        }
        if(!ok) puts("NULL");
        scanf("%*c");
    }

#ifdef LOCAL
    printf("\nTime cost: %.2fs\n", 1.0 * (clock() - _) / CLOCKS_PER_SEC);
#endif
    return 0;
}
