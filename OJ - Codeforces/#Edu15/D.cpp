//
//  Created by TaoSama on 2016-07-29
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
const int N = 1e6 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

typedef long long LL;
LL d, k, a, b, t;

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(cin >> d >> k >> a >> b >> t) {
        LL ans = d * b; //walk
        if(d <= k) ans = min(ans, d * a); //only car
        else {
            ans = min(ans, k * a + (d - k) * b); //1 car

            LL delta = k * a - k * b + t;
            if(delta < 0) {
                LL times = d / k; //car + 1 foot
                LL cost = (k * a + t) * times - t;
                cost += (d - k * times) * b;
                ans = min(ans, cost);

                cost = (k * a + t) * times; //all car
                cost += (d - k * times) * a;
                ans = min(ans, cost);
            }
        }
        cout << ans << endl;

    }

    return 0;
}
