
//  Created by TaoSama.
//  Copyright (c) 2017 TaoSama. All rights reserved.
//
#include <cstdio>
#include <iostream>
#include <set>
#include <map>
using namespace std;
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, k;
int a[N], b[N], pre[N];

int main(){
#ifdef LOCAL
    freopen("/Users/didi/ACM/in.txt", "r", stdin);
//  freopen("/Users/didi/ACM/out.txt", "w", stdout);
#endif
    ios::sync_with_stdio(0); cin.tie(0);
    
    while(cin >> k >> n){
        for(int i = 1; i <= k; ++i) cin >> a[i];
        map<int, int> app;
        for(int i = 1; i <= n; ++i) cin >> b[i], app[b[i]] = i;
        for(int i = 1; i <= k; ++i) pre[i] = pre[i - 1] + a[i];
        set<int> ans;
        for(int i = 1; i <= k; ++i){
            int initial = b[1] - pre[i];
            int bk = initial;
            int z = 0;
            set<int> tt;
            for(int j = 1; j <= k; ++j){
                initial += a[j];
                if(app.count(initial)) tt.insert(app[initial]);
            }
            if(tt.size() == n){
                ans.insert(bk);
            }
        }
        cout << ans.size() << endl;
        
    }
    return 0;
}
