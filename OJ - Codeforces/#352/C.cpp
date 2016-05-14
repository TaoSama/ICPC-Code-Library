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
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n;
double x[N], y[N];
pair<double, int> a[N], b[N];
double d2g[N];

double get(int i, int j) {
    return hypot(x[i] - x[j], y[i] - y[j]);
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);
    clock_t _ = clock();

    for(int i = 1; i <= 3; ++i) scanf("%lf%lf", x + i, y + i);
    scanf("%d", &n);
    for(int i = 4; i <= n + 3; ++i) scanf("%lf%lf", x + i, y + i);

    for(int i = 4; i <= n + 3; ++i) {
        d2g[i] = get(3, i);
        a[i] = {d2g[i] - get(1, i), i};  b[i] = {d2g[i] - get(2, i), i};
    }
    sort(a + 4, a + n + 4);
    sort(b + 4, b + n + 4);

    double ans = 1e18, tmp;
    if(n > 1) {
        vector<int> choose;
        for(int i = 0; i < 5 && i < n; ++i) choose.push_back(a[n + 3 - i].second);
        for(int i = 0; i < 5 && i < n; ++i) choose.push_back(b[n + 3 - i].second);

        pair<double, pair<int, int> > p = { -1e18, { -1, -1}};
        for(int i = 0; i < choose.size(); ++i) {
            for(int j = 0; j < choose.size(); ++j) {
                int x = choose[i], y = choose[j];
                if(x == y) continue;
                p = max(p, { -get(1, x) - get(2, y) + d2g[x] + d2g[y], {x, y}});
            }
        }

        int x = p.second.first, y = p.second.second;
        tmp = get(1, x) + get(2, y) + d2g[x] + d2g[y];
        for(int i = 4; i <= n + 3; ++i) {
            if(i == x || i == y) continue;
            tmp += 2 * d2g[i];
        }
        ans = min(ans, tmp);
    }

    int x = a[n + 3].second;
    tmp = get(1, x) + d2g[x];
    for(int i = 4; i <= n + 3; ++i) {
        if(i == x) continue;
        tmp += 2 * d2g[i];
    }
    ans = min(ans, tmp);

    x = b[n + 3].second;
    tmp = get(2, x) + d2g[x];
    for(int i = 4; i <= n + 3; ++i) {
        if(i == x) continue;
        tmp += 2 * d2g[i];
    }
    ans = min(ans, tmp);
    printf("%.12f\n", ans);

#ifdef LOCAL
    printf("\nTime cost: %.2fs\n", 1.0 * (clock() - _) / CLOCKS_PER_SEC);
#endif
    return 0;
}
