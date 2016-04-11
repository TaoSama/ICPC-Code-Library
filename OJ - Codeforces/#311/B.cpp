//
//  Created by TaoSama on 2015-06-30
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
const int N = 2e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, w, a[N];

bool check(double x) {
    double e = x / 3.0 / n;
    for(int i = n << 1; i; --i) {
        if(i > n) {
            if(a[i] < 2 * e) return false;
        } else {
            if(a[i] < e) return false;
        }
    }
    return true;
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(cin >> n >> w) {
        for(int i = 1; i <= n << 1; ++i) cin >> a[i];
        sort(a + 1, a + 1 + (n << 1));
        double l = 0, r = w;
        for(int i = 1; i <= 100; ++i) {
            double mid = (l + r) / 2.0;
            if(check(mid)) l = mid;
            else r = mid;
        }
        cout << fixed << setprecision(12) << l << endl;
    }
    return 0;
}
