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

int n, q, k;
int pre[N], cnt[1 << 20];

struct Query {
    int l, r, id;
    bool operator<(const Query& q) const {
        return r < q.r;
    }
};

long long sum, ans[N];
void update(int i, int delta) {
    if(delta > 0) {
        sum += cnt[pre[i] ^ k];
        ++cnt[pre[i]];
    } else {
        --cnt[pre[i]];
        sum -= cnt[pre[i] ^ k];
    }
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d%d%d", &n, &q, &k) == 3) {
        for(int i = 1; i <= n; ++i) {
            scanf("%d", pre + i);
            pre[i] ^= pre[i - 1];
        }
        memset(cnt, 0, sizeof cnt);
        vector<vector<Query> > Q(n / B + 2, vector<Query>());
        for(int i = 1; i <= q; ++i) {
            int l, r; scanf("%d%d", &l, &r);
            Q[l / B].push_back(Query {--l, ++r, i});
        }
        for(auto &i : Q) sort(i.begin(), i.end());

        sum = 0;
        for(int i = 0; i < Q.size(); ++i) {
            int l, r; l = r = i * B;
            for(auto &q : Q[i]) {
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
