//
//  Created by TaoSama on 2017-01-08
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

int n, w[N];

int main() {
#ifdef LOCAL
    freopen("lazy_loading.txt", "r", stdin);
    freopen("lazy_loading_out.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);

    int t; scanf("%d", &t);
    while(t--) {
        scanf("%d", &n);
        for(int i = 1; i <= n; ++i) scanf("%d", w + i);
        sort(w + 1, w + 1 + n);
        int s = 1, t = n, ans = 0;
        while(s <= t) {
            int need = (50 + w[t] - 1) / w[t];
            s += need - 1;
            t -= 1;
            if(s <= t + 1) ++ans;
            else break;
        }
        static int kase = 0;
        printf("Case #%d: %d\n", ++kase, ans);
    }

    return 0;
}
