//
//  Created by TaoSama on 2016-05-07
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
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

struct SegTree {
    int sum[N << 2];

    void build(int l, int r, int rt) {
        sum[rt] = 0;
        if(l == r) return;
        int m = l + r >> 1;
        build(l, m, rt << 1);
        build(m + 1, r, rt << 1 | 1);
    }

    void update(int o, int v, int l, int r, int rt) {
        if(l == r) {
            sum[rt] += v;
            return;
        }
        int m = l + r >> 1;
        if(o <= m) update(o, v, l, m, rt << 1);
        else update(o, v, m + 1, r, rt << 1 | 1);
        sum[rt] = sum[rt << 1] + sum[rt << 1 | 1];
    }

    int query(int k, int l, int r, int rt) {
        if(l == r) return l;
        int m = l + r >> 1;
        if(k <= sum[rt << 1]) return query(k, l, m, rt << 1);
        else return query(k - sum[rt << 1], m + 1, r, rt << 1 | 1);
    }
} T;

int n, stk[N], top;

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);
    clock_t _ = clock();

    scanf("%d", &n);
    T.build(1, 1e5, 1);
    for(int i = 1; i <= n; ++i) {
        static char op[20]; scanf("%s", op);
        if(op[1] == 'o') { //pop
            if(!top) {
                puts("Invalid");
                continue;
            }
            int x = stk[top--];
            printf("%d\n", x);
            T.update(x, -1, 1, 1e5, 1);
        } else if(op[1] == 'u') { //push
            int x; scanf("%d", &x);
            stk[++top] = x;
            T.update(x, 1, 1, 1e5, 1);
        } else {
            if(!top) {
                puts("Invalid");
                continue;
            }
//          printf("all = %d k = %d\n", top, top + 1 >> 1);
            printf("%d\n", T.query(top + 1 >> 1, 1, 1e5, 1));
        }
    }

#ifdef LOCAL
    printf("\n\nTime cost: %.2fs\n", 1.0 * (clock() - _) / CLOCKS_PER_SEC);
#endif
    return 0;
}
