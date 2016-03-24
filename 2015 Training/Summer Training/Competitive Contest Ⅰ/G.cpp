//
//  Created by TaoSama on 2015-08-21
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
#include <sstream>

using namespace std;
#define pr(x) cout << #x << " = " << x << "  "
#define prln(x) cout << #x << " = " << x << endl
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int S, m, n, s[125], c[125];
int dp[125][1 << 8][1 << 8];

int dfs(int i, int s0, int s1, int s2) {
    if(i == n + m) return s2 == (1 << S) - 1 ? 0 : INF;
    int &ret = dp[i][s1][s2];
    if(ret >= 0) return ret;

    ret = INF;

    if(i >= m) ret = min(ret, dfs(i + 1, s0, s1, s2));
//  printf("before: %d: %d %d %d\n", i, s0, s1, s2);
    int m1 = s0 & s[i], m2 = s[i] & s1;
    s0 ^= m1; s1 = (s1 ^ m2) | m1; s2 |= m2;
//  printf("after: %d: %d %d %d\n", i, s0, s1, s2);
    ret = min(ret, dfs(i + 1, s0, s1, s2) + c[i]);
    return ret;
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
//  ios_base::sync_with_stdio(0);

    while(cin >> S >> m >> n && (S || m || n)) {
        cin.get();
        for(int i = 0; i < n + m; ++i) {
            string line; getline(cin, line);
            stringstream ss(line);
            ss >> c[i]; int x;
            s[i] = 0;
            while(ss >> x) s[i] |= 1 << x - 1;
        }

//      for(int i = 0; i < n + m; ++i)
//          printf("%d\n", s[i]);

        memset(dp, -1, sizeof dp);
        cout << dfs(0, (1 << S) - 1, 0, 0) << '\n';
    }
    return 0;
}
