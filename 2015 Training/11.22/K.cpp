//
//  Created by TaoSama on 2015-11-22
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
const int N = 2e3 + 10, INF = 0x3f3f3f3f, MOD = 10000007;

int n, m, u[N], v[N];
int b[N][N], dp[N][N];

void add(int &x, int y) {
    x = x + y + MOD;
    while(x >= MOD) x -= MOD;
}

void add(int x, int y, int v) {
    for(int i = x; i <= n; i += i & -i)
        for(int j = y; j <= m; j += j & -j)
            add(b[i][j], v);
}

int sum(int x, int y) {
    int ret = 0;
    for(int i = x; i; i -= i & -i)
        for(int j = y; j; j -= j & -j)
            add(ret, b[i][j]);
    return ret;
}

int cnt = 0;
map<string, int> mp;

int ID(string &s) {
    if(mp.count(s)) return mp[s];
    mp[s] = ++cnt;
    return cnt;
}

void handle(int &n, string &s, int *u) {
    n = 0; s += 'A';
    string tmp;
    for(int i = 0; i < s.size(); ++i) {
        if(isalpha(s[i])) {
            if(tmp.size()) {
                u[++n] = ID(tmp);
                tmp.clear();
            }
        }
        tmp += s[i];
    }
}

int two[2005] = {1};

string s, t;

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int T; cin >> T;
    int kase = 0;
    for(int i = 1; i <= 2000; ++i) two[i] = two[i - 1] * 2 % MOD;
    while(T--) {
        cin >> s >> t;
        cnt = 0; mp.clear();
        handle(n, s, u);
        handle(m, t, v);

        memset(dp, 0, sizeof dp);
        memset(b, 0, sizeof b);
        for(int i = 1; i <= n; ++i) {
            for(int j = 1; j <= m; ++j) {
                if(u[i] != v[j]) continue;
                add(dp[i][j], sum(i, j - 1) + sum(i - 1, j)
                    - sum(i - 1, j - 1) + 2);
                add(i, j, dp[i][j]);
            }
        }
        int ans = ((two[n] + two[m] - 2 - sum(n, m)) % MOD + MOD) % MOD;
        printf("Case %d: %d\n", ++kase, ans);
    }
    return 0;
}
