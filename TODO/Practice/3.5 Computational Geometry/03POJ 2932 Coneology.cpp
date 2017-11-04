//
//  Created by TaoSama on 2016-08-22
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

int n;
double x[N], y[N], r[N];

bool isInside(int i, int j) {
    double dx = x[i] - x[j], dy = y[i] - y[j];
    return dx * dx + dy * dy <= r[j] * r[j];
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d", &n) == 1) {
        vector<pair<double, int> > events;
        for(int i = 1; i <= n; ++i) {
            scanf("%lf%lf%lf", r + i, x + i, y + i);
            events.push_back(make_pair(x[i] - r[i], i));
            events.push_back(make_pair(x[i] + r[i], -i));
        }
        sort(events.begin(), events.end());

        vector<int> ans;
        set<pair<double, int> > outers;
        for(int i = 0; i < events.size(); ++i) {
            int id = events[i].second;
            if(id > 0) {
                set<pair<double, int> >::iterator iter =
                    outers.lower_bound(make_pair(y[id], -1));
                if(iter != outers.end() && isInside(id, iter->second)) continue;
                if(iter != outers.begin() && isInside(id, (--iter)->second)) continue;
                ans.push_back(id);
                outers.insert(make_pair(y[id], id));
            } else outers.erase(make_pair(y[-id], -id));
        }

        sort(ans.begin(), ans.end());
        printf("%d\n", ans.size());
        for(int i = 0; i < ans.size(); ++i) {
            printf("%d%c", ans[i], " \n"[i == ans.size() - 1]);
        }
    }

    return 0;
}
