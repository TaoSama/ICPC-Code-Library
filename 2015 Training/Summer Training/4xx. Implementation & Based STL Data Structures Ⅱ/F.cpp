//
//  Created by TaoSama on 2015-07-21
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

int n, x[1005], y[1005];

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int t; cin >> t;
    while(t--) {
        cin >> n;
        int minx = INF, maxx = -INF;
        map<pair<int, int>, bool> mp;
        for(int i = 1; i <= n; ++i) {
            cin >> x[i] >> y[i];
            mp[ {x[i], y[i]}] = true;
            minx = min(minx, x[i]);
            maxx = max(maxx, x[i]);
        }

        int sum = minx + maxx;
//        prln(mid);
        int all = n;
        for(int i = 1; i <= n; ++i) {
            if(mp.count({x[i], y[i]})) {
//              pr(x[i]); prln(y[i]);
                if(x[i] << 1 == sum) {
                    --all;
                    continue;
                }
                int nx = sum - x[i], ny = y[i];
//                pr(nx); prln(ny);
                if(mp.count({nx, ny})) {
                    all -= 2;
                    mp.erase({x[i], y[i]});
                    mp.erase({nx, ny});
                }
            }
        }
        cout << (all ? "NO" : "YES") << '\n';
    }
    return 0;
}
