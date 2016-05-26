//
//  Created by TaoSama on 2016-05-26
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

int n, k;
int a[N];

int calc(int mod) {
    int ret = 0;
    for(int i = n; ~i; --i) ret = (1LL * ret * k + a[i]) % mod;
    return ret;
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);
    clock_t _ = clock();

    while(scanf("%d%d", &n, &k) == 2) {
        int unknown = 0;
        for(int i = 0; i <= n; ++i) {
            char buf[10]; scanf("%s", buf);
            a[i] = *buf == '?' ? INF : atoi(buf);
            unknown += a[i] == INF;
        }

        int used = n + 1 - unknown;

        if(k == 0) {
            //a[0] is 0 will win
            puts(a[0] == 0 || a[0] == INF && (used & 1) ? "Yes" : "No");
        } else {
            if(!unknown) {
                bool ok = true;
                for(int i = 2e9; ; ++i) {
                    if(calc(i)) {ok = false; break;}
                    if(1.0 * (clock() - _) / CLOCKS_PER_SEC > 0.95) break;
                }
                puts(ok ? "Yes" : "No");
            } else puts(~(n + 1) & 1 ? "Yes" : "No");
        }
    }

#ifdef LOCAL
    printf("\nTime cost: %.2fs\n", 1.0 * (clock() - _) / CLOCKS_PER_SEC);
#endif
    return 0;
}
