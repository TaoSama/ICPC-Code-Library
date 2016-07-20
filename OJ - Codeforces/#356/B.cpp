//
//  Created by TaoSama on 2016-06-09
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

int n, s;
int a[N];

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);
    clock_t _ = clock();

    scanf("%d%d", &n, &s);
    for(int i = 1; i <= n; ++i) scanf("%d", a + i);

    int ans = a[s];
    for(int i = s - 1, j = s + 1; ;) {
        i = max(i, 0);
        j = min(j, n + 1);
        if(i == 0 || j == n + 1) ans += a[i] + a[j];
        else if(a[i] + a[j] == 2) ans += 2;
        --i; ++j;
        if(i < 1 && j > n) break;
    }
    printf("%d\n", ans);

#ifdef LOCAL
    printf("\nTime cost: %.2fs\n", 1.0 * (clock() - _) / CLOCKS_PER_SEC);
#endif
    return 0;
}
