//
//  Created by TaoSama on 2016-07-20
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

int n;
typedef long long LL;
LL a[N], l, r;

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);
    clock_t _ = clock();

    int t; scanf("%d", &t);
    while(t--) {
        scanf("%d%I64d%I64d", &n, &l, &r);
        for(int i = 1; i <= n; ++i) scanf("%I64d", a + i);
        sort(a + 1, a + 1 + n);

        map<LL, int> mp;
        for(int i = 2; i <= n; ++i) {
            LL c = a[i] - a[i - 1] + 1;
            LL d = a[i] + a[i - 1] - 1;
            c = max(c, l); d = min(d, r);
            ++mp[c];
            --mp[d + 1];
        }

        int sum = 0;
        LL last = mp.begin()->first, ans = 0;
        for(auto& p : mp) {
            if(sum >= 1) {
                ans += p.first - last;
            }
            sum += p.second;
            last = p.first;
        }
        ans = r - l + 1 - ans;
        printf("%I64d\n", ans);
    }

#ifdef LOCAL
    printf("\nTime cost: %.2fs\n", 1.0 * (clock() - _) / CLOCKS_PER_SEC);
#endif
    return 0;
}
