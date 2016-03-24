//
//  Created by TaoSama on 2015-07-20
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
string s[105];

void print(int n, int x) {
    cout << s[x];
    for(int i = s[x].size(); i < n; ++i) cout << ' ';
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
//  ios_base::sync_with_stdio(0);

    while(cin >> n) {
        int maxl = 0;
        for(int i = 1; i <= n; ++i) {
            cin >> s[i];
            maxl = max(maxl, (int)s[i].size());
        }
        sort(s + 1, s + 1 + n);

//      cout << maxl << endl;
        int c = (60 - maxl) / (maxl + 2) + 1;
        int r = (n + c - 1) / c;

        cout << string(60, '-') << '\n';
        for(int i = 1; i <= r; ++i) {
            for(int j = 1; j <= c; ++j) {
                int p = (j - 1) * r + i;
                if(p <= n) print(j == c ? maxl : maxl + 2, p);
            }
            cout << '\n';
        }
    }
    return 0;
}
