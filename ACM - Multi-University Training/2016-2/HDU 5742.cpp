//
//  Created by TaoSama on 2016-07-22
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

int n, m;
int a[N];

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);
    clock_t _ = clock();

    int t; scanf("%d", &t);
    while(t--) {
        scanf("%d%d", &n, &m);
        memset(a, -1, sizeof a);
        for(int i = 1; i <= m; ++i) {
            int x, y; scanf("%d%d", &x, &y);
            a[x] = y;
        }
        if(a[1] == -1) a[1] = 100;
        if(a[2] == -1) a[2] = min(a[1], 100);

        int up = a[1] + a[2], dw = up;

        int last = 2;
        for(int i = 3; i <= n; ++i) {
            if(~a[i]) {
                dw += (i - last) * a[i];
                last = i;
            }
        }

        int g = __gcd(up, dw);
        up /= g; dw /= g;
        printf("%d/%d\n", up, dw);
    }

#ifdef LOCAL
    printf("\nTime cost: %.2fs\n", 1.0 * (clock() - _) / CLOCKS_PER_SEC);
#endif
    return 0;
}