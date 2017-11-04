//
//  Created by TaoSama on 2015-06-21
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
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int N = 1e5 + 10;

int n, q, a[N], s[N];
vector<int> dat[N * 3];

#define root 1, n, 1
#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1 | 1

void push_up(int rt, int sz) {
    int l = rt << 1, r = rt << 1 | 1;
    dat[rt].resize(sz);
    merge(dat[l].begin(), dat[l].end(), dat[r].begin(), dat[r].end(),
          dat[rt].begin());
}

void build(int l, int r, int rt) {
    if(l == r) {
        int x; scanf("%d", &x);
        s[l] = a[l] = x;
        dat[rt].clear();
        dat[rt].push_back(x);
        return;
    }
    int m = l + r >> 1;
    build(lson);
    build(rson);
    push_up(rt, r - l + 1);
}

int query(int L, int R, int v, int l, int r, int rt) {
    if(L <= l && r <= R) {
        return upper_bound(dat[rt].begin(), dat[rt].end(), v) - dat[rt].begin();
    }
    int m = l + r >> 1, ret = 0;
    if(L <= m) ret += query(L, R, v, lson);
    if(R > m) ret += query(L, R, v, rson);
    return ret;
}

int findkth(int L, int R, int k) {
    int l = 1, r = n;
    while(l <= r) {
        int m = l + r >> 1;
        int c = query(L, R, s[m], root);
        if(c >= k) r = m - 1;
        else l = m + 1;
    }
    return s[l];
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d%d", &n, &q) == 2) {
        build(root);
        sort(s + 1, s + 1 + n);
        while(q--) {
            int l, r, k; scanf("%d%d%d", &l, &r, &k);
            printf("%d\n", findkth(l, r, k));
        }
    }
    return 0;
}
