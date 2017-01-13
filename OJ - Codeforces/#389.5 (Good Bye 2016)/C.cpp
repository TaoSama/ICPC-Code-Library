//
//  Created by TaoSama on 2016-12-30
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
const int N = 2e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n;

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d", &n) == 1) {
        int l = -INF, r = INF;
        for(int i = 1; i <= n; ++i) {
            int c, d; scanf("%d%d", &c, &d);
            if(d == 1) l = max(l, 1900);
            else r = min(r, 1899);
            l += c;
            r += c;
        }
        if(l > r) puts("Impossible");
        else if(r > 1e8) puts("Infinity");
        else printf("%d\n", r);
    }

    return 0;
}
