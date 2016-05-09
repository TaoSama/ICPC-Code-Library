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
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, k;

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);
    clock_t _ = clock();

    while(scanf("%d%d", &n, &k) == 2) {
        int a[5];
        for(int i = 1; i <= 4; ++i) scanf("%d", a + i);
        if(n == 4 || n - 4 - 1 + 6 > k) {
            puts("-1");
            continue;
        }

        printf("%d %d ", a[1], a[3]);
        for(int i = 1; i <= n; ++i) {
            bool ok = true;
            for(int j = 1; j <= 4; ++j) if(i == a[j]) ok = false;
            if(!ok) continue;
            printf("%d ", i);
        }
        printf("%d %d\n", a[4], a[2]);

        printf("%d %d ", a[3], a[1]);
        for(int i = 1; i <= n; ++i) {
            bool ok = true;
            for(int j = 1; j <= 4; ++j) if(i == a[j]) ok = false;
            if(!ok) continue;
            printf("%d ", i);
        }
        printf("%d %d\n", a[2], a[4]);
    }

#ifdef LOCAL
    printf("\nTime cost: %.2fs\n", 1.0 * (clock() - _) / CLOCKS_PER_SEC);
#endif
    return 0;
}
