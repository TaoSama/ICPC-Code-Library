//
//  Created by TaoSama on 2015-08-03
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

int n;
pair<int, int> a[N];

bool check(double x) {
    double p = 0;
    for(int i = 1; i <= n; ++i) {
        p = max(p, 1.0 * a[i].first);
        if(p + x > a[i].second) return false;
        p += x;
    }
    return true;
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d", &n) == 1) {
        for(int i = 1; i <= n; ++i)
            scanf("%d%d", &a[i].first, &a[i].second);
        sort(a + 1, a + 1 + n);

        double l = 0, r = 1e6 + 5;
        for(int i = 1; i <= 100; ++i) {
            double m = (l + r) / 2;
            if(check(m)) l = m;
            else r = m;
        }

        int up = 0, down = 1;
        //enumerate the down
        for(int i = 1; i <= 1e5; ++i) {
            int tmp = round(i * l);
            if(abs(1.0 * tmp / i - l) < abs(1.0 * up / down - l)) {
                up = tmp;
                down = i;
            }
        }
        printf("%d/%d\n", up, down);
    }
    return 0;
}
