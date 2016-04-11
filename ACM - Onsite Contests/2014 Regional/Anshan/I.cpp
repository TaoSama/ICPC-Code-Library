//
//  Created by TaoSama on 2015-10-10
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
long double x[1005], y[1005], t[1005];

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int T; cin >> T;
    while(T--) {
        cin >> n;
        for(int i = 1; i <= n; ++i) {
            cin >> t[i] >> x[i] >> y[i];
        }
        long double maxv = -1e20;
        for(int i = 1; i < n; ++i) {
            long double d = sqrt((x[i] - x[i + 1]) * (x[i] - x[i + 1]) +
                                 (y[i] - y[i + 1]) * (y[i] - y[i + 1]));
            maxv = max(maxv, d / (t[i + 1] - t[i]));
        }
        cout << fixed << setprecision(12) << maxv << '\n';
    }
    return 0;
}
