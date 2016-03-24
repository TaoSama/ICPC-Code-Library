//
//  Created by TaoSama on 2015-04-25
//  Copyright (c) 2015 TaoSama. All rights reserved.
//
#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <set>
#include <vector>

using namespace std;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int N = 1e5 + 10;

int n;
string s, t;

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    cin >> n;
    int kase = 0;
    while(n--) {
        cout << "Case " << ++kase << ": ";
        cin >> s >> t;
        bool same = false;
        if(s[0] < t[0]) cout << "< ";
        else if(s[0] == t[0]) cout << "= ";
        else cout << "> ";

        if(s[1] == t[1]) same = true;
        if(same) {
            if(s[2] < t[2]) cout << "<";
            else if(s[2] == t[2]) {
                int ss = (s[3] - '0') * 10 + s[4] - '0';
                int tt = (t[3] - '0') * 10 + t[4] - '0';
                if(ss < tt) cout << "<";
                else if(ss == tt) {
                    if(s[5] < t[5]) cout << "<";
                    else if(s[5] == t[5]) cout << "=";
                    else cout << ">";
                } else cout << ">";
            } else cout << ">";
        } else {
            if(s[2] < t[2]) cout << "<";
            else if(s[2] == t[2]) {
                int ss = (s[3] - '0') * 10 + s[4] - '0';
                int tt = (t[3] - '0') * 10 + t[4] - '0';
                if(ss < tt) cout << "<";
                else if(ss == tt) cout << "=";
                else cout << ">";
            } else cout << ">";
        }
        cout<<'\n';
    }
    return 0;
}
