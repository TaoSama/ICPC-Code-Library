//
//  Created by TaoSama on 2015-09-28
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
const int N = 2e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, ans[N];
int sum[N << 2];
typedef pair<int, int> P;
P a[N];

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

void update(int k, int v, int l, int r, int rt) {
    --sum[rt];
    if(l == r) {
        ans[l] = v;
        return;
    }
    int m = l + r >> 1;
    if(sum[rt << 1] > k) update(k, v, lson);
    else update(k - sum[rt << 1], v, rson);
}

inline int read() {
    char c = getchar();
    while(!isdigit(c)) c = getchar();
    int x = 0;
    while(isdigit(c)) {
        x = x * 10 + c - '0';
        c = getchar();
    }
    return x;
}

void out(int x) {
    if(x > 9) out(x / 10);
    putchar(x % 10 + '0');
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d", &n) == 1) {
        build(root);
        for(int i = 1; i <= n; ++i)
            a[i].first = read(), a[i].second = read();
        for(int i = n; i; --i) update(a[i].first, a[i].second, root);
        for(int i = 1; i <= n; ++i)
            out(ans[i]), putchar(" \n"[i == n]);
    }
    return 0;
}
