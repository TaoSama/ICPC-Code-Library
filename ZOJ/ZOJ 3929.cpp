//
//  Created by TaoSama on 2016-04-10
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

void add(int& x, int y) {
    if((x += y) >= MOD) x -= MOD;
}

struct BIT {
    int n, dir, b[N];
    void init(int _n, int _dir) {
        n = _n; dir = _dir;
        memset(b, 0, sizeof b);
    }
    void update(int i, int v) {
        for(; i && i <= n; i += dir * (i & -i))
            add(b[i], v);
    }
    int query(int i) {
        int ret = 0;
        for(; i && i <= n; i -= dir * (i & -i))
            add(ret, b[i]);
        return ret;
    }
} small, large;

int n, a[N];
int two[N] = {1};

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    for(int i = 1; i < N; ++i) add(two[i], two[i - 1] * 2);

    int t; scanf("%d", &t);
    while(t--) {
        scanf("%d", &n);
        for(int i = 1; i <= n; ++i) scanf("%d", a + i);

        small.init(n, 1);
        large.init(n, -1);

        int ans = 0;
        small.update(a[1], 1); //中轴
        large.update(a[1], 1);
        for(int i = 2; i <= n; ++i) {
            add(ans, 1LL * two[n - i] * large.query(a[i] + 1) % MOD); //放右边
            add(ans, 1LL * two[n - i] * small.query(a[i] - 1) % MOD); //放左边

            small.update(a[i], two[i - 2]); //except 1
            large.update(a[i], two[i - 2]); //except 1
        }
        add(ans, ans);
        printf("%d\n", ans);
    }
    return 0;
}
