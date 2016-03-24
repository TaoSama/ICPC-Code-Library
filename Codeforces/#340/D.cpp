//
//  Created by TaoSama on 2016-01-24
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

int x[4], y[4];

bool isBetween(int a, int b, int c) {
    return min(b, c) <= a && a <= max(b, c);
}

bool f(int k, int i, int j) {
    return (x[k] == x[i] || x[k] == x[j]) && isBetween(y[k], y[i], y[j]) ||
           (y[k] == y[i] || y[k] == y[j]) && isBetween(x[k], x[i], x[j]);
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    for(int i = 1; i <= 3; ++i) scanf("%d%d", x + i, y + i);
    int ans = -1;
    if(x[1] == x[2] && x[2] == x[3] || y[1] == y[2] && y[2] == y[3]) ans = 1;
    else if(f(1, 2, 3) || f(2, 1, 3) || f(3, 1, 2)) ans = 2;
    else ans = 3;
    printf("%d\n", ans);
    return 0;
}
