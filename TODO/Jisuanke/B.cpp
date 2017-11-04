//
//  Created by TaoSama on 2017-06-10
//  Copyright (c) 2017 TaoSama. All rights reserved.
//
#pragma comment(linker, "/STACK:102400000,102400000")
#include <bits/stdc++.h>

using namespace std;
#define pr(x) cerr << #x << " = " << x << "  "
#define prln(x) cerr << #x << " = " << x << endl
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

typedef long long LL;
LL l, r;
int P, digit[100];
LL f[100][N];

const int C = N - 1;
bool notPrime[C];
int pc, g[C], p[C / 10], phi[C], mu[C];
vector<int> divisors[C];
void sieve() {
    mu[0] = 1;
    phi[1] = mu[1] = 1;
    for(int i = 2; i < C; ++i) {
        if(!notPrime[i]) {
            p[pc++] = g[i] = i;
            phi[i] = i - 1; mu[i] = -1;
        }
        for(int j = 0; j < pc && i * p[j] < C; ++j) {
            int tmp = i * p[j];
            notPrime[tmp] = g[tmp] = p[j];
            if(i % p[j]) {
                phi[tmp] = phi[i] * (p[j] - 1);
                mu[tmp] = -mu[i];
            } else {
                phi[tmp] = phi[i] * p[j];
                mu[tmp] = 0;
                break;
            }
        }
    }
    for(int i = 1; i < C; ++i) {
        if(mu[i] == 0) continue;
        for(int j = i; j < C; j += i) divisors[j].push_back(i);
    }
    for(int i = 0; i < N; ++i) divisors[N - 1].push_back(i);
}

LL dfs2(int i, int s, bool first, bool e) {
    if(!i) return 1;
    if(!e && ~f[i][s]) return f[i][s];
    LL ret = 0;
    int to = e ? digit[i] : P - 1;
    for(int j = !first; j < divisors[s].size(); ++j) {
        int d = divisors[s][j];
        if(d > to) break;
//    for(int d = !first; d <= to; ++d) {
        int newS = s;
        if(first) {
            if(d) newS = d;
            else newS = N - 1;
        } else {
            newS = d;
//            if(__gcd(s, d) != 1) continue;
        }
        if(newS != N - 1) {
            for(int mpl = d; mpl < P; mpl += d)
                ret += mu[d] * dfs2(i - 1, mpl, 1, e && mpl == to);
        } else ret += 1 * dfs2(i - 1, newS, first && !d, e && d == to);
    }
    return e ? ret : f[i][s] = ret;
}
/*
3
6
41
10
8*/

LL calc2(LL x) {
    int cnt = 0;
    for(; x; x /= P) digit[++cnt] = x % P;
    memset(f, -1, sizeof f);
    return dfs2(cnt, N - 1, 1, 1);
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);


    sieve();
    int t; scanf("%d", &t);
    while(t--) {
        scanf("%lld%lld%d", &l, &r, &P);
        LL ans = 0;
        ans = calc2(r) - calc2(l - 1);
        printf("%lld\n", ans);
    }

    return 0;
}
