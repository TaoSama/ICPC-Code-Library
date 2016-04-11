//
//  Created by TaoSama on 2016-03-18
//  Copyright (c) 2016 TaoSama. All rights reserved.
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
const int N = 1e4 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n;
typedef pair<double, double> P;
P a[N];

double dfs(int l, int r) {
    if(l == r) return INF;
    int m = l + r >> 1;
    double x = a[m].first;

    double d = min(dfs(l, m), dfs(m + 1, r));
    inplace_merge(a + l, a + m + 1, a + r + 1, [](P x, P y) {
        return x.second < y.second;  //按照y来归并2个数组
    });

    vector<int> v;
    for(int i = l; i <= r; ++i) {
        if(abs(a[i].first - x) >= d) continue; //距离中轴小于d点加入

        for(int j = 0; j < v.size(); ++j) {
            int k = v[v.size() - 1 - j];  //倒着检查y坐标相差小于d的点
            double dy = a[i].second - a[k].second;
            if(dy >= d) break;
            double dx = a[i].first - a[k].first;
            d = min(d, hypot(dx, dy));
        }
        v.push_back(i);
    }
    return d;
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d", &n) == 1 && n) {
        for(int i = 1; i <= n; ++i) scanf("%lf%lf", &a[i].first, &a[i].second);
        sort(a + 1, a + 1 + n);

        double d = dfs(1, n);
        if(d >= 1e4) {puts("INFINITY"); continue;}
        printf("%.4f\n", d);
    }
    return 0;
}
