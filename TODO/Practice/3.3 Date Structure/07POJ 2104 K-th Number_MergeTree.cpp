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
int dat[20][N];

//现在这里存的是[l,r] d:=递归层数
#define root 1, n, 1
#define lson l, m, d + 1
#define rson m + 1, r, d + 1

void push_up(int l, int r, int d) {
    int m = l + r >> 1;
    int i = l, j = m + 1, k = l;

    while(i <= m && j <= r) {
        if(dat[d + 1][i] < dat[d + 1][j])
            dat[d][k++] = dat[d + 1][i++];  //将下一层的拷贝过来
        else
            dat[d][k++] = dat[d + 1][j++];
    }

    while(i <= m) dat[d][k++] = dat[d + 1][i++];
    while(j <= r) dat[d][k++] = dat[d + 1][j++];
}

void build(int l, int r, int d) {
    if(l == r) {
        int x; scanf("%d", &x);
        s[l] = a[l] = x;
        dat[d][l] = x;
        return;
    }

    int m = l + r >> 1;
    build(lson);
    build(rson);

    push_up(l, r, d);  //merge
}

int query(int L, int R, int v, int l, int r, int d) {
    if(L <= l && r <= R) {
        return upper_bound(&dat[d][l], &dat[d][r + 1], v) - &dat[d][l];
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
//hdu2665
