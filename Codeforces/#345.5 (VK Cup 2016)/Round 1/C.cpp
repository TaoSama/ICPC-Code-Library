//
//  Created by TaoSama on 2016-03-29
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

int n, d, h;

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d%d%d", &n, &d, &h) == 3) {
        if(d > h * 2 || d == 1 && n > 2) {
            puts("-1");
            continue;
        }
        if(d == h) {
            for(int i = 2; i <= h + 1; ++i)
                printf("%d %d\n", i - 1, i);
            for(int i = h + 2; i <= n; ++i)
                printf("%d %d\n", 2, i);
        } else {
            for(int i = 2; i <= h + 1; ++i)
                printf("%d %d\n", i - 1, i);
            printf("%d %d\n", 1, h + 2);
            int idx = h + 2;
            for(int i = 1; i <= d - h - 1; ++i, ++idx)
                printf("%d %d\n", idx, idx + 1);
            for(int i = 1; i <= n - 1 - d; ++i, ++idx)
                printf("%d %d\n", 1, idx + 1);
        }
    }
    return 0;
}
