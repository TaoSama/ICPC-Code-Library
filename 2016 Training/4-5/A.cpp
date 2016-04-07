//
//  Created by TaoSama on 2016-04-05
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

int n, f[100]; //12

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    f[1] = 1;
    for(int i = 2; ; ++i) {
        f[i] = 3 * f[i - 1] + 1;
        if(f[i] > N) break;
    }
    while(scanf("%d", &n) == 1) {
        int ans = lower_bound(f + 1, f + 13, n) - f;
        printf("%d\n", ans);
    }
    return 0;
}
