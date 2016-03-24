//
//  Created by TaoSama on 2015-07-27
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

int n, m, t;
long long c[35][35];

void InitC() {
    for(int i = 0; i <= 30; ++i) {
        for(int j = 0; j <= i; ++j) {
            if(i == j || j == 0) c[i][j] = 1;
            else c[i][j] = c[i - 1][j] + c[i - 1][j - 1];
        }
    }
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    InitC();
    while(cin >> n >> m >> t) {
        long long ans = 0;
        for(int i = 4; i <= n; ++i) {
            int j = t - i;
            if(j > m) continue;
            if(j < 1) break;
            ans += 1LL * c[n][i] * c[m][j];
        }
        cout << ans << '\n';
    }
    return 0;
}
