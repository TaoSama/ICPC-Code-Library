//
//  Created by TaoSama on 2016-07-24
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
const int N = 1e3 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, m, k;
map<int, int> f;

int getSg(int n) {
    if(f.count(n)) return f[n];
    set<int> s;
    vector<int> divisors;
    for(int i = 1; i * i <= n; ++i) {
        if(n % i == 0) {
            if(i >= k) divisors.push_back(i);
            if(i * i != n && n / i >= k) divisors.push_back(n / i);
        }
    }
    for(int d : divisors) {
        int times = n / d;
        if(times > 1) s.insert(getSg(d));
    }
    for(int i = 0; ; ++i) if(!s.count(i)) return f[n] = i;
    return -1;
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);
    clock_t _ = clock();

    while(scanf("%d%d%d", &n, &m, &k) == 3) {
        f.clear();
        int ans = 0;
        if(n & 1) ans = getSg(m);
        puts(ans ? "Timur" : "Marsel");
    }

#ifdef LOCAL
    printf("\nTime cost: %.2fs\n", 1.0 * (clock() - _) / CLOCKS_PER_SEC);
#endif
    return 0;
}
