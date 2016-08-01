//
//  Created by TaoSama on 2016-07-29
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
const int N = 1e7 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

typedef long long LL;
LL n;

inline LL sq(LL x) {return x * x;}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);
    clock_t _ = clock();

    while(scanf("%lld", &n) == 1) {
        LL sum = 0;
        vector<pair<LL, LL> > ans;
        int to = sqrt(n) + 10;
        for(int l = 1, r = 1; l <= to; ++l) {
            while(r <= N && sum < n) sum += sq(r++);
            if(sum == n) ans.push_back(make_pair(l, r));
            sum -= sq(l);
        }
        printf("%d\n", ans.size());
        for(int i = 0; i < ans.size(); ++i) {
            printf("%lld", ans[i].second - ans[i].first);
            for(LL j = ans[i].first; j < ans[i].second; ++j)
                printf(" %lld", j);
            puts("");
        }
    }

#ifdef LOCAL
    printf("\nTime cost: %.2fs\n", 1.0 * (clock() - _) / CLOCKS_PER_SEC);
#endif
    return 0;
}
