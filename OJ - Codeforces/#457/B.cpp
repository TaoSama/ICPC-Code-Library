
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
    
    long long n, k;
    while(cin >> n >> k) {
        priority_queue<int> q;
        for(int i = 0; i < 63; ++i) if(n >> i & 1) q.push(i);
        while(q.size() < k) {
            int u = q.top(); q.pop();
            q.push(u - 1);
            q.push(u - 1);
        }
        if(q.size() != k) cout << "No\n";
        else {
            cout << "Yes\n";
            while(q.size()) {
                cout << q.top() << ' ';
                q.pop();
            }
            cout << '\n';
        }
    }
    return 0;
}
