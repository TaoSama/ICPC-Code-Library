//
//  Created by TaoSama on 2015-08-09
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

int n, a[35][35], row[35], col[25];

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(cin >> n) {
        for(int i = 1; i <= n; ++i)
            for(int j = 1; j <= n; ++j)
                cin >> a[i][j];

        for(int i = 1; i <= n; ++i)
            row[i] = accumulate(a[i] + 1, a[i] + 1 + n, 0);
        for(int j = 1; j <= n; ++j) {
            int sum = 0;
            for(int i = 1; i <= n; ++i)
                sum += a[i][j];
            col[j] = sum;
        }
        int ans = 0;
        for(int i = 1; i <= n; ++i) {
            for(int j = 1; j <= n; ++j)
                if(col[j] > row[i]) ++ans;
        }
        cout << ans << '\n';
    }
    return 0;
}
