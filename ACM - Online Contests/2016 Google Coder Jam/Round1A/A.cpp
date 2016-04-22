//
//  Created by TaoSama on 2016-04-16
//  Copyright (c) 2016 TaoSama. All rights reserved.
//
#pragma comment(linker, "/STACK:102400000,102400000")
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

string s;

int main() {
#ifdef LOCAL
    freopen("A-large.in", "r", stdin);
    freopen("A-large.out", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);

    int t; cin >> t;
    while(t--) {
        cin >> s;
        string t(1, s[0]);
        for(int i = 1; i < s.size(); ++i) {
            if(s[i] >= t[0]) t.insert(0, 1, s[i]);
            else t = t + s[i];
        }
        static int kase = 0;
        cout << "Case #" << ++kase << ": " << t << '\n';
    }
    return 0;
}
