//
//  Created by TaoSama on 2015-11-19
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

int n, h, a[N], b[N];

void add(int i, int v) {
    for(; i <= n; i += i & -i) b[i] += v;
}

int sum(int i) {
    int ret = 0;
    for(; i; i -= i & -i) ret += b[i];
    return ret;
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d%d", &n, &h) == 2) {
        vector<int> xs;
        for(int i = 1; i <= n; ++i) {
            scanf("%d", a + i);
            xs.push_back(a[i]);
        }
        sort(xs.begin(), xs.end());
        xs.resize(unique(xs.begin(), xs.end()) - xs.begin());

        memset(b, 0, sizeof b);
        for(int i = 1; i <= n; ++i) {
            int o = lower_bound(xs.begin(), xs.end(), a[i]) - xs.begin() + 1;
            int l = lower_bound(xs.begin(), xs.end(), a[i] - h) - xs.begin() + 1;
            int r = upper_bound(xs.begin(), xs.end(), a[i] + h) - xs.begin();
            int tmp = (sum(r) - sum(l - 1)) % MOD;
            add(o, tmp + 1);
        }
        int ans = ((sum(n) - n) % MOD + MOD) % MOD;
        printf("%d\n", ans);
    }
    return 0;
}
