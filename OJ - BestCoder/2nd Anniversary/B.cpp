//
//  Created by TaoSama on 2016-07-17
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
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 998244353;

int n, b[N], c[N];

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);
    clock_t _ = clock();

    int t; scanf("%d", &t);
    while(t--) {
        scanf("%d", &n);
        for(int i = 1; i <= n; ++i) scanf("%d", b + i);
        for(int i = 1; i <= n; ++i) scanf("%d", c + i);

        if(b[1] != c[1]) {
            puts("0");
            continue;
        }

        long long ans = 1;
        int cnt = 0;
        for(int i = 2; i <= n; ++i) {
            int diff = 0;
            diff += b[i] != b[i - 1];
            diff += c[i] != c[i - 1];
//            printf("%d: %d\n", i, diff);
            if(b[i] > b[i - 1] || c[i] < c[i - 1] || b[i] > c[i]
                    || diff == 2) {
                ans = 0;
                break;
            }
            if(diff == 0) {
                int lft = c[i] - b[i] - 1;
                lft -= cnt;
                if(lft <= 0) {
                    ans = 0;
                    break;
                }
                ans *= lft;
                ans %= MOD;
            }
            if(i != 2) cnt++;
        }
        printf("%I64d\n", ans);
    }

#ifdef LOCAL
    printf("\nTime cost: %.2fs\n", 1.0 * (clock() - _) / CLOCKS_PER_SEC);
#endif
    return 0;
}
