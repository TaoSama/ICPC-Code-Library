//
//  Created by TaoSama on 2015-10-08
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
const int N = 5e4 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, q, a[N], ans[N];

int sum[N << 2];

#define root 1, n, 1
#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1 | 1

void build(int l, int r, int rt) {
    sum[rt] = r - l + 1;
    if(l == r) return;
    int m = l + r >> 1;
    build(lson);
    build(rson);
}

int update(int k, int l, int r, int rt) {
    --sum[rt];
    if(l == r) return l;
    int m = l + r >> 1;
    if(sum[rt << 1] >= k) return update(k, lson);
    else return update(k - sum[rt << 1], rson);
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d", &n) == 1) {
        for(int i = 1; i <= n; ++i) scanf("%d", a + i);
        scanf("%d", &q);
        build(root);
        for(int i = 1; i <= n; ++i) {
            ans[i] = update(a[i], root);
        }
        for(int i = 1; i <= q; ++i) {
            int x; scanf("%d", &x);
            printf("%d%c", ans[x], " \n"[i == q]);
        }
    }
    return 0;
}
