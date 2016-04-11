//
//  Created by TaoSama on 2015-12-05
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

int n, a[N];

int sum[N << 2], ans[N];

void build(int l, int r, int rt) {
    sum[rt] = r - l + 1;
    if(l == r) return;
    int m = l + r >> 1;
    build(l, m, rt << 1);
    build(m + 1, r, rt << 1 | 1);
}

int query(int k, int l, int r, int rt) {
    --sum[rt];
    if(l == r) return l;
    int m = l + r >> 1;
    if(k >= sum[rt << 1 | 1]) return query(k - sum[rt << 1 | 1], l, m, rt << 1);
    else return query(k, m + 1, r, rt << 1 | 1);
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int t; scanf("%d", &t);
    while(t--) {
        scanf("%d", &n);
        for(int i = 1; i <= n; ++i) scanf("%d", a + i);

        build(1, n, 1);
        int all = n;
        for(int i = n; i; --i) {
            int k = a[i] - a[i - 1];
            ans[i] = query(k, 1, n, 1);
        }
        for(int i = 1; i <= n; ++i)
            printf("%d%c", ans[i], " \n"[i == n]);
    }
    return 0;
}
