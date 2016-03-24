//
//  Created by TaoSama on 2015-05-10
//  Copyright (c) 2015 TaoSama. All rights reserved.
//
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
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int N = 1e5 + 10;

long long a, b;
int cta[70], ctb[70];

long long calc(int *ct, int n) {
    for(int i = 0; i < 63; ++i) ct[i] = 0;
    int x = 1;
    ++n;
    for(int i = 0; i < 63; ++i) {
        if(x > n) break;
        x <<= 1;
        ct[i] = (n - n % x) >> 1;
        if(n % x > x / 2) ct[i] += n % x - x / 2;
    }
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%I64d%I64d", &a, &b) == 2) {
        calc(cta, a - 1);
        calc(ctb, b);
        for(int i = 0; i < 63; ++i) ctb[i] -= cta[i];
        long long ans = 0;
        for(int i = 0; i < 63; ++i) {
            ans += ctb[i] >> 1;
            ctb[i + 1] += ctb[i] >> 1;
        }
        printf("%I64d\n", ans);
    }
    return 0;
}
