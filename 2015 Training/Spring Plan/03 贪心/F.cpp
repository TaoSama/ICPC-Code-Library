//
//
//
//  Created by TaoSama on 2015-04-22
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

int n, A, B, a[105], s, g;

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(cin >> n >> A >> B) {
        for(int i = 1; i <= n; ++i) cin >> a[i];
        a[n + 1] = -INF, a[n + 2] = INF;
        sort(a + 1, a + 3 + n);

        int ans = A, Min = -INF;
        int ta, tb;
        for(int i = 1; i <= n + 1; ++i) {
            int mid = a[i] + a[i + 1] >> 1;
            if(mid >= A && mid <= B && mid - a[i] > Min) {
                Min = mid - a[i];
                ans = mid;
                //cout << a[i] << ' ' << Min << ' ' << ans << endl;
            }
            if(A >= a[i] && A <= a[i + 1])
                ta = min(A - a[i], a[i + 1] - A);
            if(B >= a[i] && B <= a[i + 1])
                tb = min(B - a[i], a[i + 1] - B);
        }
        if(ta >= Min) ans = A, Min = ta;
        if(tb > Min) ans = B;

        cout << ans << endl;
    }
    return 0;
}
