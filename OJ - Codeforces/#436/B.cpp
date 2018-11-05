
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
   
    int n; string s;
    while(cin >> n >> s) {
        vector<int> positions; positions.push_back(-1);
        for(int i = 0; i < static_cast<int>(s.size()); ++i) {
            if(isupper(s[i])) positions.push_back(i); 
        }
        positions.push_back(static_cast<int>(s.size()));
        int ans = 0;
        for(int i = 0; i + 1 < static_cast<int>(positions.size()); ++i) {
            set<char> st;
            for(int j = positions[i] + 1; j < positions[i + 1]; ++j) {
                st.insert(s[j]); 
            }
            ans = max(ans, static_cast<int>(st.size()));
        }
        cout << ans << endl;
    }
    return 0;
}
