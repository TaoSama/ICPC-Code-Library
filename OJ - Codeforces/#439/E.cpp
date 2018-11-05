
//  Created by TaoSama.
//  Copyright (c) 2017 TaoSama. All rights reserved.
//
#include <bits/stdc++.h>
using namespace std;
const int N = 2500 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

typedef long long LL;
struct BIT {
    int n, m; LL b[N][N]; 
    void init(int _n, int _m) {
        n = _n; m = _m;
        for(int i = 1; i <= n; ++i)
            for(int j = 1; j <= m; ++j) 
                b[i][j] = 0;
    }
    void add(int x, int y, int v) {
        for(int i = x; i <= n; i += i & -i) 
            for(int j = y; j <= m; j += j & -j)
                b[i][j] += v;
    }
    void add(int r1, int c1, int r2, int c2, int v) {
        add(r1, c1, v);
        add(r2 + 1, c2 + 1, v);
        add(r1, c2 + 1, -v);
        add(r2 + 1, c1, -v);
    }
    LL sum(int x, int y) {
        LL ret = 0;
        for(int i = x; i; i -= i & -i) 
            for(int j = y; j; j -= j & -j)
                ret += b[i][j];
        return ret;
    }
} bit;

int main(){
#ifdef LOCAL
    freopen("/Users/didi/ACM/in.txt", "r", stdin);
//  freopen("/Users/didi/ACM/out.txt", "w", stdout);
#endif
    ios::sync_with_stdio(0); cin.tie(0);
    
    int n, m, q;
    while(scanf("%d%d%d", &n, &m, &q) == 3) {
        random_device rd;
        default_random_engine dre(rd());
        uniform_int_distribution<LL> distribution(0, 1e13);
        auto gene = bind(distribution, dre);

        map<pair<pair<int, int>, pair<int, int>>, LL> mp;
        bit.init(n, m);
        while(q--){
            int op, r1, c1, r2, c2;
            scanf("%d%d%d%d%d", &op, &r1, &c1, &r2, &c2);
            if(op == 1) {
                LL r = gene();
                mp[{{r1, c1}, {r2, c2}}] = r;
                bit.add(r1, c1, r2, c2, r);
            }
            else if(op == 2) {
                LL r = mp[{{r1, c1}, {r2, c2}}];
                bit.add(r1, c1, r2, c2, -r);
            }
            else {
                puts(bit.sum(r1, c1) == bit.sum(r2, c2) ? "Yes" : "No");
            }
        }
    }
    return 0;
}
