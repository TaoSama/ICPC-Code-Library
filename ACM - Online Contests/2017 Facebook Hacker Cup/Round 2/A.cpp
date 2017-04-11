//
//  Created by TaoSama on 2017-01-22
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
    freopen("subtle_sabotage.txt", "r", stdin);
    freopen("subtle_sabotage_out.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);

    int t; scanf("%d", &t);
    while(t--) {
        int n, m, k; scanf("%d%d%d", &n, &m, &k);
        if(m > n) swap(n, m);
        int ans = -1;

        if(n >= 2 * k + 3 && m >= k + 1) {
            ans = (m + k - 1) / k;  //堵
            if(m >= 2 * k + 1) ans = min(ans, k == 1 ? 5 : 4); //围
        }

        static int kase = 0;
        printf("Case #%d: %d\n", ++kase, ans);
    }

    return 0;
}
