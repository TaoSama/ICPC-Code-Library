//
//  Created by TaoSama on 2016-01-23
//  Copyright (c) 2015 TaoSama. All rights reserved.
//
#pragma comment(linker, "/STACK:1024000000,1024000000")
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

int n, x1, y1, x2, y2;
int x[2005], y[2005];
typedef long long LL;
pair<LL, int> dis[N];

LL getdis(int x1, int y1, int i) {
    return 1LL * (x1 - x[i]) * (x1 - x[i]) + 1LL * (y1 - y[i]) * (y1 - y[i]);
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d%d%d%d%d", &n, &x1, &y1, &x2, &y2) == 5) {
        for(int i = 1; i <= n; ++i) {
            scanf("%d%d", x + i, y + i);
            dis[i] = {getdis(x1, y1, i), i};
        }
        sort(dis + 1, dis + 1 + n);
        dis[0] = { 0, 0};
        long long ans = 1e18;
        for(int i = 0; i <= n; ++i) {
            long long cur = dis[i].first, tmp = 0;
            while(i + 1 <= n && dis[i + 1].first == cur) ++i;
            for(int j = i + 1; j <= n; ++j)
                tmp = max(tmp, getdis(x2, y2, dis[j].second));
            ans = min(ans, cur + tmp);
        }
        printf("%I64d\n", ans);
    }
    return 0;
}
