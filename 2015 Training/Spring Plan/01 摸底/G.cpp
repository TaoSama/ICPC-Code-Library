//
//  ACdream 1686 娜娜梦游仙境系列——梦醒
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

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//	freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int t; scanf("%d", &t);
    while(t--) {
        int h, m, s; scanf("%d:%d:%d", &h, &m, &s);
        double hpos = (h % 12) * 5 + (m * 60 + s) / 3600.0 * 5;
        double mpos = m + s / 60.0;

        double ans = hpos - mpos;
        if(ans <= 0) ans += 60;
        ans /= (1 / 60.0 - 5 / 3600.0);

        printf("%.6f\n", ans);
    }
    return 0;
}
