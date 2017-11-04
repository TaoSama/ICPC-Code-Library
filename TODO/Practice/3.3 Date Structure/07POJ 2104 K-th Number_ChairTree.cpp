//
//  Created by TaoSama on 2015-06-24
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
const int M = N * 20;

int n, q, a[N], s[N], root[N], sz;
int lson[M], rson[M], sum[M];

void insert(int o, int v, int l, int r, int pre, int &rt) {
    rt = ++sz;
    sum[rt] = sum[pre] + v;
    if(l == r) return; //叶子节点没有左右儿子
    lson[rt] = lson[pre]; rson[rt] = rson[pre];

    int m = l + r >> 1;
    if(o <= m) insert(o, v, l, m, lson[pre], lson[rt]);
    else insert(o, v, m + 1, r, rson[pre], rson[rt]);
}

//这里L,R是记录[l,r]区间的两棵线段树的根节点
int query(int L, int R, int k, int l, int r) {
    if(l == r) return l;
    int cnt = sum[lson[R]] - sum[lson[L]];
    int m = l + r >> 1;
    if(cnt >= k) return query(lson[L], lson[R], k, l, m);
    else return query(rson[L], rson[R], k - cnt, m + 1, r);
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d%d", &n, &q) == 2) {
        sz = 0; root[0] = 0;
        for(int i = 1; i <= n; ++i) {
            scanf("%d", a + i);
            s[i] = a[i];
        }
        sort(s + 1, s + 1 + n);
        int m = unique(s + 1, s + 1 + n) - s - 1; // 返回的是后一个位置要-1
        for(int i = 1; i <= n; ++i) {
            int o = lower_bound(s + 1, s + 1 + m, a[i]) - s; //返回找到的位置就不-1
            insert(o, 1, 1, m, root[i - 1], root[i]);
        }
        while(q--) {
            int l, r, k; scanf("%d%d%d", &l, &r, &k);
            int ans = query(root[l - 1], root[r], k, 1, m);
            printf("%d\n", s[ans]);
        }
    }
    return 0;
}
