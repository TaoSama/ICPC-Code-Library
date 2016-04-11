//
//  Created by TaoSama on 2015-04-28
//  Copyright (c) 2015 TaoSama. All rights reserved.
//
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
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int N = 1e5 + 10;

int n, k, a[1005], b[1005];
double y[1005];

bool check(double x) {
    for(int i = 1; i <= n; ++i)
        y[i] = a[i] - x * b[i];
    sort(y + 1, y + 1 + n);

    /*for(int i = 1; i <= n; ++i)
        cout<<y[i]<<' ';
    cout<<endl<<endl; */

    double sum = 0;
    for(int i = 1; i <= n - k; ++i)
        sum += y[n - i + 1];
    return sum >= 0;
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(cin >> n >> k && (n + k)) {
        for(int i = 1; i <= n; ++i) cin >> a[i];
        for(int i = 1; i <= n; ++i) cin >> b[i];

        double l = 0, r = 1;
        for(int i = 0; i < 100; ++i) {
            double mid = (l + r) / 2;
            if(check(mid)) l = mid;
            else r = mid;
        }
        cout << (int)(l * 100 + 0.5) << '\n';
    }
    return 0;
}
