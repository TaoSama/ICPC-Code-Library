//
//  Created by TaoSama on 2015-08-09
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

int k, a[15];

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(cin >> k) {
        int ans = INF;
        for(int i = 0; i < 12; ++i) cin >> a[i];
        for(int i = 0; i < 1 << 12; ++i) {
            int sum = 0;
            for(int j = 0; j < 12; ++j) {
                if(i >> j & 1) sum += a[j];
            }
            if(sum >= k) ans = min(ans, __builtin_popcount(i));
        }
        if(ans == INF) ans = -1;
        cout << ans << '\n';
    }
    return 0;
}
