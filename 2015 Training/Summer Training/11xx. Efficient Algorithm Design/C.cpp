//
//  Created by TaoSama on 2015-07-31
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
const int N = 4e3 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, a[5][N], b[N * N], c[N * N];

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int t; cin >> t;
    while(t--) {
        cin >> n;
        for(int i = 1; i <= n; ++i)
            for(int j = 1; j <= 4; ++j) cin >> a[j][i];

        int cnt = 0;
        for(int i = 1; i <= n; ++i)
            for(int j = 1; j <= n; ++j)
                b[++cnt] = a[3][i] + a[4][j];

        sort(b + 1, b + 1 + cnt);

        int ans = 0;
        for(int i = 1; i <= n; ++i) {
            for(int j = 1; j <= n; ++j) {
                int t = a[1][i] + a[2][j];
                auto iter = lower_bound(b + 1, b + 1 + cnt, -t);
                if(iter != b + 1 + cnt) {
                    ans += upper_bound(b + 1, b + 1 + cnt, -t) - iter;
                }
            }
        }
        cout << ans << '\n';
        if(t) cout << '\n';
    }
    return 0;
}
