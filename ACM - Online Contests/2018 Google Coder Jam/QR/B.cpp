
//  Created by TaoSama.
//  Copyright (c) 2017 TaoSama. All rights reserved.
//
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n;

int main(){
#ifdef LOCAL
    freopen("/Users/didi/ACM/in.txt", "r", stdin);
//  freopen("/Users/didi/ACM/out.txt", "w", stdout);
#endif
    ios::sync_with_stdio(0); cin.tie(0);
    
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        vector<int> odd, even;
        odd.reserve(n);
        even.reserve(n);
        for(int i = 1; i <= n; ++i) {
            int x; cin >> x;
            if(i & 1) odd.emplace_back(x);
            else even.emplace_back(x);
        }
        sort(odd.begin(), odd.end());
        reverse(odd.begin(), odd.end());
        sort(even.begin(), even.end());
        reverse(even.begin(), even.end());
        vector<int> last;
        last.reserve(n);
        while(odd.size()) {
            last.emplace_back(odd.back()); 
            odd.pop_back();
            if(even.size()) {
                last.emplace_back(even.back());
                even.pop_back();
            }
        }
        int ans = -1;
        for(int i = 0; i + 1 < last.size(); ++i) {
            if(last[i] > last[i + 1]) {
                ans = i;
                break;
            }
        }
        static int kase = 0;
        cout << "Case #" << ++kase << ": ";
        if(ans == -1) cout << "OK\n";
        else cout << ans << '\n';
    }
    return 0;
}
