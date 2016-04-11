//
//  Created by TaoSama on 2015-06-05
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
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int N = 1e5 + 10;

int n, l, r, x, a[15];

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(cin >> n >> l >> r >> x) {
        for(int i = 0; i < n; ++i) cin >> a[i];
        int ans = 0;
        for(int i = 0; i < 1 << n; ++i) {
            int Min = INF, Max = -INF, sum = 0;
            for(int j = 0; j < n; ++j) {
                if(i >> j & 1) {
                    Min = min(Min, a[j]);
                    Max = max(Max, a[j]);
                    sum += a[j];
                }
            }
            //cout<<endl;
            //cout << Max << ' ' << Min << ' ' << sum << endl;
            if(sum >= l && sum <= r && Max - Min >= x) ++ ans;
        }
        cout << ans << endl;
    }
    return 0;
}
