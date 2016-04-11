//
//  Created by TaoSama on 2015-05-27
//  Copyright (c) 2015 TaoSama. All rights reserved.
//
#include <algorithm>
#include <cstdio>
#include <iostream>

using namespace std;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int N = 1e5 + 10;

long long m, h1, a1, x1, y1, h2, a2, x2, y2;

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    cin >> m;
    cin >> h1 >> a1 >> x1 >> y1;
    cin >> h2 >> a2 >> x2 >> y2;

    long long ans = 0;
    //求a的不循环节长
    while(h1 != a1) {
        h1 = (h1 * x1 + y1) % m;
        h2 = (h2 * x2 + y2) % m;
        ++ ans;
        if(ans > m) {
            cout << "-1\n";
            return 0;
        }
    }
    if(h2 == a2) {
        cout << ans << "\n";
        return 0;
    }

    long long per = 0, px2 = 1, py2 = 0;
    //a的循环节长度
    while(per == 0 || h1 != a1) {
        h1 = (h1 * x1 + y1) % m;
        px2 = (px2 * x2) % m;
        py2 = (py2 * x2 + y2) % m;
        ++per;
        if(per > m) {
            cout << "-1\n";
            return 0;
        }
    }

    long long cycle = 0;
    //来暴力匹配下b 上界是m/per 直接写m也行
    while(h2 != a2) {
        h2 = (px2 * h2 + py2) % m;
        ++cycle;
        if(cycle > m) {
            cout << "-1\n";
            return 0;
        }
    }
    ans += per * cycle;
    cout << ans << "\n";

    return 0;
}
