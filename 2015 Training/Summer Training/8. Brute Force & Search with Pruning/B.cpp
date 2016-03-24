//
//  Created by TaoSama on 2015-07-26
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

long long n, a[20];

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int kase = 0;
    while(cin >> n) {
        for(int i = 1; i <= n; ++i) cin >> a[i];
        long long ans = -1e18;
        for(int i = 1; i <= n; ++i) {
            for(int j = i; j <= n; ++j) {
                long long cur = 1;
                for(int k = i; k <= j; ++k) {
                    cur *= a[k];
                }
                ans = max(ans, cur);
            }
        }
        if(ans < 0) ans = 0;
        cout << "Case #" << ++kase << ": " << "The maximum product is " << ans <<
             ".\n\n";
    }
    return 0;
}
