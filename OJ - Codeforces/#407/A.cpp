//
//  Created by TaoSama on 2017-03-29
//  Copyright (c) 2016 TaoSama. All rights reserved.
//
#pragma comment(linker, "/STACK:102400000,102400000")
#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <set>
#include <vector>

using namespace std;
#define pr(x) cerr << #x << " = " << x << "  "
#define prln(x) cerr << #x << " = " << x << endl
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, a[N];
typedef long long LL;
LL f[N][3];

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(cin >> n) {
        memset(f, 0xc0, sizeof f);
        for(int i = 1; i <= n; ++i) cin >> a[i];
        f[1][0] = 0;
        LL ans = -1e18;
        for(int i = 2; i <= n; ++i) {
            int diff = abs(a[i - 1] - a[i]);
            f[i][0] = 0;
            f[i][1] = max({f[i][1], max(f[i - 1][0], f[i - 1][2]) + diff});
            f[i][2] = max(f[i][2], f[i - 1][1] - diff);
//          pr(i); pr(f[i][0]); pr(f[i][1]);prln(f[i][2]);
            ans = max({ans, f[i][0], f[i][1], f[i][2]});
        }
        cout << ans << endl;
    }

    return 0;
}
