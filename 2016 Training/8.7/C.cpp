//
//  Created by TaoSama on 2016-08-07
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

int n, k, a[N];
typedef long long LL;
LL sum[N];

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d%d", &n, &k) == 2) {
        for(int i = 1; i <= n; ++i) scanf("%d", a + i);
        sort(a + 1, a + 1 + n);
//        for(int i = 1; i <= n; ++i) printf("%d ", a[i]); puts("");


        pair<int, int> ans = { -INF, INF}; //+ -
        LL sum = 0;
        for(int l = n, r = n; l; --l) {
            while(r >= 0 && 1LL * (l - r) * a[l] - sum <= k)
                sum += a[r--];

//          printf("%d %d %I64d %I64d\n", r + 1, l, sum, 1LL * (l - r - 1) * a[l]);
            ans = max(ans, {l - r - 1, -a[l]});
            sum -= a[l];
        }
        printf("%d %d\n", ans.first, -ans.second);
    }

    return 0;
}
/*
3 4
3 5
4 2
*/
