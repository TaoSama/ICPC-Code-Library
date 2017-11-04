//
//  Created by TaoSama on 2015-06-26
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
#define debug(x) cout << #x << " = " << x << endl
const int N = 3e4 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;
const int M = N * 20;

int n, q, root[N], sz;
int lson[M], rson[M], sum[M];

void insert(int o, int v, int l, int r, int pre, int &rt) {
    rt = ++sz;
    sum[rt] = sum[pre] + v;
    if(l == r) return;
    lson[rt] = lson[pre]; rson[rt] = rson[pre];
    int m = l + r >> 1;
    if(o <= m) insert(o, v, l, m, lson[pre], lson[rt]);
    else insert(o, v, m + 1, r, rson[pre], rson[rt]);
}

int query(int L, int R, int k, int l, int r) {
    if(k <= l) return sum[R] - sum[L];
    int m = l + r >> 1;
    int ret = 0;
    if(k <= m) ret += query(lson[L], lson[R], k, l, m);
    ret += query(rson[L], rson[R], k, m + 1, r);
    return ret;
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d", &n) == 1) {
        sz = 0; root[0] = 0;
        map<int, int> pre;
        for(int i = 1; i <= n; ++i) {
            int x; scanf("%d", &x);
            if(!pre.count(x)) root[i] = root[i - 1];
            else insert(pre[x], 1, 1, n, root[i - 1], root[i]);
            pre[x] = i;
        }
        scanf("%d", &q);
        while(q--) {
            int l, r; scanf("%d%d", &l, &r);
            int no = query(root[l - 1], root[r], l, 1, n);
            printf("%d\n", r - l + 1 - no);
        }
    }
    return 0;
}
