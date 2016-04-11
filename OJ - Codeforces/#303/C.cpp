//
//  Created by TaoSama on 2015-05-20
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

int n, l[N], r[N];

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d", &n) == 1) {
        for(int i = 1; i <= n; ++i) {
            scanf("%d%d", l + i, r + i);
        }

        int ans = 1, t = -INF;
        for(int i = 1; i < n; ++i) {
            if(l[i] - r[i] > t) {
                ++ans;
                t = l[i];
            } else {
                if(l[i] + r[i] < l[i + 1]) {
                    t = l[i] + r[i];
                    ++ans;
                } else t = l[i];
            }
            //cout<<i<<':'<<t<<endl;
        }
        cout << ans << '\n';
    }
    return 0;
}
