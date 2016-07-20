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
const int N = 1e6 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, m, a[N];

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);
    clock_t _ = clock();

    while(scanf("%d%d", &n, &m) == 2) {
        map<int, int> mp, now;
        for(int i = 2; i * i <= m; ++i) {
            if(m % i == 0) {
                int cnt = 0;
                while(m % i == 0) ++cnt, m /= i;
                mp[i] = cnt;
            }
            if(m == 1) break;
        }
        if(m > 1) mp[m] = 1;

        for(int i = 1; i <= n; ++i) {
            int x; scanf("%d", &x);
            for(auto u : mp) {
                int p = u.first;
                if(x % p == 0) {
                    int cnt = 0;
                    while(x % p == 0) ++cnt, x /= p;
                    now[p] = max(now[p], cnt);
                }
            }
        }

        bool ok = true;
        for(auto p : mp) ok &= now[p.first] >= p.second;
        puts(ok ? "Yes" : "No");

    }


#ifdef LOCAL
    printf("\nTime cost: %.2fs\n", 1.0 * (clock() - _) / CLOCKS_PER_SEC);
#endif
    return 0;
}
