
//  Created by TaoSama.
//  Copyright (c) 2017 TaoSama. All rights reserved.
//
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, a[N];
int lft[N], f[N], g[N];

void add(int& x, int y) {
    if((x += y) >= MOD) x -= MOD;
}

int main(){
#ifdef LOCAL
    freopen("/Users/didi/ACM/in.txt", "r", stdin);
//  freopen("/Users/didi/ACM/out.txt", "w", stdout);
#endif
    ios::sync_with_stdio(0); cin.tie(0);
    
    cin >> n;
    map<int, int> mp;
    for(int i = 1, l = 1; i <= n; ++i) {
        cin >> a[i];
        while(mp[a[i]]) mp[a[l++]]--;
        lft[i] = l;
        ++mp[a[i]];
    }
    f[0] = 0;
    g[0] = 1;
    for(int i = 1; i <= n; ++i) {
        f[i] = f[lft[i] - 1] + 1;
        for(int j = lft[i] - 1; j < i; ++j) {
            if(f[i] == f[j] + 1) {
                add(g[i], g[j]);
            }
        }
    }
    cout << f[n] << ' ' << g[n] << endl;
    return 0;
}
