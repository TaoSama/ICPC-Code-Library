//
//  Created by TaoSama on 2015-08-26
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
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 9901;

int n, d, a[N];

int b[N];
void add(int i, int x) {
    for(; i <= n; i += i & -i) b[i] = (b[i] + x) % MOD;
}

int sum(int i) {
    int ret = 0;
    for(; i; i -= i & -i) ret = (ret + b[i]) % MOD;
    return ret;
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    //dp[i] = dp[j] + 1; a[i] as the end
    while(scanf("%d%d", &n, &d) == 2) {
        vector<int> xs;
        for(int i = 1; i <= n; ++i) {
            scanf("%d", a + i);
            xs.push_back(a[i]);
        }
        sort(xs.begin(), xs.end());
        xs.resize(unique(xs.begin(), xs.end()) - xs.begin());
        memset(b, 0, sizeof b);
        for(int i = 1; i <= n; ++i) {
            int idx = lower_bound(xs.begin(), xs.end(), a[i]) - xs.begin() + 1;
            int l = lower_bound(xs.begin(), xs.end(), a[i] - d) - xs.begin() + 1;
            int r = upper_bound(xs.begin(), xs.end(), a[i] + d) - xs.begin();
            int cnt = ((sum(r) - sum(l - 1) + 1) % MOD + MOD) % MOD;
            add(idx, cnt);
        }
        int ans = ((sum(n) - n) % MOD + MOD) % MOD;
        printf("%d\n", ans);
    }
    return 0;
}
