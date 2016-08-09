//
//  Created by TaoSama on 2016-08-02
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
const int N = 5e4 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, a[N];
typedef long long LL;

struct BIT {
    int b[N], cnt[N];
    int n, timStp;
    void init(int _n) {
        n = _n;
        memset(cnt, 0, sizeof cnt);
    }
    void newOne() {
        ++timStp;
    }
    void add(int i, int v) {
        for(; i <= n; i += i & -i) {
            if(cnt[i] != timStp) cnt[i] = timStp, b[i] = 0;
            b[i] += v;
        }
    }
    int sum(int i) {
        int ret = 0;
        for(; i; i -= i & -i) if(cnt[i] == timStp) ret += b[i];
        return ret;
    }
} bit, bit2;

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d", &n) == 1) {
        vector<int> xs;
        for(int i = 1; i <= n; ++i) {
            scanf("%d", a + i);
            xs.push_back(a[i]);
        }

        sort(xs.begin(), xs.end());
        xs.resize(unique(xs.begin(), xs.end()) - xs.begin());
        for(int i = 1; i <= n; ++i)
            a[i] = lower_bound(xs.begin(), xs.end(), a[i]) - xs.begin() + 1;

        bit.init(xs.size());
        bit2.init(xs.size());

        LL lft = 0;
        bit.newOne();
        for(int i = 1; i <= n; ++i) {
            lft += bit.sum(a[i] - 1);
            bit.add(a[i], 1);
        }

        LL rgt = 0;
        bit2.newOne();
        for(int i = n; i; --i) {
            rgt += bit2.sum(a[i] - 1);
            bit2.add(a[i], 1);
        }

        LL sum = lft * rgt;
//        prln(sum);

        LL no = 0;
        bit.newOne();
        for(int i = 1; i <= n; ++i) {
            bit2.add(a[i], -1);

            LL t1 = bit.sum(a[i] - 1) + bit2.sum(xs.size()) - bit2.sum(a[i]);
            LL t2 = bit2.sum(a[i] - 1) + bit.sum(xs.size()) - bit.sum(a[i]);
//            pr(i); pr(t1); prln(t2);
            no += t1 * t2;

            bit.add(a[i], 1);
        }


        printf("%I64d\n", sum - no);
    }

    return 0;
}
