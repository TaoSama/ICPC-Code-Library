//
//  Created by TaoSama on 2017-03-21
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
#define pr(x) cerr << #x << " = " << x << "  "
#define prln(x) cerr << #x << " = " << x << endl
const int N = 2e4 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, k, a[N];

inline void modAdd(int& x, int y) {
    if((x += y) >= MOD) x -= MOD;
}

struct BIT {
    int n, b[N];
    void init(int _n) {
        n = _n;
        fill(b, b + n + 1, 0);
    }
    void add(int i, int v) {
        for(; i <= n; i += i & -i) modAdd(b[i], v);
    }
    int sum(int i) {
        int ret = 0;
        for(; i; i -= i & -i) modAdd(ret, b[i]);
        return ret;
    }
} bit[105];

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int t; scanf("%d", &t);
    while(t--) {
        scanf("%d%d", &n, &k);
        for(int i = 1; i <= n; ++i) scanf("%d", a + i);
        reverse(a + 1, a + 1 + n);
        for(int i = 0; i <= k; ++i) bit[i].init(n);

        for(int i = 1; i <= n; ++i) {
            int x = a[i];
            bit[1].add(x, 1);
            for(int j = 2; j <= k; ++j) {
                bit[j].add(x, bit[j - 1].sum(x - 1));
            }
//            for(int j = 1; j <= k; ++j) {
//                printf("%d: ", j);
//                for(int x = 1; x <= n; ++x)
//                    printf("%d ", bit[j].sum(x) - bit[j].sum(x - 1));
//              puts("");
//            }
        }
        printf("%d\n", bit[k].sum(n));
    }

    return 0;
}
