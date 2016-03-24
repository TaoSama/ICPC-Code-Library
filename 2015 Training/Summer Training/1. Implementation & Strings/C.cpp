//
//  Created by TaoSama on 2015-07-18
//  Copyright (c) 2015 TaoSama. All rights reserved.
//
//#pragma comment(linker, "/STACK:1024000000,1024000000")
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
#define pr(x) cout << #x << " = " << x << "  "
#define prln(x) cout << #x << " = " << x << endl
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

const string msg[] = {" -- is not a palindrome.", " -- is a regular palindrome.",
                      " -- is a mirrored string.", " -- is a mirrored palindrome."
                     };
const string rev = "A   3  HIL JM O   2TUVWXY51SE Z  8 ";

char getRev(char c) {
    if(isalpha(c)) return rev[c - 'A'];
    else return rev[c - '0' + 25];
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    string s;
    while(cin >> s) {
        bool p = true, m = true;
        int n = s.size();
        for(int i = 0; i < (n + 1) / 2; ++i) {
//          pr(s[i]); pr(s[n - i - 1]); prln(getRev(s[i]));
            if(s[i] != s[n - i - 1]) p = false;
            if(getRev(s[i]) != s[n - i - 1]) m = false;
        }
//        pr(p); prln(m);
        cout << s << msg[m * 2 + p] << "\n\n";
    }
    return 0;
}
