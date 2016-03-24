//
//  Created by TaoSama on 2015-10-07
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
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

typedef long long LL;

int n;
LL cnt[N], ans[N];
bool carry[N];

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
//  freopen("out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int t; scanf("%d", &t);
    int kase = 0;
    while(t--) {
        scanf("%d", &n);
        memset(cnt, 0, sizeof cnt);
        memset(ans, 0, sizeof ans);
        memset(carry, 0, sizeof carry);
        int Max = -1;
        for(int i = 1; i <= n; ++i) {
            int x, c; scanf("%d%d", &x, &c);
            Max = max(Max, x);
            cnt[x] += c;
        }
        for(int i = 0; i <= Max; ++i) {
            if(cnt[i] < 2) continue;
            cnt[i + 1] += cnt[i] / 2;
            cnt[i] %= 2;
            carry[i + 1] = true;
        }

        int idx = -1;
        for(int i = Max; ~i; --i) {
            if(cnt[i] == 1 && !carry[i]) {
                idx = i;
                break;
            }
        }

        printf("Case #%d: ", ++kase);
        if(idx == -1) {
            puts("0");
            continue;
        }

        ans[idx] = 0;
        ans[0] = 1;  //let 2^max = 1 + 11...111(max-1 in total)
        for(int i = idx - 1; ~i; --i)
            ans[i] += 1 - cnt[i];
        for(int i = 0; i < idx; ++i) {
            if(ans[i] < 2) continue;
            ans[i + 1] += ans[i] / 2;
            ans[i] %= 2;
        }
        for(int i = idx; i >= 0; --i) {
            if(ans[i] == 0) continue;
            for(; i >= 0; --i) printf("%lld", ans[i]);
            puts("");
        }
    }
    return 0;
}
