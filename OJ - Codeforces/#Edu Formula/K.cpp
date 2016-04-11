//
//  Created by TaoSama on 2016-02-23
//  Copyright (c) 2016 TaoSama. All rights reserved.
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

long long n;

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    scanf("%I64d", &n);
    vector<int> v;
    for(int i = 2; i <= 10; ++i) v.push_back(i);
    long long ans = n;
    for(int i = 1; i < 1 << 9; ++i) {
        int cnt = 0, lcm = 1;
        for(int j = 0; j < 9; ++j)
            if(i >> j & 1) lcm = lcm / __gcd(lcm, v[j]) * v[j], ++cnt;
        if(cnt & 1) ans -= n / lcm;
        else ans += n / lcm;
    }
    printf("%I64d\n", ans);
    return 0;
}
