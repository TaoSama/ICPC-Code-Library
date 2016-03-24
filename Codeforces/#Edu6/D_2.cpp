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
int a[N], b[N];
typedef pair<int, int> P;
P ans[3];

void update(LL& cur, LL& minv, P a1, P a2) {
    if(cur < minv) {
        minv = cur;
        ans[1] = a1;
        ans[2] = a2;
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
        for(int i = 1; i <= 2; ++i) ans[i] = { -1, -1};
        for(int i = 1; i <= n; ++i) {
            for(int j = 1; j <= m; ++j) {
                LL cur = abs(dif + 2LL * (-a[i] + b[j]));
                update(cur, minv, {i, j}, { -1, -1});
            }
        }

        vector<pair<LL, pair<int, int> > > va, vb;
        for(int i = 1; i <= n; ++i)
            for(int j = i + 1; j <= n; ++j)
                va.push_back({a[i] + a[j], {i, j}});
        for(int i = 1; i <= m; ++i)
            for(int j = i + 1; j <= m; ++j)
                vb.push_back({b[i] + b[j], {i, j}});
        sort(va.begin(), va.end());
        sort(vb.begin(), vb.end());

        int j = 0;
        for(int i = 0; i < va.size(); ++i) {
            while(j < vb.size() && dif + 2 * (-va[i].first + vb[j].first) < 0) ++j;
            if(j < vb.size()) {
                LL cur = abs(dif + 2 * (-va[i].first + vb[j].first));
                update(cur, minv, va[i].second, vb[j].second);
            }
            if(j - 1 >= 0) {
                LL cur = abs(dif + 2 * (-va[i].first + 0LL + vb[j - 1].first));
                update(cur, minv, va[i].second, vb[j - 1].second);
            }
        }

        if(ans[1].first == -1) printf("%I64d\n0\n", minv);
        else if(ans[2].first == -1) {
            printf("%I64d\n1\n", minv);
            printf("%d %d\n", ans[1].first, ans[1].second);
        } else {
            printf("%I64d\n2\n", minv);
            printf("%d %d\n", ans[1].first, ans[2].first);
            printf("%d %d\n", ans[1].second, ans[2].second);
        }
    }
    return 0;
}
