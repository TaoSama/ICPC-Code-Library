//
//  Created by TaoSama on 2015-08-07
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
#include <sstream>
#include <string>
#include <set>
#include <vector>

using namespace std;
#define pr(x) cout << #x << " = " << x << "  "
#define prln(x) cout << #x << " = " << x << endl
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int S, m, n, s[125], c[125];
int dp[125][1 << 8][1 << 8];
string line;

//s0:= left  s1:= one teach  s2:= at least two teach
int dfs(int i, int s0, int s1, int s2) {
    if(i == m + n) return s2 == (1 << S) - 1 ? 0 : INF;
    int &ret = dp[i][s1][s2];
    if(ret >= 0) return ret;

    ret = INF;
    if(i >= m) ret = dfs(i + 1, s0, s1, s2); //not choose

    int m1 = s0 & s[i], m2 = s1 & s[i];
    s0 ^= m1; //delete from left set
    s1 = (s1 ^ m2) | m1; //delete ones will be changed to 2, add 1;
    s2 |= m2; //add 2 to s2
    ret = min(ret, c[i] + dfs(i + 1, s0, s1, s2)); //choose
    return ret;
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(getline(cin, line)) {
        stringstream ss(line);
        ss >> S >> m >> n;
        if(S == 0) break;
        for(int i = 0; i < m + n; ++i) {
            getline(cin, line);
            stringstream ss(line);
            ss >> c[i];
            s[i] = 0; int x;
            while(ss >> x) s[i] |= 1 << x - 1;
        }
//      for(int i = 0; i < m + n; ++i) cout << c[i] << ' ' << s[i] <<endl;
        memset(dp, -1, sizeof dp);
        cout << dfs(0, (1 << S) - 1, 0, 0) << '\n';
    }
    return 0;
}
