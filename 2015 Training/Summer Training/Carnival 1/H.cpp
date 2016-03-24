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

char s[1005], ans[1005];
int n, c[26];

int cnt, prime[500], vis[1005];
int par[1005], rk[1005];

void init() {
    memset(vis, 1, sizeof vis);
    cnt = 0;
    for(int i = 2; i <= 1000; ++i) {
        if(vis[i]) {
            prime[++cnt] = i;
            for(int j = i + i; j <= 1000; j += i)
                vis[j] = 0;
        }
    }
    for(int i = 1; i <= 1000; ++i) {
        par[i] = i;
        rk[i] = 0;
    }
}

int __lcm(int a, int b) {
    return a * b / __gcd(a, b);
}

int find(int x) {
    return par[x] = par[x] == x ? x : find(par[x]);
}

void unite(int x, int y) {
    x = find(x), y = find(y);
    if(x == y) return;
    if(rk[x] < rk[y]) par[x] = y;
    else {
        par[y] = x;
        if(rk[x] == rk[y]) ++rk[x];
    }
}

map<int, vector<int> > mp;

//function name fixed (spelling mistake provided by Juan)
bool canConstruct() {
    memset(ans, 0, sizeof ans);
    for(auto &i : mp) {
        int maxid = max_element(c, c + 26) - c;
//        cout << char('a' + maxid) << endl;
        vector<int>& v = i.second;
        for(int k = 0; k < v.size(); ++k) {
            int &cur = v[k];
            for(int p = cur; p <= n; p += cur) {
                if(ans[p]) continue;
                ans[p] = maxid + 'a';
                if(--c[maxid] < 0) return false;
            }
        }
    }
    int maxid = max_element(c, c + 26) - c;
    ans[1] = maxid + 'a';
    return true;
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    init();
    while(cin >> (s + 1)) {
        n = strlen(s + 1);
        memset(c, 0, sizeof c);
        for(int i = 1; i <= n; ++i) ++c[s[i] - 'a'];

        for(int i = 1; i <= cnt; ++i) {
            for(int j = i + 1; j <= cnt; ++j) {
                if(__lcm(prime[i], prime[j]) <= n)
                    unite(prime[i], prime[j]);
            }
        }

        mp.clear();
        for(int i = 1; i <= cnt && prime[i] <= n; ++i) {
            int x = find(prime[i]);
            mp[x].push_back(prime[i]);
        }

//        for(auto &i : mp) {
//            cout << i.first << ' ' << i.second.size() << endl;
//        }

        if(canConstruct()) {
            cout << "YES\n";
//            for(int i = 1; i <= n; ++i) cout << ans[i]; cout << endl;
            cout << (ans + 1) << '\n';
        } else cout << "NO\n";
    }
    return 0;
}
