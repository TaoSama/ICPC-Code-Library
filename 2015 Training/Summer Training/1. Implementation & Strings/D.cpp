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

int n, a[1005], b[1005], c1[10], c2[10];

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int kase = 0;
    while(cin >> n && n) {
        cout << "Game " << ++kase << ":\n";

        memset(c1, 0, sizeof c1);
        for(int i = 1; i <= n; ++i) cin >> a[i], ++c1[a[i]];
        while(true) {
            int strong = 0, all = 0;
            memset(c2, 0, sizeof c2);
            for(int i = 1; i <= n; ++i) {
                cin >> b[i];
                if(a[i] == b[i]) ++strong;
                ++c2[b[i]];
            }
            if(b[1] == 0) break;
            for(int i = 1; i <= 9; ++i) all += min(c1[i], c2[i]);
            cout << "    (" << strong << "," << all - strong << ")\n";
        }
    }
    return 0;
}
