
//  Created by TaoSama.
//  Copyright (c) 2017 TaoSama. All rights reserved.
//
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

string numbers = "0123456789";
string lower_case = "abcdefghijklmnopqrstuvwxyz";
string upper_case = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
string special_characters = "!@#$%^&*()-+";

int main(){
#ifdef LOCAL
    freopen("/Users/didi/ACM/in.txt", "r", stdin);
//  freopen("/Users/didi/ACM/out.txt", "w", stdout);
#endif
    ios::sync_with_stdio(0); cin.tie(0);
    
    string s; int n;
    cin >> n >> s;
    int m = 0;
    vector<string> v{numbers, lower_case, upper_case, special_characters};
    for(const auto& x : v) {
        m += any_of(s.begin(), s.end(), [&](char c){return find(x.begin(), x.end(), c) != x.end();});
    }
    cout << max({0, 4 - m, 6 - n}) << endl;
    return 0;
}
