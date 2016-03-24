//
//  Created by TaoSama on 2015-12-01
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

const int s[] = {0, 500, 1000, 1500, 2000, 2500};

int m[10];
double f(int i, int x) {
    return max(0.3 * s[i], (1 - 1.0 * m[i] / 250) * s[i] - 50 * x);
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    for(int i = 1; i <= 5; ++i) scanf("%d", m + i);
    double ans = 0;
    for(int i = 1; i <= 5; ++i) {
        int x; scanf("%d", &x);
        ans += f(i, x);
    }
    int a, b; scanf("%d%d", &a, &b);
    ans += 100 * a - 50 * b;
    printf("%.0f\n", ans);

    return 0;
}
