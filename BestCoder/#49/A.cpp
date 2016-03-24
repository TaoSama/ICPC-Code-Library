//
//  Created by TaoSama on 2015-08-01
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

int n, A, a[25];

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int t; scanf("%d", &t);
    while(t--) {
        scanf("%d%d", &n, &A);
        for(int i = 0; i < n; ++i) scanf("%d", a + i);

        sort(a, a + n, greater<int>());

        int ans = INF;
        for(int i = 0; i < 1 << n; ++i) {
            int t = A;
            for(int j = 0; j < n; ++j)
                if(i & (1 << j)) t %= a[j];
            if(!t) ans = min(ans, __builtin_popcount(i));
        }

        if(ans == INF) ans = -1;
        printf("%d\n", ans);
    }
    return 0;
}
