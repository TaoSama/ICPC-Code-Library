//
//  Created by TaoSama on 2016-01-23
//  Copyright (c) 2015 TaoSama. All rights reserved.
//
#pragma comment(linker, "/STACK:1024000000,1024000000")
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

typedef unsigned long long ULL;
ULL t, a, b;

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%I64u%I64u%I64u", &t, &a, &b) == 3) {
        if(a > b) swap(a, b);
        ULL gcd = __gcd(a, b), lcm = t + 1;
        if((double)(a / gcd) * b <= t) lcm = a / gcd * b;
        ULL times = t / lcm;
        ULL up = min(a - 1, t);
        if(times) up = times * a - 1 + min(a - 1, t - times * lcm) + 1;
        gcd = __gcd(up, t);
        printf("%I64u/%I64u\n", up / gcd, t / gcd);
    }
    return 0;
}
