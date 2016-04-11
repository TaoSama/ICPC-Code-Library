//
//  Created by TaoSama on 2016-03-23
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
const int N = 1e6 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

struct BIT {
    int n, b[N];
    void init(int _n) {
        n = _n;
        memset(b, 0, sizeof b);
    }
    void add(int i, int v) {
        for(; i; i -= i & -i) b[i] += v;
    }
    int sum(int i) {
        int ret = 0;
        for(; i <= n; i += i & -i) ret += b[i];
        return ret;
    }
} bit;

int n, c, q, a[N];
vector<pair<int, int> > qs[N];
int last[N], wh[N], ans[N];

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    scanf("%d%d%d", &n, &c, &q);
    for(int i = 1; i <= n; ++i) {
        scanf("%d", a + i);
        last[i] = wh[a[i]];
        wh[a[i]] = i;
    }
    for(int i = 1; i <= q; ++i) {
        int l, r; scanf("%d%d", &l, &r);
        qs[r].push_back(make_pair(l, i));
    }

    bit.init(n);
    for(int i = 1; i <= n; ++i) {
        if(last[i]) bit.add(last[i], 1);
        if(last[last[i]]) bit.add(last[last[i]], -1);
        for(int j = 0; j < qs[i].size(); ++j) {
            pair<int, int>& q = qs[i][j];
            ans[q.second] = bit.sum(q.first);
        }
    }
    for(int i = 1; i <= q; ++i) printf("%d\n", ans[i]);
    return 0;
}
