//
//  Created by TaoSama on 2016-05-14
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
const int N = 30 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, a[N];
typedef long long LL;

LL C(int n, int m) {
    LL ret = 1;
    m = min(m, n - m);
    for(int i = 0; i < m; ++i) {
        ret *= n - i;
        ret /= i + 1;
    }
    return ret;
}

LL calc(int n, int s) {
    LL ret = 0;
    for(int i = s; i <= n; i += 2) ret += C(n, i);
    return ret;
}

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
        for(int i = 1; i <= n; ++i) scanf("%d", a + i);
        sort(a + 1, a + 1 + n);
        LL odd = 0, even = 0;
        for(int i = 1; i <= n; ++i) {
            odd += 1LL * a[i] * (1 + calc(n - i, 2));
            even += 1LL * a[i] * calc(n - i, 1);
        }

        LL ans = odd - even;
        if(ans < 0) ans = -ans;
        printf("%I64d\n", ans);
    }

#ifdef LOCAL
    printf("\nTime cost: %.2fs\n", 1.0 * (clock() - _) / CLOCKS_PER_SEC);
#endif
    return 0;
}
