//
//  Created by TaoSama on 2015-10-01
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
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, a[N], b[N];

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d", &n) == 1) {
        for(int i = 0; i < n; ++i) scanf("%d", a + i);
        long long ans = 0;
        for(int k = 10; k <= 1e9; k *= 10) {
            for(int i = 0; i < n; ++i) b[i] = a[i] % k;
            sort(b, b + n);
            for(int i = 0; i < n; ++i) {
                int t = k - b[i];
                int p = lower_bound(b + i + 1, b + n, t) - b;
                ans += n - p;
            }
        }
        printf("%lld\n", ans);
    }
    return 0;
}
