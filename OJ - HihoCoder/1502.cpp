//
//  Created by TaoSama on 2017-04-09
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
const int N = 250 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, m, k, s[N][N];

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    cin >> n >> m >> k;
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= m; ++j) {
            cin >> s[i][j];
            s[i][j] += s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1];
        }
    }
    static auto get = [&](int x1, int y1, int x2, int y2) {
        --x1; --y1;
        return s[x1][y1] + s[x2][y2] - s[x1][y2] - s[x2][y1];
    };

    int ans = -1;
    for(int x1 = 1; x1 <= n; ++x1) {
        for(int x2 = x1; x2 <= n; ++x2) {
            for(int y1 = 1; y1 <= m; ++y1) {
                int l = y1, r = m, y2 = -1;
                while(l <= r) {
                    int m = l + r >> 1;
                    if(get(x1, y1, x2, m) <= k) l = m + 1, y2 = m;
                    else r = m - 1;
                }
                if(~y2) ans = max(ans, (x2 - x1 + 1) * (y2 - y1 + 1));
            }
        }
    }
    cout << ans << endl;

    return 0;
}
