//  Created by TaoSama.
//  Copyright (c) 2017 TaoSama. All rights reserved.
//
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

typedef long long LL;
const int SZ = 1.5 * (1 << 19);
LL f[20][SZ], digit[20];
int trans7[1 << 7], trans12[1 << 12];

int get(int s7, int s12, int m7, int m12) {
    int idx = 0;
    idx = (idx * 233 + s7) % SZ;
    idx = (idx * 233 + s12) % SZ;
    idx = (idx * 233 + m7) % SZ;
    idx = (idx * 233 + m12) % SZ;
    return idx;
}

LL dfs(int i, int s7, int s12, int m7, int m12, bool first, bool e) {
    if(!i) return first;
    int idx = get(s7, s12, m7, m12); 
    if(!e && ~f[i][idx]) return f[i][idx];
    LL ret = 0;
    int to = e ? digit[i] : 9;
    for(int d = first; d <= to; ++d) {
        int nm7 = m7, nm12 = m12;
        int ns7 = s7, ns12 = s12;
        nm7 = (nm7 * 10 + d) % 7; 
        nm12 = (nm12 * 10 + d) % 12; 
        if(!first) {
            if(d) {
                if(nm7 == 0 || nm12 == 0) continue;
                ns7 |= 1 << nm7;
                ns12 |= 1 << nm12;
            }
        }
        else {
            if(nm7 == 0 || nm12 == 0) continue;
            if(ns7 >> nm7 & 1) continue;
            if(ns12 >> nm12 & 1) continue;
            ns7 |= 1 << nm7;
            ns12 |= 1 << nm12;
        }
        ret += dfs(i - 1, trans7[ns7], trans12[ns12], nm7, nm12, first || d, e && d == to);
    }
    return e ? ret : f[i][idx] = ret; 
}

LL calc(LL x) {
    int cnt = 0;
    for(; x; x /= 10) digit[++cnt] = x % 10;
    return dfs(cnt, 0, 0, 0, 0, false, true);
}

int ans[N];

int brute(int n) {
    for(int i = 1; i <= n; ++i) {
        char buf[100]; sprintf(buf, "%d", i);
        ans[i] = ans[i - 1];
        bool ok = true;
        for(int j = 0; buf[j] && ok; ++j) {
            int cur7 = 0, cur12 = 0;
            for(int k = j; buf[k] && ok; ++k) {
                cur7 = (cur7 * 10 + buf[k] - '0') % 7;
                cur12 = (cur12 * 10 + buf[k] - '0') % 12;
                ok &= cur7 && cur12;
            }
        }
        ans[i] += ok;
    }
}

int main(){
#ifdef LOCAL
    freopen("/Users/didi/ACM/in.txt", "r", stdin);
//  freopen("/Users/didi/ACM/out.txt", "w", stdout);
#endif
    ios::sync_with_stdio(0); cin.tie(0);
    
    memset(f, -1, sizeof f);
    for(int s = 0; s < 1 << 7; ++s) {
        int ns = 0;
        for(int i = 0; i < 7; ++i) {
            if(s >> i & 1) ns |= 1 << (i * 10 % 7);
        }
        trans7[s] = ns;
    }
    for(int s = 0; s < 1 << 12; ++s) {
        int ns = 0;
        for(int i = 0; i < 12; ++i) {
            if(s >> i & 1) ns |= 1 << (i * 10 % 12);
        }
        trans12[s] = ns;
    }

    brute(N - 1);
    for(int i = 1; i < N; ++i) {
        if(calc(i) != ans[i]) {
            printf("%d = %lld %d\n", i, calc(i), ans[i]);
            break;
        }
    }

    int t; scanf("%d", &t);
    while(t--) {
        LL n; scanf("%lld", &n);
        printf("%lld\n", calc(n));
    }
    return 0;
}
// 6 56
