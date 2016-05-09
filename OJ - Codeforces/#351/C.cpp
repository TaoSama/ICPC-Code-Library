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
const int N = 5000 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, a[N];
int cnt[N], ans[N];

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);
    clock_t _ = clock();

    while(scanf("%d", &n) == 1) {
        for(int i = 1; i <= n; ++i) scanf("%d", a + i);
        memset(ans, 0, sizeof ans);
        for(int i = 1; i <= n; ++i) {
            int cur = 0;
            memset(cnt, 0, sizeof cnt);
            for(int j = i; j <= n; ++j) {
                int c = a[j]; ++cnt[c];
                if(cnt[c] > cnt[cur] || cnt[c] == cnt[cur] && c < cur) cur = c;
                ++ans[cur];
            }
        }
        for(int i = 1; i <= n; ++i)
            printf("%d%c", ans[i], " \n"[i == n]);
    }

#ifdef LOCAL
    printf("\nTime cost: %.2fs\n", 1.0 * (clock() - _) / CLOCKS_PER_SEC);
#endif
    return 0;
}
