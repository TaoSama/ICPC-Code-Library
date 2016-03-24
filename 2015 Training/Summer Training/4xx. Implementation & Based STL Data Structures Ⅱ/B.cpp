//
//  Created by TaoSama on 2015-07-21
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

int n, a[1005][20];

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int t; cin >> t;
    while(t--) {
        cin >> n;
        for(int i = 1; i <= n; ++i) cin >> a[0][i];

        bool zero = false;
        for(int i = 1; i <= 1000; ++i) {
            for(int j = 1; j <= n; ++j) {
                a[i][j] = abs(a[i - 1][j] - a[i - 1][j == n ? 1 : j + 1]);
            }
            if(count(a[i] + 1, a[i] + 1 + n, 0) == n) zero = true;
        }
        cout << (zero ? "ZERO" : "LOOP") << '\n';
    }
    return 0;
}
