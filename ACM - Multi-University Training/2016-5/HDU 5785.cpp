//
//  Created by TaoSama on 2016-08-02
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
const int N = 1e6 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

struct PalindromicTree {
    static const int M = 1e6 + 10, S = 26;
    int n, sz, last;
    int nxt[M][S], fail[M], len[M];
    char s[M];
    int cnt[M], sum[M];
    int newnode(int l) {
        len[sz] = l;
        sum[sz] = cnt[sz] = 0;
        memset(nxt[sz], 0, sizeof(nxt[sz]));
        return sz++;
    }
    void init() {
        sz = last = 0;
        newnode(0); newnode(-1);
        s[n = 0] = -1;
        fail[0] = 1;
    }
    int getfail(int u) {
        while(s[n - len[u] - 1] != s[n]) u = fail[u];
        return u;
    }
    pair<int, int> add(int c) {
        s[++n] = c;
        int u = getfail(last);
        int& v = nxt[u][c];
        if(!v) {
            int cur = newnode(len[u] + 2);
            fail[cur] = nxt[getfail(fail[u])][c];
            v = cur;
//            pr(len[fail[v]]); prln(len[v]);
            cnt[v] = cnt[fail[v]] + 1;
            sum[v] = sum[fail[v]] + len[v];
            if(sum[v] >= MOD) sum[v] -= MOD;
//            prln(sum[v]);
        }
        last = v;
        return {cnt[v], sum[v]};
    }
} pt;

int n;
char s[N];
int preCnt[N], preSum[N];

typedef long long LL;
LL mul(LL x, LL y) {
    return x * y % MOD;
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%s", s + 1) == 1) {
        n = strlen(s + 1);
        pt.init();
        for(int i = 1; i <= n; ++i) {
            auto ret = pt.add(s[i] - 'a');
            tie(preCnt[i], preSum[i]) = ret;
        }

        pt.init();
        LL ans = 0;
        for(int i = n; i > 1; --i) {
            auto ret = pt.add(s[i] - 'a');
            int sufCnt, sufSum;
            tie(sufCnt, sufSum) = ret;
//            prln(i);
//            printf("%d %d %d %d\n", preCnt[i - 1], preSum[i - 1], sufCnt, sufSum);

            LL sqI = mul(mul(mul(i, i), preCnt[i - 1]), sufCnt);
            LL mid = mul(preCnt[i - 1], sufSum - sufCnt) -
                     mul(sufCnt, preSum[i - 1]);
            mid %= MOD;
            mid = mul(mid, i);
            LL rht = mul(sufSum - sufCnt, preSum[i - 1]);
            ans += sqI + mid - rht;
            ans %= MOD;
//            prln(ans);
        }
        ans = (ans + MOD) % MOD;
        printf("%I64d\n", ans);
    }

    return 0;
}
