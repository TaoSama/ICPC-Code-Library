
//  Created by TaoSama.
//  Copyright (c) 2017 TaoSama. All rights reserved.
//
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, m;
int a[N], b[N];
vector<int> divisors[N];
void init(){
    for(int i = 1; i < N; ++i){
        for(int j = i; j < N; j += i){
            divisors[j].push_back(i);
        }
    }
}

int main(){
#ifdef LOCAL
    freopen("/Users/didi/ACM/in.txt", "r", stdin);
//  freopen("/Users/didi/ACM/out.txt", "w", stdout);
#endif
    ios::sync_with_stdio(0); cin.tie(0);
    
    init();
    while(scanf("%d%d", &n, &m) == 2){
        for(int i = 0; i < n; ++i) scanf("%d", a + i);
        for(int i = 0; i < m; ++i) scanf("%d", b + i);
        int sz = max(n, m) + 1;
        vector<int> cb(sz, 0), vis(m, 0);
        for(int i = 0; i < m; ++i){
            if(vis[i]) continue;
            int len = 0;
            int t = i;
            while(!vis[t]){
                ++len;
                vis[t] = true;
                t = b[t];
            }
            cb[len] += len;
            // printf("%d ", len);
        }
        // puts("");
        
        vis = vector<int>(n, 0);
        long long ans = 1;
        for(int i = 0; i < n; ++i){
            if(vis[i]) continue;
            int len = 0;
            int t = i;
            while(!vis[t]){
                ++len;
                vis[t] = true;
                t = a[t];
            }
            int sum = 0;
            for(int div : divisors[len]) sum += cb[div];
            ans = ans * sum % MOD;
        }
        static int kase = 0;
        printf("Case #%d: %lld\n", ++kase, ans);
    } 
    return 0;
}
