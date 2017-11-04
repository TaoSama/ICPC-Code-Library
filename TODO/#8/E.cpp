//
//  Created by TaoSama on 2017-01-14
//  Copyright (c) 2016 TaoSama. All rights reserved.
//
#pragma comment(linker, "/STACK:102400000,102400000")
#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
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

int n, q;

struct BIT {
    int n, b[N];
    void init(int _n) {
        n = _n;
        memset(b, -1, sizeof b);
    }
    void add(int i, int v) {
        for(; i <= n; i += i & -i) b[i] = max(b[i], v);
    }
    int sum(int i) {
        int ret = -1;
        for(; i; i -= i & -i) ret = max(b[i], ret);
        return ret;
    }
} bit[100];

int a[N], s[N];
int get(int x) {
    int s = 0;
    for(; x; x /= 10) s += x % 10;
    return s;
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int t; scanf("%d", &t);
    while(t--) {
        scanf("%d%d", &n, &q);
        for(int i = 0; i < 100; ++i) bit[i].init(n);
        for(int i = 1; i <= n; ++i) {
            scanf("%d", a + i);
            s[i] = get(a[i]);
            bit[s[i]].add(i, a[i]);
        }

        static int kase = 0;
        printf("Case #%d:\n", ++kase);
        while(q--) {
            int x; scanf("%d", &x);
//          pr(x); pr(a[x]); prln(s[x]);
            printf("%d\n", bit[s[x]].sum(x - 1));
        }
    }

    return 0;
}
