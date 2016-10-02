//
//  Created by TaoSama on 2016-10-01
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
LL a[N], s[N];

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d", &n) == 1) {
        for(int i = 1; i <= n; ++i) {
            scanf("%I64d", a + i);
            s[i] = s[i - 1] + a[i];
        }

        set<pair<int, int> > seg;
        multiset<LL> maxv;
        seg.insert({1, n});
        maxv.insert(s[n]);
        for(int i = 1; i <= n; ++i) {
            int x; scanf("%d", &x);
            auto iter = seg.upper_bound({x, INF});
            if(iter != seg.begin()) --iter;
            int l, r; tie(l, r) = *iter;
            seg.erase(iter);
            LL sum = s[r] - s[l - 1];
            maxv.erase(maxv.find(sum));
            if(l <= x - 1) {
                seg.insert({l, x - 1});
                maxv.insert(s[x - 1] - s[l - 1]);
            }
            if(x + 1 <= r) {
                seg.insert({x + 1, r});
                maxv.insert(s[r] - s[x]);
            }
            if(maxv.size()) printf("%I64d\n", *maxv.rbegin());
            else puts("0");
        }
    }

    return 0;
}
