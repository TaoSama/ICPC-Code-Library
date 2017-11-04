//
//  Created by TaoSama on 2017-06-18
//  Copyright (c) 2017 TaoSama. All rights reserved.
//
#pragma comment(linker, "/STACK:102400000,102400000")
#include <bits/stdc++.h>

using namespace std;
#define pr(x) cerr << #x << " = " << x << "  "
#define prln(x) cerr << #x << " = " << x << endl
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int notPrime[N], mu[N];
vector<int> primes, divisors[N];
void gao() {
    mu[1] = 1;
    for(int i = 2; i < N; ++i) {
        if(!notPrime[i]) {
            mu[i] = -1;
            primes.push_back(i);
        }
        for(int j = 0; j < primes.size() && i * primes[j] < N; ++j) {
            int x = i * primes[j];
            notPrime[x] = true, mu[x] = -mu[i];
            if(i % primes[j] == 0) {mu[x] = 0; break;}
        }
    }
    for(int i = 1; i < N; ++i) {
        if(mu[i] == 0) continue;
        for(int j = i; j < N; j += i) divisors[j].push_back(i);
    }
}

int n, q, a[N];
int cntx[N], cntc[N], ans[N];

const int B = 225;
struct Query {
    int l, r, block, k, id;
};

bool cmpSeq(const Query& a, const Query& b) {
    return a.block < b.block ||
           a.block == b.block && a.r < b.r;
}

void add(int x) {
    for(int div : divisors[cntx[x]]) --cntc[div];
    ++cntx[x];
    for(int div : divisors[cntx[x]]) ++cntc[div];
}

void del(int x) {
    for(int div : divisors[cntx[x]]) --cntc[div];
    --cntx[x];
    for(int div : divisors[cntx[x]]) ++cntc[div];
}


int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    gao();

    scanf("%d%d", &n, &q);
    for(int i = 1; i <= n; ++i) scanf("%d", a + i);

    vector<Query> qs(q);
    for(int i = 1; i <= q; ++i) {
        int l, r, k; scanf("%d%d%d", &l, &r, &k);
        qs[i - 1] = {l, r, l / B, k, i};
    }

    sort(qs.begin(), qs.end(), cmpSeq);
    memset(cntx, 0, sizeof cntx);
    memset(cntc, 0, sizeof cntc);
    int l = 1, r = 0;
    for(auto& q : qs) {
        while(r < q.r) add(a[++r]);
        while(l < q.l) del(a[l++]);
        while(r > q.r) del(a[r--]);
        while(l > q.l) add(a[--l]);

        int k = q.k;
        int sum = 0;
//        printf("l = %d r = %d k = %d\n", q.l, q.r, q.k);
//        for(int i = 0; i <= 2; ++i) printf("cntc[%d]=%d\n", i, cntc[i]);
        for(int div : divisors[k]) sum += mu[div] * cntc[div];

        ans[q.id] = sum;
    }

    for(int i = 1; i <= q; ++i) printf("%d\n", ans[i]);

    return 0;
}
