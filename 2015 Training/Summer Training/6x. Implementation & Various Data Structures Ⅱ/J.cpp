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

int n, m, a[10];

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int kase = 0;
    while(cin >> n && n) {
        for(int i = 1; i <= n; ++i) {
            char op[5]; cin >> op;
            a[i] = op[1] - '0';
        }
        string code; cin >> code >> m;
        cout << "S-Tree #" << ++kase << ":\n";
        for(int i = 1; i <= m; ++i) {
            string s; cin >> s;
            int x = 0;
            for(int j = 1; j <= n; ++j) {
//              cout << s[a[j] - 1] << endl;
                x = (x << 1) + s[a[j] - 1] - '0';
            }
            cout << code[x];
        }
        cout << "\n\n";
    }
    return 0;
}
