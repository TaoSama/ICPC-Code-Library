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
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n;
typedef long long LL;
LL a[40];

LL ABS(const LL& x) {
    if(x < 0) return -x;
    return x;
}

void checkAns(pair<LL, LL>& ans, pair<LL, LL> rhs, LL sum, LL cnt) {
    LL lftSum = rhs.first, lftCnt = rhs.second;
    ans = min(ans, make_pair(ABS(sum + lftSum), cnt + lftCnt));
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);
    clock_t _ = clock();

    while(scanf("%d", &n) == 1 && n) {
        for(int i = 0; i < n; ++i) scanf("%lld", a + i);

        pair<LL, LL> ans((LL)1e18, (LL)1e18);

        int half = n >> 1, lft = n - half;
        vector<pair<LL, LL> > v;
        for(int i = 1; i < 1 << half; ++i) {
            LL sum = 0, cnt = 0;
            for(int j = 0; j < half; ++j) {
                if(i >> j & 1) {
                    ++cnt;
                    sum += a[j];
                }
            }
            v.push_back(make_pair(sum, cnt));
            checkAns(ans, make_pair(0, 0), sum, cnt);
        }
        sort(v.begin(), v.end());

        for(int i = 1; i < 1 << lft; ++i) {
            LL sum = 0, cnt = 0;
            for(int j = 0; j < lft; ++j) {
                if(i >> j & 1) {
                    ++cnt;
                    sum += a[half + j];
                }
            }
            checkAns(ans, make_pair(0, 0), sum, cnt);

            int x = lower_bound(v.begin(), v.end(), make_pair(-sum,
                                (LL) - INF)) - v.begin();
            if(x != v.size()) checkAns(ans, v[x], sum, cnt);

            if(x) {
                --x;
                x = lower_bound(v.begin(), v.end(), make_pair(v[x].first,
                                (LL) - INF)) - v.begin();
                checkAns(ans, v[x], sum, cnt);
            }
        }
        printf("%lld %lld\n", ans.first, ans.second);
    }

#ifdef LOCAL
    printf("\nTime cost: %.2fs\n", 1.0 * (clock() - _) / CLOCKS_PER_SEC);
#endif
    return 0;
}
