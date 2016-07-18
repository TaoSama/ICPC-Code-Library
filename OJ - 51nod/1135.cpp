//
//  Created by TaoSama on 2016-07-08
//  Copyright (c) 2016 TaoSama. All rights reserved.
//
#pragma comment(linker, "/STACK:102400000,102400000")
#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <set>
#include <vector>
#include <bitset>

using namespace std;
#define pr(x) cout << #x << " = " << x << "  "
#define prln(x) cout << #x << " = " << x << endl
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

const int C = 1e5 + 10;

bitset<C> notPrime;
vector<int> prime;
void gao() {
    notPrime[1] = 1;
    for(int i = 2; i < C; ++i) {
        if(!notPrime[i]) prime.push_back(i);
        for(int j = 0; j < prime.size() && i * prime[j] < C; ++j) {
            notPrime[i * prime[j]] = 1;
            if(i % prime[j] == 0) break;
        }
    }
}

typedef long long LL;
LL quick(LL x, LL n, LL m) {
    LL ret = 1;
    for(; n; n >>= 1) {
        if(n & 1) ret = ret * x % m;
        x = x * x % m;
    }
    return ret;
}

int phi(int x) {
    int ret = x;
    for(int i = 0; i < prime.size() && prime[i] * prime[i] <= x; ++i) {
        if(x % prime[i]) continue;
        ret = ret / prime[i] * (prime[i] - 1);
        while(x % prime[i] == 0) x /= prime[i];
    }
    if(x > 1) ret = ret / x * (x - 1);
    return ret;
}

vector<int> factorize(int x) {
    vector<int> ret;
    for(int i = 0; i < prime.size() && prime[i] * prime[i] <= x; ++i) {
        if(x % prime[i]) continue;
        ret.push_back(prime[i]);
        while(x % prime[i] == 0) x /= prime[i];
    }
    if(x > 1) ret.push_back(x);
    return ret;
}

vector<int> getDivisors(int x) {
    vector<int> ret;
    for(int i = 1; i * i <= x; ++i) {
        if(x % i) continue;
        ret.push_back(i);
        if(i * i != x) ret.push_back(x / i);
    }
    return ret;
}

int root(int x) {
    vector<int> factors = factorize(x - 1);
    for(int g = 1; g < x; ++g) {
        bool ok = true;
        for(int j = 0; j < factors.size(); ++j) {
            int e = (x - 1) / factors[j];
            if(quick(g, e, x) == 1) {
                ok = false;
                break;
            }
        }
        if(ok) return g;
    }
    return -1;
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);
    clock_t _ = clock();

    int p; scanf("%d", &p);
    gao();
    printf("%d\n", root(p));

#ifdef LOCAL
    printf("\nTime cost: %.2fs\n", 1.0 * (clock() - _) / CLOCKS_PER_SEC);
#endif
    return 0;
}
