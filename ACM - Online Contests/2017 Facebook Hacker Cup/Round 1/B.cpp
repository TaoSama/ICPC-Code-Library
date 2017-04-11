//
//  Created by TaoSama on 2017-01-15
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

int n, r;
int x[N], y[N];

int get(pair<int, int>* rx, pair<int, int>* ry, int l, int r) {
    int ret = 0;
    for(int i = 1; i <= n; ++i) {
        bool ok = true;
        for(int j = l; j <= r && ok; ++j) {
            if(x[i] >= rx[j].first && x[i] <= rx[j].second
                    && y[i] >= ry[j].first && y[i] <= ry[j].second) {}
            else ok = false;
        }
        ret += ok;
    }
    return ret;
}

int main() {
#ifdef LOCAL
    freopen("fighting_the_zombies.txt", "r", stdin);
    freopen("fighting_the_zombies_out.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);

    int t; scanf("%d", &t);
    while(t--) {
        scanf("%d%d", &n, &r);
        for(int i = 1; i <= n; ++i) scanf("%d%d", x + i, y + i);
        vector < pair<pair<int, int>, pair<int, int> > > v;
        for(int i = 1; i <= n; ++i) {
            for(int j = 1; j <= n; ++j) {
                v.push_back({{x[i] - r, x[i]}, {y[j], y[j] + r}});
                v.push_back({{x[i], x[i] + r}, {y[j], y[j] + r}});
                v.push_back({{x[i], x[i] + r}, {y[j] - r, y[j]}});
                v.push_back({{x[i] - r, x[i]}, {y[j] - r, y[j]}});
            }
        }

        int ans = 0;
        for(int i = 0; i < v.size(); ++i) {
            for(int j = i + 1; j < v.size(); ++j) {
                pair<int, int> rx[] = {v[i].first, v[j].first};
                pair<int, int> ry[] = {v[i].second, v[j].second};
                int cur = get(rx, ry, 0, 0) + get(rx, ry, 1, 1) - get(rx, ry, 0, 1);
                ans = max(ans, cur);
            }
        }

        static int kase = 0;
        printf("Case #%d: %d\n", ++kase, ans);
    }

    return 0;
}
