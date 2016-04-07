//
//  Created by TaoSama on 2016-04-02
//  Copyright (c) 2016 TaoSama. All rights reserved.
//
#pragma comment(linker, "/STACK:102400000,102400000")
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

int n, m[20], r[20];

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    scanf("%d", &n);
    int lcm = 1;
    for(int i = 1; i <= n; ++i) {
        scanf("%d", m + i);
        lcm = lcm / __gcd(lcm, m[i]) * m[i];
    }
    for(int i = 1; i <= n; ++i) scanf("%d", r + i);
    set<int> s;
    for(int i = 0; i < lcm; ++i)
        for(int j = 1; j <= n; ++j)
            if(i % m[j] == r[j]) s.insert(i);

    double ans = 1.0 * s.size() / lcm;
    printf("%.12f\n", ans);
    return 0;
}
