//
//
//
//  Created by TaoSama on 2015-03-30
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

int n, t, dpp[25000], dpn[15000], c[105], v[105];

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//	freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    cin >> n >> t;
    for(int i = 1; i <= n; ++i) cin >> v[i];
    for(int i = 1; i <= n; ++i) cin >> c[i];

    memset(dpp, 0x3f, sizeof dpp);
    dpp[0] = 0;
    for(int i = 1; i <= n; ++i) {
        int k = 1;
        while(c[i] > 0) {
            int t = min(c[i], k);
            for(int j = t + 120 * 120; j >= t * v[i]; --j)
                dpp[j] = min(dpp[j], dpp[j - t * v[i]] + t);
            c[i] -= k; k <<= 1;
        }
    }
    /*for(int i = 0; i <= t + 120 * 120; ++i)
        if(dpp[i] != INF) printf("dpp[%d]: %d\n", i, dpp[i]);*/

    memset(dpn, 0x3f, sizeof dpn);
    dpn[0] = 0;
    for(int i = 1; i <= n; ++i)
        for(int j = v[i]; j <= 120 * 120; ++j)
            dpn[j] = min(dpn[j], dpn[j - v[i]] + 1);
    /*for(int i = 0; i <= 120 * 120; ++i)
        if(dpn[i] != INF) printf("dpn[%d]: %d\n", i, dpn[i]);*/

    int ans = INF;
    for(int i = 0; i <= 120 * 120; ++i)
        ans = min(ans, dpp[t + i] + dpn[i]);

    if(ans == INF) ans = -1;
    cout << ans << endl;
    return 0;
}
