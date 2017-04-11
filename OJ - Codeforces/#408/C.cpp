//
//  Created by TaoSama on 2017-04-11
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
#define pr(x) cerr << #x << " = " << x << "  "
#define prln(x) cerr << #x << " = " << x << endl
const int N = 3e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, a[N];
vector<int> G[N];

struct BIT {
    int n, b[N];
    void init(int _n) {
        n = _n;
        memset(b, 0, sizeof b);
    }
    void add(int i, int v) {
        for(; i <= n; i += i & -i) b[i] += v;
    }
    int sum(int i) {
        int ret = 0;
        for(; i; i -= i & -i) ret += b[i];
        return ret;
    }
    int kth(int k) {
        int ret = 0;
        for(int i = 18; ~i; --i) {
            int x = 1 << i;
            if(ret + x <= n && b[ret + x] < k) {
                k -= b[ret + x];
                ret += x;
            }
        }
        return ret + 1;
    }
} bit;

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d", &n) == 1) {
        for(int i = 1; i <= n; ++i) G[i].clear();

        vector<int> xs;
        for(int i = 1; i <= n; ++i) {
            scanf("%d", a + i);
            xs.push_back(a[i]);
        }
        for(int i = 1; i < n; ++i) {
            int u, v; scanf("%d%d", &u, &v);
            G[u].push_back(v);
            G[v].push_back(u);
        }

        sort(xs.begin(), xs.end());
        xs.resize(unique(xs.begin(), xs.end()) - xs.begin());
        auto getRank = [&](int x) {
            return lower_bound(xs.begin(), xs.end(), x) - xs.begin() + 1;
        };

        int ans = INF;
        bit.init(xs.size());
        for(int i = 1; i <= n; ++i) bit.add(getRank(a[i]), 1);
        for(int i = 1; i <= n; ++i) {
            int cur = a[i];
            bit.add(getRank(a[i]), -1);
            for(int v : G[i]) {
                bit.add(getRank(a[v]), -1);
                cur = max(cur, a[v] + 1);
            }
            int k = bit.sum(xs.size());
            if(k) {
                int idx = bit.kth(k);
                cur = max(cur, xs[idx - 1] + 2);
            }
            ans = min(ans, cur);

            bit.add(getRank(a[i]), 1);
            for(int v : G[i]) bit.add(getRank(a[v]), 1);
        }
        printf("%d\n", ans);
    }

    return 0;
}
