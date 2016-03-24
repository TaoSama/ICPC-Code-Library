//
//  Created by TaoSama on 2016-01-22
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

typedef long long LL;

int n, m;
int a[N], b[N], ans[5];

void update(LL& cur, LL& minv, int a1, int a2, int a3, int a4) {
    if(cur < minv) {
        minv = cur;
        ans[1] = a1;
        ans[2] = a2;
        ans[3] = a3;
        ans[4] = a4;
    }
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
//    ios_base::sync_with_stdio(0);

    while(scanf("%d", &n) == 1) {
        LL suma = 0, sumb = 0;
        for(int i = 1; i <= n; ++i) scanf("%d", a + i), suma += a[i];
        scanf("%d", &m);
        for(int i = 1; i <= m; ++i) scanf("%d", b + i), sumb += b[i];

        LL dif = suma - sumb, minv = abs(dif);
        for(int i = 1; i <= 4; ++i) ans[i] = -1;
        for(int i = 1; i <= n; ++i) {
            for(int j = 1; j <= m; ++j) {
                LL cur = abs(dif + 2LL * (-a[i] + b[j]));
                update(cur, minv, i, j, -1, -1);
            }
        }

        vector<pair<LL, pair<int, int> > > va, vb;
        for(int i = 1; i <= n; ++i)
            for(int j = i + 1; j <= n; ++j)
                va.push_back({a[i] + a[j], {i, j}});
        for(int i = 1; i <= m; ++i)
            for(int j = i + 1; j <= m; ++j)
                vb.push_back({b[i] + b[j], {i, j}});
        sort(vb.begin(), vb.end());

        for(auto &x : va) {
            LL cur = dif - 2 * x.first;
            auto iter = lower_bound(vb.begin(), vb.end(),
                                    make_pair(-cur / 2, make_pair(-1, -1)));
            if(iter != vb.end()) {
                LL tmp = abs(cur + 2 * iter->first);
                update(tmp, minv, x.second.first, x.second.second, iter->second.first,
                       iter->second.second);
            }
            if(iter != vb.begin()) {
                --iter;
                LL tmp = abs(cur + 2 * iter->first);
                update(tmp, minv, x.second.first, x.second.second, iter->second.first,
                       iter->second.second);
            }
        }

        if(ans[1] == -1) printf("%I64d\n0\n", minv);
        else if(ans[3] == -1) {
            printf("%I64d\n1\n", minv);
            printf("%d %d\n", ans[1], ans[2]);
        } else {
            printf("%I64d\n2\n", minv);
            printf("%d %d\n", ans[1], ans[3]);
            printf("%d %d\n", ans[2], ans[4]);
        }
    }
    return 0;
}
