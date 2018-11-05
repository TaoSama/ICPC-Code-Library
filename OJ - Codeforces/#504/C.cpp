
//  Created by TaoSama.
//  Copyright (c) 2017 TaoSama. All rights reserved.
//
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, k;
string s;

int main(){
#ifdef LOCAL
    freopen("/Users/didi/ACM/in.txt", "r", stdin);
    //  freopen("/Users/didi/ACM/out.txt", "w", stdout);
#endif
    ios::sync_with_stdio(0); cin.tie(0);

    while(cin >> n >> k >> s) {
        string t;
        for(char c : s) {
            if(c == '(') t += c;
            else {
                if(k < n) {
                    k += 2;
                    t.pop_back();
                } else t += c;
            }
        }
        cout << t << endl;
    }
    return 0;
}
