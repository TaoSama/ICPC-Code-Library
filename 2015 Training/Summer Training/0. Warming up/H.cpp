//
//  Created by TaoSama on 2015-07-17
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
const int M = N * 20;

int n, q, a[N];
int root[N], ls[M], rs[M], sum[M], sz;

void insert(int o, int v, int l, int r, int pre, int& rt) {
    rt = ++sz; sum[rt] = sum[pre] + v;
    if(l == r) return;
    ls[rt] = ls[pre]; rs[rt] = rs[pre];

    int m = l + r >> 1;
    if(o <= m) insert(o, v, l, m, ls[pre], ls[rt]);
    else insert(o, v, m + 1, r, rs[pre], rs[rt]);
}

int query(int L, int R, int k, int l, int r) {
    if(l == r) return l;
    int cnt = sum[ls[R]] - sum[ls[L]];

    int m = l + r >> 1;
    if(cnt >= k) return query(ls[L], ls[R], k, l, m);
    else return query(rs[L], rs[R], k - cnt, m + 1, r);
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int t; scanf("%d", &t);
    while(t--) {
        scanf("%d%d", &n, &q);
        for(int i = 1; i <= n; ++i) scanf("%d", a + i);

        vector<int> xs(n);
        copy(a + 1, a + 1 + n, xs.begin());
        sort(xs.begin(), xs.end());
        xs.resize(unique(xs.begin(), xs.end()) - xs.begin());

        sz = root[0] = 0;
        for(int i = 1; i <= n; ++i) {
            int x = lower_bound(xs.begin(), xs.end(), a[i]) - xs.begin() + 1;
            insert(x, 1, 1, xs.size(), root[i - 1], root[i]);
        }

        while(q--) {
            int l, r, k; scanf("%d%d%d", &l, &r, &k);
            int idx = query(root[l - 1], root[r], k, 1, xs.size());
//          prln(idx);
            printf("%d\n", xs[idx - 1]);
        }
    }
    return 0;
}
