
//  Created by TaoSama.
//  Copyright (c) 2017 TaoSama. All rights reserved.
//
#include <bits/stdc++.h>
using namespace std;
const int N = 50 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, a[N], b[N];
int p[N];

int find(int x) { return p[x] = p[x] == x ? x : find(p[x]); }

int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }

int main(){
#ifdef LOCAL
    freopen("/Users/didi/ACM/in.txt", "r", stdin);
//  freopen("/Users/didi/ACM/out.txt", "w", stdout);
#endif
    ios::sync_with_stdio(0); cin.tie(0);
    
    int t; cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; ++i) p[i] = i;
        int cnt = n - 1;
        memset(b, 0, sizeof b);
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
            b[a[i]]++;
            for (int j = 1; j < i; ++j) {
                if (gcd(a[i], a[j]) == 1) {
                    int fa = find(i), fb = find(j);
                    if (fa != fb) {
                        -- cnt;
                        p[fa] = fb;
                    }
                }
            }
        }
        if (cnt > 0) {
            cnt = 1; 
            if (a[1] == 29) a[1] = 31; 
            else a[1] = 29;
        }
        cout << cnt << endl;
        for (int i = 1; i <= n; ++i) cout << a[i] << " \n"[i == n];
    }
    return 0;
}
