//
//  Created by TaoSama on 2016-02-11
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
const int N = 1e6 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, a[N];

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d", &n) == 1) {
        int i, j;
        if(n & 1) {
            for(i = 1, j = 1; j < n; ++i, j += 2)
                a[i] = a[i + n - j] = j;
            a[i] = a[i + n / 2 + 1] = n;
            for(i = n + 2, j = 2; j < n; ++i, j += 2)
                a[i] = a[i + n - j] = j;
        } else {
            for(i = 1, j = 2; j < n; ++i, j += 2)
                a[i] = a[i + n - j] = j;
            a[i] = a[i + n / 2] = n;
            for(i = n + 1, j = 1; j < n; ++i, j += 2)
                a[i] = a[i + n - j] = j;
        }
        for(int i = 1; i <= n << 1; ++i)
            printf("%d%c", a[i], " \n"[i == (n << 1)]);
    }
    return 0;
}
