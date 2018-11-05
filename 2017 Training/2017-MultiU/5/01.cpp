
//  Created by TaoSama.
//  Copyright (c) 2017 TaoSama. All rights reserved.
//
#include <bits/stdc++.h>
using namespace std;
const int N = 5e4 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

vector<int> divisors[N];
void init() {
    for(int i = 2; i < N; ++i){
        for(int j = i; j < N; j += i){
            divisors[j].push_back(i);
        }
    }
}

int a[N], b[N];
bitset<N> A, B;
int n, m, q;

int main(){
#ifdef LOCAL
    freopen("/Users/didi/ACM/in.txt", "r", stdin);
//  freopen("/Users/didi/ACM/out.txt", "w", stdout);
#endif
    ios::sync_with_stdio(0); cin.tie(0);
    
    init();
    int t; scanf("%d", &t);
    while(t--) {
        scanf("%d%d%d", &n, &m, &q);
        A.reset();
        for(int i = 1; i <= n; ++i) {
            scanf("%d", a + i);
            A[a[i]] = 1;
        }
        vector<int> vis(N);
        for(int i = 1; i <= m; ++i) {
            int x; scanf("%d", &x);
            vis[x] = 1;
        }
        B.reset();
        for(int i = 1; i < N; ++i) {
            int cnt = 0;
            for(int div : divisors[i]) {
                cnt += vis[div];
            }
            // printf("%d = %d\n", a[i], cnt);
            B[i] = cnt & 1;
        } 
        for(int i = 1; i < N; ++i) vis[i] += vis[i - 1];
       /*  cout << B << endl; */
        /* cout << "fuck" << endl; */
        for(int i = 1; i <= q; ++i){
            int k; scanf("%d", &k);
            // printf("%d = ", k);
            int ans = ((A >> k) & (B >> (k + 1) << (k + 1))).count(); 
            ans += (A >> k)[0] ? vis[N - 1] - vis[k] : 0;
            ans += k == 0;
           /*  cout << (A >> k) << endl; */
            // cout << (B >> (k + 1) << (k + 1)) << endl;
            /* cout << "more = " << ((A >> k)[0] ? vis[N - 1] - vis[k] : 0) << endl; */
            printf("%d\n", ans & 1);
        }
    }
    return 0;
}
