//
//  Created by TaoSama on 2015-11-28
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

typedef long long LL;

LL n;
LL a[65] = {0, 1}, b[65] = {0, 1}; //total: 54

LL dfs(LL n) {
    if(n <= 0) return 0;
    if(n == 1) return 1;
    int idx = upper_bound(a + 1, a + 55, n) - a - 1;
    return b[idx] + n - a[idx] + dfs(n - a[idx] - 1);
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int t; scanf("%d", &t);
    for(int i = 2; a[i - 1] <= 1e16; ++i) {
        a[i] = 2 * a[i - 1] + 1;
        b[i] = 2 * b[i - 1] + a[i - 1] + 1;
    }
    while(t--) {
        scanf("%I64d", &n);
        printf("%I64d\n", dfs(n));
    }
    return 0;
}
