//
//  Created by TaoSama on 2015-08-01
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
const int N = 1e6 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, p[N], s[N], h[N];

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int t; cin >> t;
    while(t--) {
        cin >> n;
        for(int i = 1; i <= n; ++i) cin >> p[i];
        for(int i = 1; i <= n; ++i) cin >> s[i];

        int ans = 0, lev = s[1];
        for(int i = 1; i <= n; ++i) {
            //water has been interrupted, need to promote
            if(p[i] > lev) lev = p[i];
            //water is too high, need to low down
            if(s[i] < lev) lev = s[i];
            h[i] = lev;
        }

        lev = s[n];
        for(int i = n; i; --i) {
            if(p[i] > lev) lev = p[i];
            if(s[i] < lev) lev = s[i];
//          cout << h[i] << ' ' << lev << ' ' << p[i] << endl;
            ans += min(h[i], lev) - p[i];
        }
        cout << ans << '\n';
    }
    return 0;
}
