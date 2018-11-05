
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
    
    int n; 
    while(cin >> n) {
        vector<int> a(n);
        for(int& x : a) cin >> x;
        vector<int> vis(n + 1, false), cnt(n + 1, 0);
        for(int x : a) vis[x] = true, cnt[x]++;
        vector<int> doNothing(n + 1, 0);
        int curNum = 1, ans = 0;
        for(int& x : a) {
           if(cnt[x] == 1) continue;
           for(; curNum <= n && vis[curNum]; ++curNum);
           // cout << x << ' ' << curNum <<endl;
           if(doNothing[x] || curNum < x) {
               ++ans;
               --cnt[x];
               x = curNum;
               ++curNum;
           }
           else doNothing[x] = true;
        }
        cout << ans << endl;
        for(int x : a) cout << x << ' '; cout << endl;
    }
    return 0;
}
