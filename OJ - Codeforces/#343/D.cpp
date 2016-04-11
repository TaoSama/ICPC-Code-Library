//
//  Created by TaoSama on 2016-02-23
//  Copyright (c) 2016 TaoSama. All rights reserved.
//
#pragma comment(linker, "/STACK:1024000000,1024000000")
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

typedef long long LL;
int n;
LL v[N];

struct BIT {
    int n; LL b[N];
    void init(int _n) {
        n = _n;
        memset(b, 0, sizeof b);
    }
    void add(int i, LL v) {
        for(; i <= n; i += i & - i) b[i] = max(b[i], v);
    }
    LL sum(int i) {
        LL ret = 0;
        for(; i; i -= i & -i) ret = max(ret, b[i]);
        return ret;
    }
} bit;

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d", &n) == 1) {
        vector<LL> xs;
        for(int i = 1; i <= n; ++i) {
            int r, h; scanf("%d%d", &r, &h);
            v[i] = 1LL * r * r * h;
            xs.push_back(v[i]);
        }
        sort(xs.begin(), xs.end());
        xs.resize(unique(xs.begin(), xs.end()) - xs.begin());

        LL ans = 0;
        bit.init(xs.size());
        for(int i = 1; i <= n; ++i) {
            int idx = lower_bound(xs.begin(), xs.end(), v[i]) - xs.begin() + 1;
            LL cur = bit.sum(idx - 1) + v[i];
            ans = max(ans, cur);
            bit.add(idx, cur);
        }
        printf("%.12f\n", ans * acos(-1));
    }
    return 0;
}
