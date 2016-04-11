//
//  Created by TaoSama on 2015-07-22
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
const int N = 2e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

string s, t;

bool isEqual(int n, int l, int r) {
//    cout << n << ' ' ;
//    for(int i = 0; i < n; ++i) cout << s[l + i]; cout << ' ';
//    for(int i = 0; i < n; ++i) cout << t[r + i]; cout << endl;
    for(int i = 0; i < n; ++i) {
        if(s[l + i] != t[r + i]) return false;
    }
    return true;
}

bool dfs(int n, int l, int r) {
    if(n == 1) return s[l] == t[r];
    if(isEqual(n, l, r)) return true;
    if(n & 1) return false;
    return dfs(n / 2, l, r + n / 2) && dfs(n / 2, l + n / 2, r) ||
           dfs(n / 2, l, r) && dfs(n / 2, l + n / 2, r + n / 2);
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(cin >> s >> t) {
        if(dfs(s.size(), 0, 0)) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}
