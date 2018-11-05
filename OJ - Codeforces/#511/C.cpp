
//  Created by TaoSama.
//  Copyright (c) 2017 TaoSama. All rights reserved.
//
#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

const int M = 1.5e7 + 10;
vector<int> primes;
int gg[M];
void gao() {
    for(int i = 1; i < M; ++i) gg[i] = i;
    for(int i = 2; i < M; ++i) {
        if(gg[i] == i) primes.push_back(i);
        for(int j = 0; j < primes.size() && i * primes[j] < M; ++j) {
            gg[i * primes[j]] = primes[j];
            if(i % primes[j] == 0) break;
        }
    }
}

int a[N], cnt[M];

int main(){
#ifdef LOCAL
    freopen("/Users/didi/Downloads/data.in", "r", stdin);
//  freopen("/Users/didi/ACM/out.txt", "w", stdout);
#endif
    ios::sync_with_stdio(0); cin.tie(0);
    
    gao();

    int n;
    while(cin >> n) {
        int g = -1;
        for(int i = 1; i <= n; ++i) {
            cin >> a[i];
            if(g == -1) g = a[i];
            else {
                g = gcd(g, a[i]);
            }
        }
        memset(cnt, 0, sizeof cnt);
        for(int i = 1; i <= n; ++i) {
            int y = a[i];
            y /= g;
            while(y > 1) {
                int t = gg[y];
                ++cnt[t];
                while(gg[y] == t) y /= t;
            }
        }

        int ans = 0;
        for(int i = 1; i < M; ++i) {
            ans = max(ans, cnt[i]);
        }
        ans = n - ans;
        if(ans == n) ans = -1;
        cout << ans << endl;
    }
    return 0;
}
