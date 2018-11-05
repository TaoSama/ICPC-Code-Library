
//  Created by TaoSama.
//  Copyright (c) 2017 TaoSama. All rights reserved.
//
#include <bits/stdc++.h>
using namespace std;
const int N = 1e4 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

struct BIT {
    int b[N], n;
    void init(int _n) {
        n = _n;
        for(int i = 0; i <= n; ++i) b[i] = 0;
    }
    void add(int i, int x) {
        for(; i <= n; i += i & -i) if((b[i] += x) >= MOD) b[i] -= MOD;
    }
    int sum(int i) {
        int ret = 0;
        for(; i; i -= i & -i) if((ret += b[i]) >= MOD) ret -= MOD;
        return ret;
    }
} bit[N];

int n, a[N];
int f[N][N];
int g[N], h[N];
int ans[N];

int main(){
#ifdef LOCAL
    freopen("/Users/didi/ACM/in.txt", "r", stdin);
//  freopen("/Users/didi/ACM/out.txt", "w", stdout);
#endif
    ios::sync_with_stdio(0); cin.tie(0);
    
    int t; scanf("%d", &t);
    while(t--) {
        scanf("%d", &n);
        for(int i = 1; i <= n; ++i)
            scanf("%d", a + i);
        for(int i = 1; i <= n; ++i) h[i] = INF;
        int maxl = 0;
        for(int i = 1; i <= n; ++i) {
            g[i] = lower_bound(h + 1, h + 1 + n, a[i]) - h;
            maxl = max(maxl, g[i]);
            h[g[i]] = a[i];
        }
        // cout << "maxl="<<maxl<<endl;
        for(int j = 0; j <= maxl; ++j) bit[j].init(n);
        for(int i = 1; i <= n; ++i) {
            for(int j = maxl; j >= 1; --j) {
                bit[j].add(a[i], bit[j - 1].sum(a[i] - 1));
            }
            bit[1].add(a[i], 1);
        }
        static int kase = 0;
        printf("Case #%d: ", ++kase);
        for(int i = 1; i <= n; ++i) {
            ans[i] = i <= maxl ? bit[i].sum(n) : 0;
            printf("%d%c", ans[i], " \n"[i == n]);  
        }
    }
    return 0;
}
