//
//  Created by TaoSama on 2015-08-07
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
const int N = 1 << 11, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, m, a[130];
int kase, vis[N][N], dp[N][N], cnt[N][N];

void init() {
    for(int s = 0; s < 1 << n; ++s) {
        for(int a = s; a; a = (a - 1) & s)
            cnt[s][a] = 0;
        cnt[s][0] = 0;
    }

    for(int i = 1; i <= m; ++i) {
        for(int s = 0; s < 1 << n; ++s)
            cnt[s][s & a[i]]++;
    }
}

// s: the set of features we already asked
// a: subset of s that the object has
int dfs(int s, int a) {
    if(cnt[s][a] <= 1) return 0;
    if(cnt[s][a] == 2) return 1;

    int &ret = dp[s][a];
    if(vis[s][a] == kase) return ret;
    vis[s][a] = kase;

    ret = m;
    for(int k = 0; k < n; ++k) {
        if(s >> k & 1) continue;
        int s2 = s | 1 << k, a2 = a | 1 << k;
        //still can guess
        if(cnt[s2][a2] >= 1 && cnt[s2][a] >= 1) {
            int need = max(dfs(s2, a2), dfs(s2, a)) + 1;
            ret = min(ret, need);
        }
    }
    return ret;
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d%d", &n, &m) == 2 && (n || m)) {
        memset(a, 0, sizeof a);
        for(int i = 1; i <= m; ++i) {
            char buf[15]; scanf("%s", buf + 1);
            for(int j = 1; j <= n; ++j)
                a[i] = a[i] * 2 + buf[j] - '0';
        }

        ++kase;
        init();
        printf("%d\n", dfs(0, 0));
    }
    return 0;
}
