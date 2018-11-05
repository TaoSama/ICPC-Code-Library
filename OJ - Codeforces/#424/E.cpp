
//  Created by TaoSama.
//  Copyright (c) 2017 TaoSama. All rights reserved.
//
#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

typedef long long LL;
struct BIT{
    int n, b[N];
    void init(int _n){
        n = _n;
        memset(b, 0, sizeof b);
    }
    void add(int i, int v){
        for(; i <= n; i += i & -i) b[i] += v;
    }
    int sum(int i){
        LL ret = 0;
        for(; i; i -= i & -i) ret += b[i];
        return ret;
    }
} bit;

int n;

int main(){
#ifdef LOCAL
    freopen("/Users/didi/ACM/in.txt", "r", stdin);
//  freopen("/Users/didi/ACM/out.txt", "w", stdout);
#endif
    ios::sync_with_stdio(0); cin.tie(0);
    
    while(cin >> n){
        LL ans = 0;
        bit.init(n);
        for(int i = 1; i <= n; ++i){
            int x; cin >> x;
            int cur = i - bit.sum(x);
            ans += cur;
            bit.add(x, cur);
        }
        cout << ans << endl;
    }
    return 0;
}
