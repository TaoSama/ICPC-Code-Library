
//  Created by TaoSama.
//  Copyright (c) 2017 TaoSama. All rights reserved.
//
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;



int main(){
#ifdef LOCAL
    freopen("/Users/didi/ACM/in.txt", "r", stdin);
//  freopen("/Users/didi/ACM/out.txt", "w", stdout);
#endif
    ios::sync_with_stdio(0); cin.tie(0);
    
    int t; cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        vector<long long> a(n), b(m);
        for (int i = 0; i < n; ++i) cin >> a[i];
        for (int i = 0; i < m; ++i) cin >> b[i];
        sort(a.begin(), a.end());
        reverse(a.begin(), a.end());
        while (a.size() && a.back() == 0) a.pop_back();
        sort(b.begin(), b.end());
        reverse(b.begin(), b.end());
        while (b.size() && b.back() == 0) b.pop_back();
        cout << (a == b ? "Bob" : "Alice") << '\n';
    }
    return 0;
}
