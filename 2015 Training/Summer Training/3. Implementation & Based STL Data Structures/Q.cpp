//
//  Created by TaoSama on 2015-07-20
//  Copyright (c) 2015 TaoSama. All rights reserved.
//
//#pragma comment(linker, "/STACK:1024000000,1024000000")
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

int n, m;
double water;
vector<double> v;

bool check(double x) {
    double sum = 0;
    for(int i = 0; i < v.size(); ++i) {
        if(x > v[i]) sum += (x - v[i]) * 100.0;
    }
    return sum >= water;
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int kase = 0;
    while(scanf("%d%d", &n, &m) && (n || m)) {
        v.clear();
        for(int i = 1; i <= n; ++i) {
            for(int j = 1; j <= m; ++j) {
                double x; scanf("%lf", &x);
                v.push_back(x);
            }
        }
        scanf("%lf", &water);

        double l = -1e10, r = 1e10;
        for(int i = 1; i <= 100; ++i) {
            double mid = (l + r) / 2;
//          prln(m);
            if(check(mid)) r = mid;
            else l = mid;
        }
        int cnt = 0;
        for(int i = 0; i < v.size(); ++i)
            if(v[i] < l) ++cnt;


        printf("Region %d\n", ++kase);
        printf("Water level is %.2f meters.\n", l);
        printf("%.2f percent of the region is under water.\n\n", cnt * 100.0 / (n * m));
    }
    return 0;
}
