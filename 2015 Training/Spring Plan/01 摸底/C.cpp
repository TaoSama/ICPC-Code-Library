//
//  ACdream 1682 娜娜梦游仙境系列——吃不完的糖果
//
//  Created by TaoSama on 2015-04-11
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

int a[N];

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//	freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        int sum = 0;
        for(int i = 1; i <= n; ++i) {
            cin >> a[i];
            sum += a[i];
        }

        int t = 0, tt = 0, Max = -INF, Min = INF;
        for(int i = 1; i <= n; ++i) {
            t += a[i];      //最大子串
            if(t > Max)  Max = t;
            if(t < 0) t = 0;

            tt += a[i];    //最小子串
            if(tt < Min) Min = tt;
            if(tt > 0) tt = 0;
        }

        int ans = max(Max, sum - Min);
        cout << ans << endl;
    }
    return 0;
}
