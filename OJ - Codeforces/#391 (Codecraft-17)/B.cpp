//
//  Created by TaoSama on 2017-01-12
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

using namespace std;
#define pr(x) cout << #x << " = " << x << "  "
#define prln(x) cout << #x << " = " << x << endl
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, f[N];

vector<int> factorize(int x) {
    vector<int> ret;
    for(int i = 2; i * i <= x; ++i) {
        if(x % i == 0) {
            ret.push_back(i);
            while(x % i == 0) x /= i;
        }
    }
    if(x > 1) ret.push_back(x);
    return ret;
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d", &n) == 1) {
        memset(f, 0, sizeof f);
        for(int i = 1; i <= n; ++i) {
            int x; scanf("%d", &x);
            vector<int> factor = factorize(x);
//          for(int fac : factor) cout << fac << ' '; cout << endl;
            int cur = 0;
            for(int fac : factor) ++f[fac];
        }
//        for(int i = 1; i <= 10; ++i) printf("f[%d] = %d\n", i, f[i]);
        int ans = *max_element(f, f + N);
        ans = max(ans, 1);
        printf("%d\n", ans);
    }

    return 0;
}
