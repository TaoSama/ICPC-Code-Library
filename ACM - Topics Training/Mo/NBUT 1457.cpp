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
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;
const int B = 400;
typedef long long LL;

int n, q, a[N];
int cnt[N];

struct Query {
    int l, r, id;
    bool operator<(const Query& q) const {
        return r < q.r;
    }
};

LL sum, ans[N];

LL cube(LL x) {
    return x * x * x;
}

void update(int i, int delta) {
    sum -= cube(cnt[a[i]]);
    cnt[a[i]] += delta;
    sum += cube(cnt[a[i]]);
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d", &n) == 1) {
        vector<int> xs;
        memset(cnt, 0, sizeof cnt);
        for(int i = 1; i <= n; ++i) {
            scanf("%d", a + i);
            xs.push_back(a[i]);
        }
        sort(xs.begin(), xs.end());
        xs.resize(unique(xs.begin(), xs.end()) - xs.begin());
        for(int i = 1; i <= n; ++i)
            a[i] = lower_bound(xs.begin(), xs.end(), a[i]) - xs.begin() + 1;

        scanf("%d", &q);
        vector<vector<Query> > Q(n / B + 2, vector<Query>());
        for(int i = 1; i <= q; ++i) {
            int l, r; scanf("%d%d", &l, &r);
            Q[l / B].push_back((Query) {l, ++r, i});
        }
        for(int i = 0; i < Q.size(); ++i) sort(Q[i].begin(), Q[i].end());

        sum = 0;
        for(int i = 0; i < Q.size(); ++i) {
            int l, r; l = r = i * B;
            for(int j = 0; j < Q[i].size(); ++j) {
                Query& q = Q[i][j];
                while(r < q.r) update(r++, 1);
                while(l < q.l) update(l++, -1);
                while(l > q.l) update(--l, 1);
                ans[q.id] = sum;
            }
            for(int j = l; j < r; ++j) update(j, -1);
        }
        for(int i = 1; i <= q; ++i) printf("%I64d\n", ans[i]);
    }
    return 0;
}
