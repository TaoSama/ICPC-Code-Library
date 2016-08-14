//
//  Created by TaoSama on 2016-08-11
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



int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int t; scanf("%d", &t);
    while(t--) {
        int n, C; scanf("%d%d", &n, &C);
        vector<int> v;
        for(int i = 1; i <= n; ++i) {
            int x, y, z; scanf("%d%d%d", &x, &y, &z);
            v.push_back(x);
        }
        sort(v.begin(), v.end());
        int q; scanf("%d", &q);
        while(q--) {
            int T, k; scanf("%d%d", &T, &k); --k;
            double ans = v[k];
            ans = sqrt(ans * ans + 2.0 * C * T);
            printf("%.3f\n", ans);
        }
    }

    return 0;
}
