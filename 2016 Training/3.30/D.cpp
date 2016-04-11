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
const int N = 1e7, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int d[N];

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int x, y;
    while(scanf("%d%d", &x, &y) == 2) {
        int ans = 0;
        for(int i = 1; i <= y; ++i)
            ans += y / i - (x - 1) / i;
        printf("%d\n", ans);
    }
    return 0;
}
