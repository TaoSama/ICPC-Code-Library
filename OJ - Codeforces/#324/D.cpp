//
//  Created by TaoSama on 2015-10-07
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
const int N = 1e7 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

typedef long long LL;

LL n;

LL mod_exp(LL a, LL b, LL mod) {
    LL ret = 1;
    while(b) {
        if(b & 1) ret = ret * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return ret;
}

bool check(LL a, LL n) {
    LL x = n - 1, y;
    int t = 0;
    while((x & 1) == 0) {
        x >>= 1;
        t++;
    }
    x = mod_exp(a, x, n);

    for(int i = 1; i <= t; i++) {
        y = x * x % n;
        if(y == 1 && x != 1 && x != n - 1) return true;
        x = y;
    }
    if(y != 1) return true;
    return false;
}

bool Miller_Rabin(LL n, int times = 20) {
    if(n == 2) return true;
    if(n == 1 || !(n & 1)) return false;

    for(int i = 1; i <= times; i++) {
        LL a = rand() % (n - 1) + 1;
        if(check(a, n)) return false;
    }
    return true;
}

int maxd, ans[5];

bool dfs(int lef, int k) {
    if(k == maxd + 1) return lef == 0;
    for(int i = lef; i >= 2; --i) {
        if(i == 2 || (i & 1) && Miller_Rabin(i)) {
            ans[k] = i;
            if(dfs(lef - i, k + 1)) return true;
        }
    }
    return false;
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(cin >> n) {
        for(maxd = 3; maxd; --maxd) {
            if(dfs(n, 1)) {
                cout << maxd << endl;
                for(int i = 1; i <= maxd; ++i)
                    cout << ans[i] << ' ';
                cout << '\n';
                break;
            }
        }
    }
    return 0;
}
