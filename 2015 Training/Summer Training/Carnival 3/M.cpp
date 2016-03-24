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

int n, m;
set<char> s[105];
char a[105][105];

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    cin >> n >> m;
    for(int i = 1; i <= n; ++i) cin >> (a[i] + 1);
    for(int j = 1; j <= m; ++j)
        for(int i = 1; i <= n; ++i)
            s[j].insert(a[i][j]);

    long long ans = 1;
    for(int i = 1; i <= m; ++i) {
        long long x = s[i].size();
        ans = ans * x % MOD;
    }
    cout << ans << '\n';

    return 0;
}
