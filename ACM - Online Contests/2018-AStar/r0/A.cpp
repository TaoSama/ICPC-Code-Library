
//  Created by TaoSama.
//  Copyright (c) 2017 TaoSama. All rights reserved.
//
#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, m, k;
int a[N];
int diff[1 << 10];
int cnt[1 << 10];

int main(){
#ifdef LOCAL
    freopen("/Users/didi/ACM/in.txt", "r", stdin);
//  freopen("/Users/didi/ACM/out.txt", "w", stdout);
#endif
    ios::sync_with_stdio(0); cin.tie(0);
    
    int t; scanf("%d", &t);
    while(t--) {
        scanf("%d%d%d", &n, &m, &k);
        for(int i = 1; i <= n; ++i) {
            char s[20]; scanf("%s", s);
            a[i] = 0;
            for(int j = 0; j < m; ++j) a[i] |= (s[j] - 'A') << j;
        }
        for(int j = 0; j < 1 << m; ++j) diff[j] = cnt[j] = 0;
        for(int i = 1; i <= n; ++i) {
            for(int j = i + 1; j <= n; ++j) {
               diff[a[i] ^ a[j]]++; 
            }
        }
        int ans = 0;
        for(int i = 1; i < 1 << m; ++i) {
            for(int j = 1; j < 1 << m; ++j) {
                if(i & j) {
                    cnt[i] += diff[j];
                }
            }
            ans += cnt[i] >= k;
        }
        static int kase = 0;
        printf("Case #%d: %d\n", ++kase, ans);
    }
    return 0;
}
