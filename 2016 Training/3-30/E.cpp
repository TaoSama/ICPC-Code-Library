//
//  Created by TaoSama on 2016-03-30
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

int n, k, a[N];

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d%d", &n, &k) == 2) {
        for(int i = 1; i <= n; ++i) scanf("%d", a + i);
        if(n == 1) {puts("0 0"); continue;}

        int inversions = 0, equals = 0;
        for(int i = 1; i <= n; ++i)
            for(int j = 1; j < i; ++j)
                inversions += a[j] > a[i], equals += a[j] == a[i];

        int tot = n * (n - 1) / 2 - equals;
        int minv = inversions - k;
        if(minv < 0) {
            minv = abs(minv) & 1;
            if(equals) minv = 0;
        }
        int maxv = inversions + k;
        if(maxv > tot) {
            maxv = tot - (maxv - tot & 1);
            if(equals) maxv = tot;
        }

        printf("%d %d\n", minv, maxv);
    }
    return 0;
}
