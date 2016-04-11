//
//  Created by TaoSama on 2015-05-29
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
typedef long long  LL;

int n;
LL W, w[45];
pair<LL, LL> ps[1 << 20];

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d%lld", &n, &W) == 2) {
        for(int i = 0 ; i < n; ++i) scanf("%lld", w + i);
        int n2 = n >> 1;
        for(int i = 0; i < 1 << n2; ++i) {
            LL sw = 0, sv = 0;
            for(int j = 0; j < n2; ++j) {
                if(i >> j & 1) {
                    sw += w[j];
                    sv += w[j];
                }
            }
            ps[i] = make_pair(sw, sv);
        }
        sort(ps, ps + (1 << n2));
        int m = 1;
        for(int i = 1; i < 1 << n2; ++i) {
            if(ps[m - 1].second < ps[i].second) {
                ps[m++] = ps[i];
            }
        }

        LL ans = 0;
        for(int i = 0; i < 1 << (n - n2); ++i) {
            LL sw = 0, sv = 0;
            for(int j = 0; j < n - n2; ++j) {
                if(i >> j & 1) {
                    sw += w[n2 + j];
                    sv += w[n2 + j];
                }
            }
            if(sw <= W) {
                LL tv = (lower_bound(ps, ps + m,
                                     make_pair(W - sw, (LL)INF)) - 1)->second;
                ans = max(ans, sv + tv);
            }
        }
        printf("%lld\n", ans);
    }
    return 0;
}
