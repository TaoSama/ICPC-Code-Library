//
//  Created by TaoSama on 2015-04-27
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

string s;
string t = "CODEFORCES";
int tt = t.size();

bool gao() {
    int ss = s.size();
    if(ss < tt) return false;
    int l = 0, r = 0;
    while(l < tt && s[l] == t[l]) l++;
    while(r < tt && s[ss - r - 1] == t[tt - r - 1]) r++;
    //cout<< l<< ' ' <<r<<endl;
    return l + r >= tt;
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(cin >> s) {
        if(gao()) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}
