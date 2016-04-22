//
//  Created by TaoSama on 2016-01-25
//  Copyright (c) 2015 TaoSama. All rights reserved.
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
const int N = 5e4 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;
const int B = 250;

typedef long long LL;

int n, q;
int c[N], cnt[N];
LL sum, up[N], dw[N];

struct Query {
    int l, r, id;
    bool operator< (const Query& q) const {
        return r < q.r;
    }
};

void update(int i, int delta) {
    sum -= cnt[c[i]] * cnt[c[i]];
    cnt[c[i]] += delta;
    sum += cnt[c[i]] * cnt[c[i]];
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d%d", &n, &q) == 2) {
        for(int i = 1; i <= n; ++i) scanf("%d", c + i);
        memset(cnt, 0, sizeof cnt);

        vector<vector<Query> > Q(n / B + 2, vector<Query>());
        for(int i = 1; i <= q; ++i) {
            int l, r; scanf("%d%d", &l, &r);
            Q[l / B].push_back(Query {l, ++r, i});
        }
        for(int i = 0; i <= n / B; ++i) sort(Q[i].begin(), Q[i].end());

        sum = 0;
        for(int i = 0; i < Q.size(); ++i) {
            int l, r; l = r = i * B;
            for(int j = 0; j < Q[i].size(); ++j) {
                Query &q = Q[i][j];
                while(r < q.r) update(r++, 1);
                while(l < q.l) update(l++, -1);
                while(l > q.l) update(--l, 1);

                up[q.id] = sum - r + l;
                dw[q.id] = 1LL * (r - l) * (r - l - 1);
                LL g = __gcd(up[q.id], dw[q.id]);
                up[q.id] /= g;
                dw[q.id] /= g;
            }
            for(int j = l; j < r; ++j) update(j, -1);
        }
        for(int i = 1; i <= q; ++i) printf("%lld/%lld\n", up[i], dw[i]);
    }
    return 0;
}
