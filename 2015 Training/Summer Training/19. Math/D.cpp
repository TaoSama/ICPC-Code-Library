//
//  Created by TaoSama on 2015-08-14
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

vector<int> prime;
void init() {
    bool vis[50005] = {};
    for(int i = 2; i <= 50000; ++i) {
        if(!vis[i]) {
            prime.push_back(i);
            for(int j = i + i; j <= 50000; j += i)
                vis[j] = 1;
        }
    }
}

long long n;

int e[50005];
void fact(long long x) {
    for(auto &p : prime) {
        while(x % p == 0) {
            x /= p;
            e[p] ++;
        }
        if(x == 1) break;
    }
}

typedef long long ll;
ll ksm(ll x, ll n) {
    ll ret = 1;
    while(n) {
        if(n & 1) ret *= x;
        x *= x;
        n >>= 1;
    }
    return ret;
}

int main() {
#ifdef LOCAL
//    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int kase = 0;
    init();
    while(cin >> n && n) {
        cout << "Case " << ++kase << ": ";

        ll cnt = 0, ans = 0, t = n;
        int m = sqrt(n);
        for(int i = 2; i <= m; ++i) {
            ll cur = 1;
            if(t % i == 0) {
                ++cnt;
                while(t % i == 0) {
                    t /= i;
                    cur *= i;
                }
                ans += cur;
            }
            if(t == 1) break;
        }
        if(t != 1) {ans += t; ++cnt;}
        if(t == n) ans = n + 1; //itself is prime
        else if(cnt == 1) ans++;
        cout << ans << '\n';
    }
    return 0;
}
