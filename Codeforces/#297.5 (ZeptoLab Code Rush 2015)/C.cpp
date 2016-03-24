//
//
//
//  Created by TaoSama on 2015-04-05
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

long long c, hr, hb, wr, wb;

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(cin >> c >> hr >> hb >> wr >> wb) {
        long long ans = 0;
        if(wr > wb) swap(wr, wb), swap(hr, hb);
        if(wb * wb >= c) {
            for(int i = 0; i <= c / wb; ++i)
                ans = max(ans, i * hb + (c - wb * i) / wr * hr);
        } else {
            if(hr * wb > hb * wr) swap(wr, wb), swap(hr, hb);
            for(int i = 0; i <= wb; ++i)
                ans = max(ans, i * hr + (c - wr * i) / wb * hb);
			//hr * wb < hb * wr 能买的起r 不如买b 所以枚举wb个r
        }
        cout << ans << endl;
    }
    return 0;
}
