//
//  Created by TaoSama on 2015-06-21
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
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int N = 1e5 + 10;
const int B = 600; //sqrt(n) 400 sqrt(nlogn)都T了 sqrt(nlogn)/2是个不错的数字

int n, q, a[N], s[N];
vector<int> b[350];

int query(int L, int R, int k) {
    int l = 0, r = n - 1;
    while(l <= r) {
        int m = l + r >> 1, x = s[m];
        int tl = L, tr = R, c = 0;

        //处理两端不在块内的
        while(tl <= tr && tl % B) if(a[tl++] <= x) ++c;
        while(tl <= tr && (tr + 1) % B) if(a[tr--] <= x) ++c;

        while(tl <= tr) {
            int cur = tl / B;
            c += upper_bound(b[cur].begin(), b[cur].end(), x) - b[cur].begin();
            tl += B;
        }

//      cout << x << " c: " << c << endl;
        if(c >= k) r = m - 1;
        else l = m + 1;
    }
    return l;
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d%d", &n, &q) == 2) {
        for(int i = 0; i < n / B; ++i) b[i].clear();
        for(int i = 0; i < n; ++i) {
            scanf("%d", a + i);
            s[i] = a[i];
            b[i / B].push_back(a[i]);
        }

        sort(s, s + n);
        for(int i = 0; i < n / B; ++i) sort(b[i].begin(), b[i].end());

        while(q--) {
            int l, r, k; scanf("%d%d%d", &l, &r, &k);
            int ans = query(l - 1, r - 1, k);
            printf("%d\n", s[ans]);
        }
    }
    return 0;
}
