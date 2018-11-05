
//  Created by TaoSama.
//  Copyright (c) 2017 TaoSama. All rights reserved.
//
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

string s;

int get(string s) {
    int h = s.size() / 2;
    int ans = 0;
    for(int i = 0, j; i < s.size(); i = j + 1) {
        for(j = i; j + 1 < min(i + h, h * 2) && s[j + 1] != s[j]; ++j);
        // cout << i << ' ' << j << endl;
        ans = max(ans, j - i + 1);
    }
    return ans;
}

int main(){
#ifdef LOCAL
    freopen("/Users/didi/ACM/in.txt", "r", stdin);
//  freopen("/Users/didi/ACM/out.txt", "w", stdout);
#endif
    ios::sync_with_stdio(0); cin.tie(0);
    
    while(cin >> s) {
        int ans = get(s + s);
        reverse(s.begin(), s.end());
        ans = max(ans, get(s + s));
        cout << ans << endl;
    }
    return 0;
}
