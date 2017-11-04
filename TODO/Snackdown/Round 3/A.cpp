//
//  Created by TaoSama on 2017-06-03
//  Copyright (c) 2017 TaoSama. All rights reserved.
//
#pragma comment(linker, "/STACK:102400000,102400000")
#include <bits/stdc++.h>

using namespace std;
#define pr(x) cerr << #x << " = " << x << "  "
#define prln(x) cerr << #x << " = " << x << endl
const int N = 2e6 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, k, a[N];
typedef long long LL;
inline void addMod(int& x, int y) {
    if((x += y) >= MOD) x -= MOD;
}
struct BIT {
    int n, b[N];
    void init(int _n) {
        n = _n;
        memset(b, 0, sizeof b);
    }
    void add(int i, int x) {
        for(; i <= n; i += i & -i) addMod(b[i], x);
    }
    int sum(int i) {
        int ret = 0;
        for(; i; i -= i & -i) addMod(ret, b[i]);
        return ret;
    }
    int sum(int l, int r) {
        int ret = 0;
        addMod(ret, sum(r));
        addMod(ret, MOD - sum(l - 1));
        return ret;
    }
} bit, mex;

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d%d", &n, &k) == 2) {
        vector<int> vs; vs.push_back(0);
        for(int i = 1; i <= n; ++i) {
            scanf("%d", a + i);
            vs.push_back(a[i]);
            vs.push_back(a[i] + 1);
        }
        vs.push_back(k);
        sort(vs.begin(), vs.end());
        vs.resize(unique(vs.begin(), vs.end()) - vs.begin());
        for(int i = 1; i <= n; ++i)
            a[i] = lower_bound(vs.begin(), vs.end(), a[i]) - vs.begin() + 1;

        k = lower_bound(vs.begin(), vs.end(), k) - vs.begin() + 1;

        bit.init(n + 1);
        mex.init(vs.size());
        bit.add(1, 1);
        int l = 2;
        vector<int> cnt(vs.size() + 1, 0);
        for(int i = 2; i <= n + 1; ++i) {
            int x = a[i - 1];
            if(!cnt[x]++) mex.add(x, 1);
            while(mex.sum(k) == k) {
                if(!--cnt[a[l - 1]]) mex.add(a[l - 1], -1);
                ++l;
            }
            bit.add(i, bit.sum(l - 1, i));
//          printf("(%d, %d) %d = %d\n", l - 1, i - 1, i - 1, bit.sum(i, i));
        }
        printf("%d\n", bit.sum(n + 1, n + 1));
    }

    return 0;
}
