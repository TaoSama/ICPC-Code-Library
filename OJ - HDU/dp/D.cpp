//
//  HDU 1003 Max Sum
//
//  Created by TaoSama on 2015-02-06
//  Copyright (c) 2014 TaoSama. All rights reserved.
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
#define CLR(x) memset(x, 0, sizeof(x))

using namespace std;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int N = 1e5 + 10;

int n;

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);
    int t; cin >> t;
    for(int kase = 1; kase <= t; ++kase) {
        cin >> n;
        int ans = -INF, sum = 0, x, l, r, st = 1;
        for(int i = 1; i <= n; ++i) {
            cin >> x;
            sum += x;
            if(sum > ans) {
                ans = sum;
                l = st;
                r = i;
            }
            if(sum < 0) sum = 0, st = i + 1;
        }
        if(kase > 1) cout << endl;
        cout << "Case " << kase << ":" << endl;
        cout << ans << ' ' << l << ' ' << r << endl;
    }
    return 0;
}
