//
//  Created by TaoSama on 2015-10-24
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
const double EPS = 1e-8;

typedef long long LL;

LL n;

vector<int> p;
void gao() {
    for(int i = 2; i <= 60; ++i) {
        bool isPrime = true;
        for(int j = 2; j * j <= i; ++j) {
            if(i % j == 0) {
                isPrime = false;
                break;
            }
        }
        if(isPrime) p.push_back(i);
    }
}

LL calc() {
    LL ret = 0;
    int sz = p.size();
    for(int s = 1; s < 1 << sz; ++s) {
        LL cnt = 0, mul = 1;
        for(int i = 0; i < sz; ++i) {
            if(s >> i & 1) {
                ++cnt;
                mul *= p[i];
                if(mul >= 60) break;
            }
        }
        if(mul >= 60) continue;
        LL tmp = (LL)(pow(1.0 * n, 1.0 / mul) + EPS) - 1;
        if(cnt & 1) ret += tmp;
        else ret -= tmp;
    }
    return ret + 1;
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    gao();
    while(scanf("%I64d", &n) == 1) {
        printf("%I64d\n", calc());
    }
    return 0;
}
