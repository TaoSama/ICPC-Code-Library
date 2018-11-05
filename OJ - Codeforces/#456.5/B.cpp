
//  Created by TaoSama.
//  Copyright (c) 2017 TaoSama. All rights reserved.
//
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n;
vector<int> G[N];
int leaf[N];

int main(){
#ifdef LOCAL
    freopen("/Users/didi/ACM/in.txt", "r", stdin);
//  freopen("/Users/didi/ACM/out.txt", "w", stdout);
#endif
    ios::sync_with_stdio(0); cin.tie(0);
    
    while(cin >> n) {
        for(int i = 1; i <= n; ++i) G[i].clear();
        for(int i = 2; i <= n; ++i) {
            int f; cin >> f;
            G[f].emplace_back(i);
        }
        bool ok = true;
        for(int i = 1; i <= n; ++i) {
            if(G[i].size() == 0) continue;
            int cnt = 0;
            for(int v : G[i]) if(G[v].size() == 0) ++cnt;
            ok &= cnt >= 3;
        }
        cout << (ok ? "Yes" : "No") << endl;
    }
    return 0;
}
