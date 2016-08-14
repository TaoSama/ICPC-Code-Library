//
//  Created by TaoSama on 2016-08-04
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
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

typedef long long LL;
int n, k, c[N];
bool vis[N];

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    while(scanf("%d%d", &n, &k) == 2) {
        for(int i = 1; i <= n; ++i) scanf("%d", c + i);

        memset(vis, 0, sizeof vis);
        for(int i = 1; i <= k; ++i) {
            int x; scanf("%d", &x);
            vis[x] = true;
        }

        LL ans = 0, sumVis = 0, sum = 0;
        for(int i = 1; i <= n; ++i) {
            int pre = i == 1 ? n : i - 1;
            int nxt = i == n ? 1 : i + 1;
            if(vis[i]) {
                ans += c[i] * sum;
                sumVis += c[i];
            } else {
                LL tmp = sumVis;
                if(pre < i && !vis[pre]) tmp += c[pre];
                if(nxt < i && !vis[nxt]) tmp += c[nxt];
                ans += c[i] * tmp;
            }
            sum += c[i];
//            prln(ans);
        }
        printf("%I64d\n", ans);

    }

    return 0;
}
