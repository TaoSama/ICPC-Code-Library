//
//  Created by TaoSama on 2016-07-30
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

typedef long long LL;
int n;
LL k[4], t[4], c[N];
LL ans[N];
priority_queue<LL, vector<LL>, greater<LL> > pq[4];

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    for(int i = 1; i <= 3; ++i) cin >> k[i];
    for(int i = 1; i <= 3; ++i) cin >> t[i];
    cin >> n;
    for(int i = 1; i <= n; ++i) cin >> c[i];

    for(int i = 1; i <= 3; ++i) {
        k[i] = min(k[i], (LL)n);
        while(k[i]--) pq[i].push(0);
    }
    for(int i = 1; i <= n; ++i) {
        for(int type = 1; type <= 3; ++type) {
            LL top = pq[type].top(); pq[type].pop();
            ans[i] += max(0LL, top - c[i]) + t[type];
//          pr(i); pr(type); prln(ans[i]);
            c[i] = top = max(top, c[i]) + t[type];
            pq[type].push(top);
        }
    }
    LL maxv = *max_element(ans + 1, ans + 1 + n);
    cout << maxv << endl;

    return 0;
}
