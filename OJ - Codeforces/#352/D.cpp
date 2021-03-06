//
//  Created by TaoSama on 2016-05-12
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
const int N = 5e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

typedef long long LL;
int n, k;
int a[N], lb, ub;

int getMax() { //minimize
    int l = ub, r = INF;
    while(l <= r) {
        int m = l + r >> 1;
        LL sum = 0;
        for(int i = 1; i <= n; ++i) sum += max(0, a[i] - m);
        if(sum > k) l = m + 1;
        else r = m - 1;
    }
//    prln(l);
    return l;
}

int getMin() { //maximize
    int l = 0, r = lb;
    while(l <= r) {
        int m = l + r >> 1;
        LL sum = 0;
        for(int i = 1; i <= n; ++i) sum += max(0, m - a[i]);
        if(sum <= k) l = m + 1;
        else r = m - 1;
    }
//    prln(l - 1);
    return l - 1;
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);
    clock_t _ = clock();

    while(scanf("%d%d", &n, &k) == 2) {
        LL sum = 0;
        for(int i = 1; i <= n; ++i) {
            scanf("%d", a + i);
            sum += a[i];
        }

        lb = sum / n, ub = (sum + n - 1) / n;
        printf("%d\n", getMax() - getMin());
    }

#ifdef LOCAL
    printf("\nTime cost: %.2fs\n", 1.0 * (clock() - _) / CLOCKS_PER_SEC);
#endif
    return 0;
}
