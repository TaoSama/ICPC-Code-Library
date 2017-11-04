//
//  Created by TaoSama on 2017-04-22
//  Copyright (c) 2017 TaoSama. All rights reserved.
//
#pragma comment(linker, "/STACK:102400000,102400000")
#include <bits/stdc++.h>

using namespace std;
#define pr(x) cerr << #x << " = " << x << "  "
#define prln(x) cerr << #x << " = " << x << endl
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;



int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int t; cin >> t;
    while(t--) {
        string s; cin >> s;
        for(int i = 0; i < s.size(); ++i) {
            if(s[i] == '0') cout << 0;
            else if(s[i] == '2') cout << 2;
            else if(s[i] == '4') cout << 4;
            else if(s[i] == '6') cout << 6;
            else if(s[i] == '9') cout << 9;
            if(i + 2 < s.size()) {
                string two = s.substr(i, 3);
                if(two == "two") cout << 2;
                else if(two == "six") cout << 6;
                if(i + 3 < s.size()) {
                    two += s[i + 3];
                    if(two == "zero") cout << 0;
                    else if(two == "four") cout << 4;
                    else if(two == "nine") cout << 9;
                }
            }
        }
        cout << '\n';
    }

    return 0;
}
