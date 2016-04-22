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

int n, m, a[15];

typedef long long LL;

LL calc() {
    LL ret = 0;
    vector<int> factor;
    for(int i = 0; i < n; ++i) if(a[i]) factor.push_back(a[i]);
    n = factor.size();
    for(int s = 1; s < 1 << n; ++s) {
        int cnt = 0, mul = 1;
        for(int i = 0; i < n; ++i)
            if(s >> i & 1) ++cnt, mul = mul / __gcd(mul, a[i]) * a[i];
        if(cnt & 1) ret += m / mul;
        else ret -= m / mul;
    }
    return ret;
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d%d", &m, &n) == 2) {
        --m;
        for(int i = 0; i < n; ++i) scanf("%d", a + i);
        printf("%I64d\n", calc());
    }
    return 0;
}
