//
//  Created by TaoSama on 2016-06-02
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

int n, h, k;
int a[N];
typedef long long LL;

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);
    clock_t _ = clock();

    while(scanf("%d%d%d", &n, &h, &k) == 3) {
        for(int i = 1; i <= n; ++i) scanf("%d", a + i);

        LL ans = 0, cur = 0;
        for(int i = 1; i <= n || cur;) {
            while(i <= n && cur + a[i] <= h) cur += a[i++];
            if(i == n + 1) {
                ans += (cur + k - 1) / k;
                cur = 0;
            } else {
                LL delta = (cur + a[i] - h + k - 1) / k;
                ans += delta;
                cur -= min(cur, delta * k);
            }
        }
        printf("%I64d\n", ans);
    }

#ifdef LOCAL
    printf("\nTime cost: %.2fs\n", 1.0 * (clock() - _) / CLOCKS_PER_SEC);
#endif
    return 0;
}
