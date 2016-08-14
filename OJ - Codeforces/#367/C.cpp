//
//  Created by TaoSama on 2016-08-12
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
#define pr(x) cout << #x << " = " << x << "  "
#define prln(x) cout << #x << " = " << x << endl
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

string s[N][2];
typedef long long LL;
int n, w[N][2];
LL f[N][2];

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(cin >> n) {
        for(int i = 1; i <= n; ++i) cin >> w[i][1];
        for(int i = 1; i <= n; ++i) {
            cin >> s[i][0];
            s[i][1] = s[i][0];
            reverse(s[i][1].begin(), s[i][1].end());
        }

        memset(f, 0x3f, sizeof f);
        f[1][0] = 0; f[1][1] = w[1][1];
        for(int i = 2; i <= n; ++i) {
            for(int j = 0; j < 2; ++j) {
                for(int k = 0; k < 2; ++k) {
                    if(s[i][j] >= s[i - 1][k])
                        f[i][j] = min(f[i][j], f[i - 1][k] + w[i][j]);
                }
            }
        }
        LL ans = min(f[n][0], f[n][1]);
        if(ans > 1e15) ans = -1;
        cout << ans << '\n';
    }

    return 0;
}
