//
//  Created by TaoSama on 2017-03-23
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
#define pr(x) cerr << #x << " = " << x << "  "
#define prln(x) cerr << #x << " = " << x << endl
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, a[N];
vector<int> qs[N];

struct BIT {
    int n, b[N];
    void init(int _n) {
        n = _n;
        memset(b, 0, sizeof b);
    }
    void add(int i, int v) {
        for(; i <= n; i += i & -i) b[i] += v;
    }
    int findkth(int k) {
        int ret = 0;
//        for(int i = 1; i <= n; ++i) printf("b[%d] = %d\n", i, b[i]);
        for(int i = 16; ~i; --i) {
            int x = 1 << i;
            if(ret + x <= n && b[ret + x] <= k) {
                ret += x;
                k -= b[ret];
            }
        }
        return ret;
    }
} bit;

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d", &n) == 1) {
        for(int i = 1; i <= n; ++i) scanf("%d", a + i);

        vector<int> nxt(n + 1, -1), lst(n + 1, -1);
        for(int i = n; i; --i) {
            nxt[i] = lst[a[i]];
            lst[a[i]] = i;
        }

        for(int i = 1; i <= n; ++i) qs[i].clear();
        //add k
        for(int i = 1; i <= n; ++i) qs[1].push_back(i);

        bit.init(n);
        for(int i = 1; i <= n; ++i) {
            if(~lst[i]) {
                bit.add(lst[i], 1);
//                printf("add %d\n", i);
            }
        }

        vector<int> ans(n + 1, 0);
        for(int i = 1; i <= n; ++i) {
            for(int k : qs[i]) {
                ++ans[k];
                int wh = bit.findkth(k);
                if(wh + 1 <= n) qs[wh + 1].push_back(k);
            }
            bit.add(i, -1);
            if(~nxt[i]) bit.add(nxt[i], 1);
        }

        for(int i = 1; i <= n; ++i) printf("%d%c", ans[i], " \n"[i == n]);
    }

    return 0;
}
