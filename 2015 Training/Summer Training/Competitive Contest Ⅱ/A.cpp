//
//  Created by TaoSama on 2015-08-23
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
const int N = 5e4 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

long long a, b;

vector<int> prime;
void gao() {
    bool vis[N] = {};
    for(int i = 2; i <= 5e4; ++i) {
        if(!vis[i]) {
            prime.push_back(i);
            for(int j = i + i; j <= 5e4; j += i)
                vis[j] = true;
        }
    }
}

long long fact(int x) {
    long long ret = 1;
    int t = x;
    for(int i = 0; i < prime.size() && prime[i] <= x; ++i) {
        int p = prime[i];
        int cnt = 0;
        while(t % p == 0) {
            ++cnt;
            t /= p;
        }
        ret *= (cnt + 1);
        if(t == 1) break;
    }
    if(t > 1) ret *= 2;
    return ret;
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int t; scanf("%d", &t);
    gao();
    while(t--) {
        scanf("%lld%lld", &a, &b);
        long long ans, Max = -INF;
        for(int i = a; i <= b; ++i) {
            long long cur = fact(i);
            if(cur > Max) {
                ans = i;
                Max = cur;
            }
        }
        printf("Between %lld and %lld, %lld has a maximum of %lld divisors.\n",
               a, b, ans, Max);
    }
    return 0;
}
