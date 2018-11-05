
//  Created by TaoSama.
//  Copyright (c) 2017 TaoSama. All rights reserved.
//
#include <cstdio>
#include <iostream>
#include <stack>
using namespace std;
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, k;
int a[N];

int main(){
#ifdef LOCAL
    freopen("/Users/didi/ACM/in.txt", "r", stdin);
//  freopen("/Users/didi/ACM/out.txt", "w", stdout);
#endif
    ios::sync_with_stdio(0); cin.tie(0);
    
    while(scanf("%d%d", &n, &k) == 2){
        for(int i = 1; i <= n; ++i) scanf("%d", a + i);
        stack<long long> A, B;
        long long ans = 0, mul = 1;
        for(int l = 1, r = 0; l <= n; ++l){
            while(l > r || ((A.size() ? A.top() : 1) * mul % k)){
                B.push(a[++r]);
                mul = mul * a[r] % k;
            }
            ans += n + 1 - r;
            if(A.empty()){
                while(B.size()){
                    A.push((A.size() ? A.top() : 1) * B.top() % k);
                    B.pop();
                }
                mul = 1;
            }
            A.pop();
        }
        printf("%lld\n", ans);
    }
    return 0;
}
