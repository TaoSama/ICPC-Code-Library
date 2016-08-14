//
//  Created by TaoSama on 2016-08-04
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

struct Query {
    int l, id;
};
vector<Query> qs[N];
int n, a[N];

struct BIT {
    int n, b[N];
    void init(int _n) {
        n = _n;
        memset(b, 0, sizeof b);
    }
    void add(int i, int v) {
        for(; i; i -= i & -i) b[i] ^= v;
    }
    int sum(int i) {
        int ret = 0;
        for(; i <= n; i += i & -i) ret ^= b[i];
        return ret;
    }
} bit;

int sum[N], ans[N];

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d", &n) == 1) {
        for(int i = 1; i <= n; ++i) {
            scanf("%d", a + i);
            sum[i] = sum[i - 1] ^ a[i];
        }

        int q; scanf("%d", &q);
        for(int i = 1; i <= q; ++i) {
            int l, r; scanf("%d%d", &l, &r);
            qs[r].push_back({l, i});
        }

        bit.init(n);
        map<int, int> mp;
        for(int i = 1; i <= n; ++i) {
            int x = a[i];
            if(mp.count(x)) bit.add(mp[x], x);
            bit.add(i, x);
            mp[x] = i;

            for(auto q : qs[i]) {
                int res = sum[i] ^ sum[q.l - 1];
                res ^= bit.sum(q.l);
                ans[q.id] = res;
            }
        }
        for(int i = 1; i <= q; ++i) printf("%d\n", ans[i]);
    }

    return 0;
}
