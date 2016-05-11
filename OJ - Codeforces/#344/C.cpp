//
//  Created by TaoSama on 2016-03-04
//  Copyright (c) 2016 TaoSama. All rights reserved.
//
#pragma comment(linker, "/STACK:1024000000,1024000000")
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
const int N = 2e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, q, a[N];
int deq[N];

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d%d", &n, &q) == 2) {
        for(int i = 1; i <= n; ++i) scanf("%d", a + i);
        vector<pair<int, int> > Q;
        for(int i = 1; i <= q; ++i) {
            int t, r; scanf("%d%d", &t, &r);
            while(Q.size() && Q.back().second <= r) Q.pop_back();
            Q.push_back({t, r});
        }
        Q.push_back({ -1, 0});
        int l = 1, r = Q[0].second, f = r;
        sort(a + l, a + r + 1);
        for(int i = l; i <= r; ++i) deq[i] = a[i];
        for(int i = 1; i < Q.size(); ++i) {
            int cnt = Q[i - 1].second - Q[i].second;
            while(cnt--) {
                if(Q[i - 1].first == 1) a[f--] = deq[r--];
                else a[f--] = deq[l++];
            }
        }
        for(int i = 1; i <= n; ++i) printf("%d%c", a[i], " \n"[i == n]);
    }
    return 0;
}
