
//  Created by TaoSama.
//  Copyright (c) 2017 TaoSama. All rights reserved.
//
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

typedef long long LL;
int n, p[20];
LL k;
vector<LL> lft, rgt;

const LL M = 1000000000000000000ll;
void dfs(int dep, int mx, LL x, vector<LL>& v) {
    if(dep == mx) {
        v.emplace_back(x);
        return;
    }
    while(true) {
        dfs(dep + 1, mx, x, v);
        if(p[dep] > M / x) break;
        x *= p[dep];
    }
}

int main(){
#ifdef LOCAL
    freopen("/Users/didi/ACM/in.txt", "r", stdin);
//  freopen("/Users/didi/ACM/out.txt", "w", stdout);
#endif
    ios::sync_with_stdio(0); cin.tie(0);
    
    while(cin >> n) {
        for(int i = 0; i < n; ++i) cin >> p[i];
        cin >> k;
        lft.clear(); rgt.clear();
        dfs(0, min(n, 5), 1, lft);
        dfs(min(n, 5), n, 1, rgt);

        sort(lft.begin(), lft.end());
        sort(rgt.begin(), rgt.end());
        LL l = 1, r = M, ans = -1;
        while(l <= r) {
            LL m = (l + r) / 2;
            LL cnt = 0;
            bool ok = false;
            for(LL x : lft) {
                cnt += upper_bound(rgt.begin(), rgt.end(), m / x) - rgt.begin();
                if(cnt >= k) {ok = true; break;}
            }
            if(ok) ans = m, r = m - 1;
            else l = m + 1;
        }
        cout << ans << endl;
    }
    return 0;
}
