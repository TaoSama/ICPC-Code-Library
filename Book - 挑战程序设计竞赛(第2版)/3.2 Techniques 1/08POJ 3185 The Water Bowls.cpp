//
//  Created by TaoSama on 2016-07-29
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
const int N = 20 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n = 20, a[N];

int solve(int x) {
    int ret = x;
    bool flip[N] = {}; flip[2] = flip[1] = x;
    for(int i = 2; i <= n; ++i) {
//        for(int j = 1; j <= 5; ++j) printf("%d ", flip[j]); puts("");
        if(a[i - 1] ^ flip[i - 1]) {
//          prln(i);
            flip[i] ^= 1;
            flip[i + 1] ^= 1;
            ++ret;
        }
    }
    if(a[n] ^ flip[n]) ret = INF;
    return ret;
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);
    clock_t _ = clock();

    for(int i = 1; i <= n; ++i) scanf("%d", a + i);

//  prln(solve(0));
//  prln(solve(1));

    int ans = min(solve(0), solve(1));
    printf("%d\n", ans);


#ifdef LOCAL
    printf("\nTime cost: %.2fs\n", 1.0 * (clock() - _) / CLOCKS_PER_SEC);
#endif
    return 0;
}
