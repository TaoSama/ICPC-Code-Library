//
//  Created by TaoSama on 2016-03-22
//  Copyright (c) 2016 TaoSama. All rights reserved.
//
#pragma comment(linker, "/STACK:102400000,102400000")
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
const int N = 5e4 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

struct BIT {
    int n, b[N];
    void init(int _n) {
        n = _n;
        memset(b, 0, sizeof b);
    }
    void add(int i, int v) {
        for(; i; i -= i & -i) b[i] = max(b[i], v);
    }
    int sum(int i) {
        int ret = 0;
        for(; i <= n; i += i & -i) ret = max(ret, b[i]);
        return ret;
    }
} bit;

vector<int> divisors[N];
vector<pair<int, int> > qs[N];
int n, q, a[N], ans[N];
int last[N];

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    for(int i = 1; i <= 5e4; ++i)
        for(int j = i; j <= 5e4; j += i)
            divisors[j].push_back(i);

    int t; scanf("%d", &t);
    while(t--) {
        scanf("%d", &n);
        for(int i = 1; i <= n; ++i) scanf("%d", a + i);
        scanf("%d", &q);
        for(int i = 1; i <= n; ++i) qs[i].clear();
        for(int i = 1; i <= q; ++i) {
            int l, r; scanf("%d%d", &l, &r);
            qs[r].push_back({l, i});
        }

        bit.init(n);
        memset(last, 0, sizeof last);
        for(int i = 1; i <= n; ++i) {
            int v = a[i];
            for(int x : divisors[v]) {
                if(last[x]) bit.add(last[x], x);
                last[x] = i;
            }
            for(auto q : qs[i]) ans[q.second] = bit.sum(q.first);
        }
        for(int i = 1; i <= q; ++i) printf("%d\n", ans[i]);
    }
    return 0;
}
