//
//  Created by TaoSama on 2015-09-17
//  Copyright (c) 2015 TaoSama. All rights reserved.
//
//#pragma comment(linker, "/STACK:1024000000,1024000000")
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
const int N = 2e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, k, x;
long long a[N], l[N], r[N];

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d%d%d", &n, &k, &x) == 3) {
        l[0] = r[n + 1] = 0;
        for(int i = 1; i <= n; ++i) {
            scanf("%I64d", a + i);
            l[i] = l[i - 1] | a[i];
        }
        for(int i = n; i; --i)
            r[i] = r[i + 1] | a[i];

        long long ans = 0;
        for(int i = 1; i <= n; ++i) {
            long long cur = l[i - 1] | r[i + 1], tmp = a[i];
            for(int j = 1; j <= k; ++j) tmp *= x;
            ans = max(ans, cur | tmp);
        }
        printf("%I64d\n", ans);
    }
    return 0;
}
