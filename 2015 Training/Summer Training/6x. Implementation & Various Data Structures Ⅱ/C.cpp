//
//  Created by TaoSama on 2015-07-24
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

int n;
string s[205];

bool can(char c) {
    if(c == ' ' || c == '-' || c == '|' || c == '#') return false;
    return true;
}

void dfs(int x, int y) {
    cout << s[x][y] << '(';
//    pr(x); prln(y);
    if(x + 1 < n && s[x + 1][y] == '|') {
        int l = y, r = y;
        while(l - 1 >= 0 && s[x + 2][l - 1] == '-') l--;
        while(r + 1 < s[x + 2].size() && s[x + 2][r + 1] == '-') r++;
//        pr(l); prln(r);
        for(int i = l; i <= r && i < s[x + 3].size(); ++i) {

            if(can(s[x + 3][i]))
                dfs(x + 3, i);
        }
    }
    cout << ')';
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int t; cin >> t; cin.get();
    while(t--) {
        n = 0;
        while(getline(cin, s[++n]) && s[n] != "#");
//        cout << n << endl;
        if(n == 1) {cout << "()\n"; continue;}
//        for(int i = 1; i < n; ++i) cout << s[i] << endl;
        for(int i = 0; i < s[1].size(); ++i) {
            if(can(s[1][i])) {
                cout << '(';
                dfs(1, i);
                cout << ')';
            }
        }
        cout << '\n';
    }
    return 0;
}
