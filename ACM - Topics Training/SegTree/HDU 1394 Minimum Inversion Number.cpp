//
//  Created by TaoSama on 2015-09-18
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
const int N = 5e3 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, a[N];
int sum[N << 2];

#define root 0, n - 1, 1
#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1 | 1

void push_up(int rt) {
    sum[rt] = sum[rt << 1] + sum[rt << 1 | 1];
}

void update(int o, int l, int r, int rt) {
    if(l == r) {
        sum[rt]++;
        return;
    }
    int m = l + r >> 1;
    if(o <= m) update(o, lson);
    else update(o, rson);
    push_up(rt);
}

int query(int L, int R, int l, int r, int rt) {
    if(L <= l && r <= R) {
        return sum[rt];
    }
    int m = l + r >> 1, ret = 0;
    if(L <= m) ret += query(L, R, lson);
    if(R > m) ret += query(L, R, rson);
    return ret;
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d", &n) == 1) {
        int cur = 0;
        memset(sum, 0, sizeof sum);
        for(int i = 1; i <= n; ++i) {
            scanf("%d", a + i);
            cur += query(a[i], n - 1, root);
            update(a[i], root);
        }

        int ans = cur;
        for(int i = 1; i < n; ++i) {
            int tmp = n - a[i] - 1 - a[i]; //big: n-a[i]-1,  small: a[i]
            cur += tmp;
            ans = min(ans, cur);
        }
        printf("%d\n", ans);
    }
    return 0;
}
