//
//  Created by TaoSama on 2015-10-04
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
#define pr(x) cout << #x << " = " << x << "  "
#define prln(x) cout << #x << " = " << x << endl
const int N = 1e4 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;
const int S = 1 << 10;

int n, k, q;
int sco[N], s[N], r[N];
vector<int> dat[S][S];

bool cmp(int x, int y) {
    return sco[x] < sco[y];
}

void gao() {
    for(int i = 1; i <= n; ++i) r[i] = i;
    sort(r + 1, r + 1 + n, cmp);

    for(int mask = 0; mask < 1 << k; ++mask) {
        for(int i = 0; i < 1 << k; ++i) dat[mask][i].clear();
        for(int i = 1; i <= n; ++i) {
            int id = r[i];
            int cur = mask & s[id];
            dat[mask][cur].push_back(sco[id]);
        }
    }
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d%d", &n, &k) == 2) {
        for(int i = 1; i <= n; ++i) {
            int t; scanf("%d%d", sco + i, &t);
            s[i] = 0;
            while(t--) {
                int x; scanf("%d", &x);
                s[i] |= 1 << x - 1;
            }
        }

        gao();

        scanf("%d", &q);
        while(q--) {
            int id, t; scanf("%d%d", &id, &t);
            int need = 0;
            while(t--) {
                int x; scanf("%d", &x);
                need |= 1 << x - 1;
            }
            int cur = need & s[id];
            vector<int> &v = dat[need][cur];
            int ans = v.size() - (upper_bound(v.begin(), v.end(), sco[id]) - v.begin());
            printf("%d\n", ans + 1);
        }
    }
    return 0;
}
