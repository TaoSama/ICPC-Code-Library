
//  Created by TaoSama.
//  Copyright (c) 2017 TaoSama. All rights reserved.
//
#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, T;
int a[N], b[N];

int main(){
#ifdef LOCAL
    freopen("/Users/didi/ACM/in.txt", "r", stdin);
//  freopen("/Users/didi/ACM/out.txt", "w", stdout);
#endif
    ios::sync_with_stdio(0); cin.tie(0);
    
    while(scanf("%d%d", &n, &T) == 2) {
        for(int i = 1; i <= n; ++i) scanf("%d%d", a + i, b + i);

        int l = 0, r = n, ans = 0;
        while(l <= r) {
            int m = (l + r) / 2;
            vector<int> can;
            for(int i = 1; i <= n; ++i) if(a[i] >= m) can.emplace_back(b[i]);
            bool ok = true;
            ok &= can.size() >= m;
            if(ok) {
                sort(can.begin(), can.end());
                int cur = 0;
                for(int i = 0; i < m; ++i) {
                    cur += can[i];
                    if(cur > T) {
                        ok = false;
                        break;
                    }
                }
            }
            if(ok) ans = m, l = m + 1;
            else r = m - 1;
        }
        vector<pair<int, int>> v;
        for(int i = 1; i <= n; ++i) if(a[i] >= ans) v.emplace_back(b[i], i);
        sort(v.begin(), v.end());
        printf("%d\n%d\n", ans, ans);
        for(int i = 0; i < ans; ++i) printf("%d ", v[i].second);
        printf("\n");
    }
    return 0;
}
