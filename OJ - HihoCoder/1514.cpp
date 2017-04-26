//
//  Created by TaoSama on 2017-04-26
//  Copyright (c) 2017 TaoSama. All rights reserved.
//
#pragma comment(linker, "/STACK:102400000,102400000")
#include <bits/stdc++.h>

using namespace std;
#define pr(x) cerr << #x << " = " << x << "  "
#define prln(x) cerr << #x << " = " << x << endl
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;


int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    vector<vector<int>> v(3);
    for(int i = 0; i < 3; ++i) {
        int sz; scanf("%d", &sz);
        v[i].resize(sz);
    }
    for(int i = 0; i < 3; ++i) {
        for(int& x : v[i]) scanf("%d", &x);
        sort(v[i].begin(), v[i].end());
    }

    vector<int> r(3);
    for(int i = 0; i < 3; ++i) r[i] = i;
    long long ans = 1e18;
    do {
        vector<int>& a = v[r[0]];
        vector<int>& b = v[r[1]];
        vector<int>& c = v[r[2]];
        for(int x : b) {
            auto pre = upper_bound(a.begin(), a.end(), x);
            if(pre == a.begin()) continue;
            --pre;
            auto nxt = lower_bound(c.begin(), c.end(), x);
            if(nxt == c.end()) continue;
            ans = min(ans, 0LL + x - *pre + *nxt - x + *nxt - *pre);
        }
    } while(next_permutation(r.begin(), r.end()));
    printf("%lld\n", ans);

    return 0;
}
