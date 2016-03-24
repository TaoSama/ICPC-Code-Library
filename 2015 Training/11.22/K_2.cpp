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

int n, m, c, a[N];
int b[N], dp[N];

int cnt = 0;
map<string, int> mp;

int ID(string &s) {
    if(mp.count(s)) return mp[s];
    mp[s] = ++cnt;
    return -1;
}

void add(int &x, int y) {
    x += y;
    if(x < 0) x += MOD;
    else if(x >= MOD) x -= MOD;
}

void update(int i, int v) {
    for(; i <= cnt; i += i & -i) add(b[i], v);
}

int sum(int i) {
    int ret = 0;
    for(; i; i -= i & -i) add(ret, b[i]);
    return ret;
}

void handle(int &n, string &s, bool flag) {
    n = c = 0; s += 'A';
    string tmp; tmp += s[0];
    for(int i = 1; i < s.size(); ++i) {
        if(isalpha(s[i])) {
            ++n;
            int id = ID(tmp);
            if(flag && ~id) a[++c] = id;
            tmp.clear();
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
//  ios_base::sync_with_stdio(0);

    int T; cin >> T;
    int kase = 0;
    for(int i = 1; i <= 2000; ++i) two[i] = two[i - 1] * 2 % MOD;
    while(T--) {
        cin >> s >> t;
        cnt = 0; mp.clear();
        handle(n, s, false);
        handle(m, t, true);

        memset(dp, 0, sizeof dp);
        memset(b, 0, sizeof b);
        for(int i = 1; i <= c; ++i) {
            dp[i] = sum(a[i]) + 1;
            update(a[i], dp[i]);
        }
        int ans = ((two[n] + two[m] - 2 - 2 * sum(cnt)) % MOD + MOD) % MOD;
        printf("Case %d: %d\n", ++kase, ans);
    }
    return 0;
}
