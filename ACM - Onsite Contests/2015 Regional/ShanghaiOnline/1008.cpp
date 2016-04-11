//
//  Created by TaoSama on 2015-09-26
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

typedef long long LL;

int n, M;
int mul[N << 2];

#define root 1, n, 1
#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1 | 1

void build(int l, int r, int rt) {
    mul[rt] = 1;
    if(l == r) return;
    int m = l + r >> 1;
    build(lson);
    build(rson);
}

void update(int o, int v, int l, int r, int rt) {
    if(l == r) {
        mul[rt] = v % M;
        return;
    }
    int m = l + r >> 1;
    if(o <= m) update(o, v, lson);
    else update(o, v, rson);
    mul[rt] = 1LL * mul[rt << 1] * mul[rt << 1 | 1] % M;
}


int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int t; scanf("%d", &t);
    int kase = 0;
    while(t--) {
        scanf("%d%d", &n, &M);
        build(root);
        printf("Case #%d:\n", ++kase);
        for(int i = 1; i <= n; ++i) {
            int op, x; scanf("%d%d", &op, &x);
            if(op == 1) update(i, x, root);
            else update(x, 1, root);
            printf("%d\n", mul[1]);
        }
    }
    return 0;
}
