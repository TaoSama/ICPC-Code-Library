//
//  Created by TaoSama on 2016-05-06
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

int n;

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);
    clock_t _ = clock();

    while(scanf("%d", &n) == 1) {
        pair<int, int> ans = {0, 0}; //length start
        int sum = 1;
        for(int l = 2, r = 2; 1LL * l * l <= n; ++l) {
            while(1LL * sum * r <= n) {
                if(n % sum == 0) ans = max(ans, {r - l, -l});
                sum *= r++;
            }
            if(n % sum == 0) ans = max(ans, {r - l, -l});
            sum /= l;
        }
        if(!ans.first) {
            printf("%d\n%d\n", 1, n);
            continue;
        }
        printf("%d\n", ans.first);
        for(int i = -ans.second; ans.first--; ++i)
            printf("%d%c", i, "*\n"[!ans.first]);
    }

#ifdef LOCAL
    printf("Time cost: %.2fs\n", 1.0 * (clock() - _) / CLOCKS_PER_SEC);
#endif
    return 0;
}
